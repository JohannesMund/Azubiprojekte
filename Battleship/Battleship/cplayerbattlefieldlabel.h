#pragma once

#include "cabstractbattlefieldlabel.h"

/**
 * @brief The CPlayerBattleFieldLabel class
 * Das BattlefieldLabel für den Spieler.
 */

class CPlayerBattleFieldLabel : public CAbstractBattleFieldLabel
{
public:
    CPlayerBattleFieldLabel(QWidget* parent = nullptr);

private:
    virtual QString updateHitArea(const int shipId) override;
};
