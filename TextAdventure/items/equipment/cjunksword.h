#pragma once
#include <csword.h>

class CJunkSword : public CSword
{
public:
    CJunkSword();

    virtual void battleEffect(CEnemy* enemy) override;
    virtual void battleBuff(CEnemy* enemy, bool& endRound) override;
};
