#pragma once
#include "cenemy.h"

class CLivingChest : public CEnemy
{
public:
    CLivingChest();

    virtual void spoilsOfWar() override;
    virtual void battleAction(bool& endRound) override;
};
