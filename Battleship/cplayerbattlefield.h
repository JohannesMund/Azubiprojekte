#pragma once

#include "cabstractbattlefield.h"
#include "cplayerplacement.h"

class CPlayerBattleField : public CAbstractBattleField
{
public:
    CPlayerBattleField(QWidget* parent = nullptr);

private:
    virtual void placeBattleShips() override;

    void unsetButtons(const std::vector<BattleFieldCoords> coords);

    virtual void startGame() override;
    virtual void buttonToggled(const bool toggleState, const BattleFieldCoords coords) override;
    virtual void shipHit(const BattleFieldCoords coords) override;

    bool isMoveValid(const BattleFieldCoords coords) const;

    CPlayerPlacement _placementHelper;
};
