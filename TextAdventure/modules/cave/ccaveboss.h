#pragma once

#include <cenemy.h>

class CCaveBoss : public CEnemy
{
public:
    CCaveBoss();

    virtual void spoilsOfWar() override;
    virtual void battleAction(bool& endRound) override;
};
