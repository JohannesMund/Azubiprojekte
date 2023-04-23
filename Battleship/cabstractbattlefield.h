#pragma once

#include "battlefieldcoords.h"
#include "cbattlefieldbutton.h"
#include "cbattlefieldgrid.h"
#include <QFrame>

class CAbstractBattleFieldLabel;

class CShipsAtCoords;
class CAbstractBattleField : public QFrame
{

public:
    auto begin()
    {
        return _grid.begin();
    }

    auto end()
    {
        return _grid.end();
    }

    CAbstractBattleField(QWidget* parent = nullptr);
    void setLabel(CAbstractBattleFieldLabel* label);

    bool hasShipAround(const BattleFieldCoords::BattleFieldCoords coords,
                       std::function<bool(const BattleFieldCoords::BattleFieldCoords coords)> f) const;
    bool hasShipAround(const BattleFieldCoords::BattleFieldCoords coords) const;

    bool isInRange(const BattleFieldCoords::BattleFieldCoords coords) const;

    bool checkForWin() const;

    CBattleFieldButton* at(const BattleFieldCoords::BattleFieldCoords coords) const;

protected:
    CBattleFieldGrid<CBattleFieldButton*> _grid;

    void init();

    virtual void placeBattleShips() = 0;
    virtual void startGame() = 0;
    virtual void buttonToggled(const bool toggleState, const BattleFieldCoords::BattleFieldCoords coords) = 0;
    virtual void shipHit(const BattleFieldCoords::BattleFieldCoords coords) = 0;

    void clearGrid();

    void enableAll(const bool bEnable);
    void revealAll();

    CAbstractBattleFieldLabel* _label;
};
