#pragma once

#include "battlefieldcoords.h"
#include "cplayerplacement.h"

class CShipsAtCoords;
class CPlayerBattleField : public CAbstractBattleField
{
public:
    CPlayerBattleField(QWidget* parent = nullptr);

private:
    virtual void placeBattleShips() override;

    void unsetButtons(const CShipsAtCoords& coords);

    virtual void startGame() override;
    virtual void buttonToggled(const bool toggleState, const BattleFieldCoords::BattleFieldCoords coords) override;
    virtual void shipHit(const BattleFieldCoords::BattleFieldCoords coords) override;

    bool isMoveValid(const BattleFieldCoords::BattleFieldCoords coords) const;

    CPlayerPlacement _placementHelper;
};
