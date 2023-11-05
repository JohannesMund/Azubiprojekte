#pragma once

#include "cequipment.h"

class CEnemy;
class CSword : public CEquipment
{
public:
    CSword();

    virtual void enhance() override;

    virtual void battleEffect(CEnemy* enemy) override;
    virtual void battleBuff(CEnemy* enemy, bool& endRound) override;
};
