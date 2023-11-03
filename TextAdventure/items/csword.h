#pragma once

#include "cenhancableitem.h"

class CEnemy;
class CSword : public CEnhancableItem
{
public:
    CSword();

    virtual void enhance() override;

    virtual void battleEffect(CEnemy* enemy) override;
    virtual void battleBuff(CEnemy* enemy, bool& endRound) override;
};