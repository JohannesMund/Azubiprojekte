#include "ccomputerplayer.h"
#include "battlefieldcoords.h"
#include "cabstractbattlefield.h"
#include "cbattlefieldbutton.h"
#include "cbattlefieldgriditerator.h"
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

    auto button = _battleField->at(coords);

    button->reveal(true);
    if (button->hasShip())
    {
        hit(CShipAtCoords(coords, button->getShipId()));
        doMove();
    }
}

void CComputerPlayer::hit(const CShipAtCoords& s)
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

    if (_battleField->checkForWin())
    {
        CGameManagement::getInstance()->computerWins();
    }
}

BattleFieldCoords::BattleFieldCoords CComputerPlayer::doMoveEasy() const
{
    return justSomeRandomMove();
}

BattleFieldCoords::BattleFieldCoords CComputerPlayer::doMoveMedium() const
{
    auto coords = findNextHit();
    if (coords.has_value())
    {
        return coords.value();
    }
    return justSomeRandomMove();
}

BattleFieldCoords::BattleFieldCoords CComputerPlayer::doMoveHard() const
{
    auto coords = findNextHit();
    if (coords.has_value())
    {
        return coords.value();
    }

    coords = strategicMove();
    if (coords.has_value())
    {
        return coords.value();
    }

    return justSomeRandomMove();
}

std::optional<BattleFieldCoords::BattleFieldCoords> CComputerPlayer::strategicMove() const
{
    for (auto it = _battleField->begin(); it != _battleField->end(); it++)
    {
        if (it.x() % 3 && it.y() % 3)
        {
            if (!(*it)->isRevealed())
            {
                return BattleFieldCoords::BattleFieldCoords({(unsigned int)it.x(), (unsigned int)it.y()});
            }
        }
    }

    return {};
}

BattleFieldCoords::BattleFieldCoords CComputerPlayer::justSomeRandomMove() const
{
    auto coords = getAvailableFields();
    Randomizer::initRand();
    Randomizer::shuffle(coords);
    return coords.at(0);
}

std::optional<BattleFieldCoords::BattleFieldCoords> CComputerPlayer::findNextHit() const
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

std::vector<BattleFieldCoords::BattleFieldCoords> CComputerPlayer::getAvailableFields() const
{
    std::vector<BattleFieldCoords::BattleFieldCoords> coordList;
    for (auto it = _battleField->begin(); it != _battleField->end(); it++)
    {
        if (!(*it)->isRevealed())
        {
            coordList.push_back({(unsigned int)it.x(), (unsigned int)it.y()});
        }
    }
    return coordList;
}

bool CComputerPlayer::isValidMove(const CShipAtCoords& s) const
{
    if (!_battleField->isInRange(s.getCoords()))
    {
        return false;
    }
    if (_battleField->at(s.getCoords())->isRevealed())
    {
        return false;
    }

    auto fnOtherRevealedShipAround = [this, s](const auto b)
    { return (b->isRevealed() && b->hasShip() && ((unsigned)b->getShipId() != s.getShipId())); };

    if (_battleField->hasShipAround_if(s.getCoords(), fnOtherRevealedShipAround))
    {
        return false;
    }

    return true;
}

CShipVector::const_iterator CComputerPlayer::getMinOrMax(const bool isMin,
                                                         const BattleFieldCoords::EDirections dir,
                                                         const CShipVector& filtered) const
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
    const bool isMin, const BattleFieldCoords::EDirections dir, const CShipVector& filtered) const
{
    const auto it = getMinOrMax(isMin, dir, filtered);

    if (it == filtered.end())
    {
        return {};
    }

    CShipAtCoords s = *it;
    s.transposeCoords(dir, isMin);

    if (isValidMove(s))
    {
        return s.getCoords();
    }

    return {};
}
