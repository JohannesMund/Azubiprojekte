#include "ccomputerbattlefield.h"
#include "cabstractbattlefieldlabel.h"
#include "cbattlefieldbutton.h"
#include "cgamemanagement.h"

#include <QApplication>

#include <algorithm>
#include <random>

CComputerBattleField::CComputerBattleField(QWidget* parent) : CAbstractBattleField(parent)
{
    connect(CGameManagement::getInstance(), &CGameManagement::playerTurn, this, [this]() { enableAll(true); });
    connect(CGameManagement::getInstance(), &CGameManagement::playerTurn, this, [this]() { enableAll(false); });
}

void CComputerBattleField::placeBattleShips()
{
    autoPlaceBattleShips();
    enableAll(false);
}

void CComputerBattleField::startGame()
{
    enableAll(true);
}

void CComputerBattleField::buttonToggled(const bool, const BattleFieldCoords coords)
{
    if (!isInRange(coords))
        return;

    auto button = get(coords);
    button->setEnabled(false);
    if (button->hasShip())
    {
        button->reveal(true);
        _label->hit(button->getShipId());
    }
    else
    {
        CGameManagement::getInstance()->playerFinished();
    }
}

void CComputerBattleField::shipHit(const BattleFieldCoords coords)
{
}
void CComputerBattleField::autoPlaceBattleShips()
{
    std::srand(std::time(nullptr));
    auto ships = CGameManagement::getInstance()->getAvailableShips();
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        autoPlaceBattleShip(CGameManagement::getSizeOfShip(ships.at(i)), i);
    }
}

void CComputerBattleField::autoPlaceBattleShip(const int size, const int shipId)
{
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine{seed};

    while (true)
    {
        qApp->processEvents();
        unsigned int x = std::rand() / ((RAND_MAX + 1u) / _grid.at(0).size());
        unsigned int y = std::rand() / ((RAND_MAX + 1u) / _grid.size());

        std::vector<EDirections> directions = {EDirections::eHorizontal, EDirections::eVertical};

        std::shuffle(std::begin(directions), std::end(directions), rng);

        for (auto dir : directions)
        {
            if (autoPlaceBattleShipRecursion({x, y}, size, dir, shipId))
            {
                return;
            }
        }
    }
}

bool CComputerBattleField::autoPlaceBattleShipRecursion(BattleFieldCoords coords,
                                                        const int size,
                                                        const EDirections dir,
                                                        const int shipId)
{
    if (!isInRange(coords))
    {
        return false;
    }

    if (hasShipAround(coords))
    {
        return false;
    }

    if (size == 0)
    {
        get(coords)->setHasShip(shipId, false);
        return true;
    }

    if (dir == EDirections::eVertical)
    {
        coords.y++;
    }
    else
    {
        coords.x++;
    }

    if (autoPlaceBattleShipRecursion(coords, size - 1, dir, shipId))
    {
        get(coords)->setHasShip(shipId, false);
        return true;
    }
    return false;
}
