#include "ccomputerplayer.h"
#include "cabstractbattlefield.h"
#include "cbattlefieldbutton.h"
#include "cgamemanagement.h"

#include <algorithm>
#include <random>

CComputerPlayer::CComputerPlayer(CAbstractBattleField* battleField, QObject* parent) :
    QObject(parent),
    _battleField(battleField)
{
    connect(CGameManagement::getInstance(), &CGameManagement::computerTurn, this, &CComputerPlayer::doMove);
}

void CComputerPlayer::doMove()
{
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine{seed};

    auto coords = getAvailableFields();
    std::shuffle(coords.begin(), coords.end(), rng);

    auto button = _battleField->get(coords.at(0));

    button->reveal(true);
    if (button->hasShip())
    {
        doMove();
    }
}

std::vector<CAbstractBattleField::BattleFieldCoords> CComputerPlayer::getAvailableFields()
{
    auto size = CGameManagement::getInstance()->getGridSize();
    std::vector<CAbstractBattleField::BattleFieldCoords> coordList;
    for (int i = 0; i < size.height(); i++)
    {

        for (int j = 0; j < size.width(); j++)
        {
            const CAbstractBattleField::BattleFieldCoords coords = {(unsigned)i, (unsigned)j};

            if (!_battleField->get(coords)->isRevealed())
            {
                coordList.push_back(coords);
            }
        }
    }
    return coordList;
}
