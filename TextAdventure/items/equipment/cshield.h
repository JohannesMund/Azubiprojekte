#pragma once
#include "cequipment.h"

class CEnemy;
class CShield : public CEquipment
{
public:
    CShield();

    virtual void battleEffect(CEnemy* enemy) override = 0;
    virtual void battleBuff(CEnemy* enemy, bool& endRound) override = 0;

    /**
     * @brief shieldFilter
     * @return a filter function to filter shield items from std containers
     */
    static std::function<bool(const CItem*)> shieldFilter();
};
