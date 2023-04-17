#pragma once

#include "cabstractbattlefield.h"

class CComputerBattleField : public CAbstractBattleField
{
public:
    CComputerBattleField(QWidget* parent);

private:
    virtual void placeBattleShips() override;
    virtual void startGame() override;
    virtual void buttonToggled(const bool toggleState, const BattleFieldCoords::BattleFieldCoords coords) override;
    virtual void shipHit(const BattleFieldCoords::BattleFieldCoords coords) override;

    void autoPlaceBattleShips();
    void autoPlaceBattleShip(const int size, const int shipId);

    bool autoPlaceBattleShipRecursion(BattleFieldCoords::BattleFieldCoords coords,
                                      const int size,
                                      const BattleFieldCoords::EDirections dir,
                                      const int shipId);
};
