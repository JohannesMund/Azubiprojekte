#pragma once

#include "cabstractbattlefieldlabel.h"

class CComputerBattleFieldLabel : public CAbstractBattleFieldLabel
{
public:
    CComputerBattleFieldLabel(QWidget* parent = nullptr);

private:
    virtual QString updateHitArea(const int shipId) override;
};
