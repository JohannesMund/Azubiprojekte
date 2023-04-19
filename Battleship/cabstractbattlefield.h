#pragma once

#include "battlefieldcoords.h"

#include <QFrame>

class CAbstractBattleFieldLabel;
class CBattleFieldButton;
class CShipsAtCoords;
class CAbstractBattleField : public QFrame
{

public:
    CAbstractBattleField(QWidget* parent = nullptr);
    void setLabel(CAbstractBattleFieldLabel* label);

    bool hasShipAround(const BattleFieldCoords::BattleFieldCoords coords,
                       std::function<bool(const BattleFieldCoords::BattleFieldCoords coords)> f) const;
    bool hasShipAround(const BattleFieldCoords::BattleFieldCoords coords) const;

    bool isInRange(const BattleFieldCoords::BattleFieldCoords coords) const;

    CBattleFieldButton* get(const BattleFieldCoords::BattleFieldCoords coords) const;

protected:
    std::vector<std::vector<CBattleFieldButton*>> _grid;

    void init();

    virtual void placeBattleShips() = 0;
    virtual void startGame() = 0;
    virtual void buttonToggled(const bool toggleState, const BattleFieldCoords::BattleFieldCoords coords) = 0;
    virtual void shipHit(const BattleFieldCoords::BattleFieldCoords coords) = 0;

    void clearGrid();

    void enableAll(const bool bEnable);

    CAbstractBattleFieldLabel* _label;
};
