#pragma once

#include "cenemy.h"

class CBountyEnemy : public CEnemy
{
public:
    CBountyEnemy(const std::string& name);

    virtual void spoilsOfWar() override;
    virtual void battleAction(bool& endRound) override;
};
