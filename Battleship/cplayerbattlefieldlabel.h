#pragma once

#include "cabstractbattlefieldlabel.h"

class CPlayerBattleFieldLabel : public CAbstractBattleFieldLabel
{
public:
    CPlayerBattleFieldLabel(QWidget* parent = nullptr);

private:
    virtual QString updateHitArea(const int shipId) override;
};
