#pragma once

#include <cenemy.h>

class CMobEnemy : public CEnemy
{
public:
    CMobEnemy();

    virtual void battleAction(bool& endRound) override;

private:
    void specialAttack();

    unsigned int _specialAttackChance = 0;
};
