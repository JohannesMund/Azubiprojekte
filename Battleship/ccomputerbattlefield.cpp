#include "ccomputerbattlefield.h"
#include "randomizer.h"
#include "cabstractbattlefieldlabel.h"
#include "cbattlefieldbutton.h"
#include "cgamemanagement.h"

#include <QApplication>

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

void CComputerBattleField::buttonToggled(const bool, const BattleFieldCoords::BattleFieldCoords coords)
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

void CComputerBattleField::shipHit(const BattleFieldCoords::BattleFieldCoords)
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
    while (true)
    {
        qApp->processEvents();
        unsigned int x = std::rand() / ((RAND_MAX + 1u) / _grid.at(0).size());
        unsigned int y = std::rand() / ((RAND_MAX + 1u) / _grid.size());

        std::vector<BattleFieldCoords::EDirections> directions = {BattleFieldCoords::EDirections::eHorizontal,
                                                                  BattleFieldCoords::EDirections::eVertical};
        Randomizer::shuffle(directions);

        for (auto dir : directions)
        {
            if (autoPlaceBattleShipRecursion({x, y}, size, dir, shipId))
            {
                return;
            }
        }
    }
}

bool CComputerBattleField::autoPlaceBattleShipRecursion(BattleFieldCoords::BattleFieldCoords coords,
                                                        const int size,
                                                        const BattleFieldCoords::EDirections dir,
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

    if (dir == BattleFieldCoords::EDirections::eVertical)
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
