#pragma once

#include "cabstractbattlefieldlabel.h"

/**
 * @brief The CComputerBattleFieldLabel class
 * Das BattlefieldLabel für den Comuterspieler.
 */

class CComputerBattleFieldLabel : public CAbstractBattleFieldLabel
{
public:
    CComputerBattleFieldLabel(QWidget* parent = nullptr);

private:
    virtual QString updateHitArea(const int shipId) override;
};
