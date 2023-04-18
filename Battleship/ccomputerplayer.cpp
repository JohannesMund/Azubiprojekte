#include "ccomputerplayer.h"
#include "battlefieldcoords.h"
#include "cabstractbattlefield.h"
#include "cbattlefieldbutton.h"
#include "cgamemanagement.h"
#include "randomizer.h"

CComputerPlayer::CComputerPlayer(CAbstractBattleField* battleField, QObject* parent) :
    QObject(parent),
    _battleField(battleField)
{
    connect(CGameManagement::getInstance(), &CGameManagement::computerTurn, this, &CComputerPlayer::doMove);
}

void CComputerPlayer::doMove()
{
    BattleFieldCoords::BattleFieldCoords coords;
    switch (CGameManagement::getInstance()->getDifficulty())
    {
    case CGameManagement::EDifficulty::eEasy:
        coords = doMoveEasy();
        break;
    case CGameManagement::EDifficulty::eMedium:
    default:
        coords = doMoveMedium();
        break;
    case CGameManagement::EDifficulty::eHard:
        coords = doMoveHard();
        break;
    }

    auto button = _battleField->get(coords);

    button->reveal(true);
    if (button->hasShip())
    {
        hit({coords, (unsigned)button->getShipId()});
        doMove();
    }
}

BattleFieldCoords::BattleFieldCoords CComputerPlayer::doMoveEasy()
{
    return justSomeRandomMove();
}

BattleFieldCoords::BattleFieldCoords CComputerPlayer::doMoveMedium()
{
    auto coords = findNextHit();
    if (coords.has_value())
    {
        return coords.value();
    }

    return justSomeRandomMove();
}

BattleFieldCoords::BattleFieldCoords CComputerPlayer::doMoveHard()
{
    return justSomeRandomMove();
}

BattleFieldCoords::BattleFieldCoords CComputerPlayer::justSomeRandomMove()
{
    auto coords = getAvailableFields();
    Randomizer::shuffle(coords);
    return coords.at(0);
}

void CComputerPlayer::hit(const CShipAtCoords s)
{
    auto hits = std::count_if(_hits.begin(), _hits.end(), CShipAtCoords::shipIdFilter(s.getShipId()));
    hits++;

    const auto hitpoints =
        CGameManagement::getSizeOfShip(CGameManagement::getInstance()->getAvailableShips().at(s.getShipId()));

    if (hits >= hitpoints)
    {
        _sunkShips.push_back(s.getShipId());
        _hits.erase(std::remove_if(_hits.begin(), _hits.end(), CShipAtCoords::shipIdFilter(s.getShipId())),
                    _hits.end());
    }
    else
    {
        _hits.push_back(s);
    }
}

std::optional<BattleFieldCoords::BattleFieldCoords> CComputerPlayer::findNextHit()
{
    if (_hits.empty())
    {
        return {};
    }

    auto filtered = _hits.filter(CShipAtCoords::shipIdFilter(_hits.at(0).getShipId()));

    if (filtered.empty())
    {
        return {};
    }

    if (filtered.isHorizontalLine())
    {
        auto sMin = appendToMinOrMax(true, BattleFieldCoords::EDirections::eHorizontal, filtered);
        if (sMin.has_value())
            return sMin.value();

        auto sMax = appendToMinOrMax(false, BattleFieldCoords::EDirections::eHorizontal, filtered);
        if (sMax.has_value())
            return sMax.value();
    }

    if (filtered.isVerticalLine())
    {
        auto sMin = appendToMinOrMax(true, BattleFieldCoords::EDirections::eVertical, filtered);
        if (sMin.has_value())
            return sMin.value();

        auto sMax = appendToMinOrMax(false, BattleFieldCoords::EDirections::eVertical, filtered);
        if (sMax.has_value())
            return sMax.value();
    }

    return {};
}

std::vector<BattleFieldCoords::BattleFieldCoords> CComputerPlayer::getAvailableFields()
{
    auto size = CGameManagement::getInstance()->getGridSize();
    std::vector<BattleFieldCoords::BattleFieldCoords> coordList;
    for (int i = 0; i < size.width(); i++)
    {

        for (int j = 0; j < size.height(); j++)
        {
            const BattleFieldCoords::BattleFieldCoords coords = {(unsigned)i, (unsigned)j};

            if (!_battleField->get(coords)->isRevealed())
            {
                coordList.push_back(coords);
            }
        }
    }
    return coordList;
}

bool CComputerPlayer::isValidField(const CShipAtCoords s) const
{
    if (!_battleField->isInRange(s.getCoords()))
    {
        return false;
    }
    if (_battleField->get(s.getCoords())->isRevealed())
    {
        return false;
    }

    if (_battleField->hasShipAround(s.getCoords(),
                                    [this, s](const auto coords)
                                    {
                                        auto b = _battleField->get(coords);
                                        return (b->hasShip() && ((unsigned)b->getShipId() != s.getShipId()));
                                    }))
    {
        return false;
    }

    return true;
}

CShipsAtCoords::const_iterator CComputerPlayer::getMinOrMax(const bool isMin,
                                                            const BattleFieldCoords::EDirections dir,
                                                            const CShipsAtCoords& filtered) const
{
    if (isMin)
    {
        return std::min_element(filtered.begin(), filtered.end(), CShipAtCoords::battleFieldCoordLT(dir));
    }
    else
    {
        return std::max_element(filtered.begin(), filtered.end(), CShipAtCoords::battleFieldCoordLT(dir));
    }
}

std::optional<BattleFieldCoords::BattleFieldCoords> CComputerPlayer::appendToMinOrMax(
    const bool isMin, const BattleFieldCoords::EDirections dir, const CShipsAtCoords& filtered) const
{
    const auto it = getMinOrMax(isMin, dir, filtered);

    if (it == filtered.end())
    {
        return {};
    }

    CShipAtCoords s = *it;
    s.transposeCoords(dir, isMin);

    if (isValidField(s))
    {
        return s.getCoords();
    }

    return {};
}
