#pragma once

#include "cequipment.h"

class CEnemy;
class CSword : public CEquipment
{
public:
    CSword();
    virtual ~CSword()
    {
    }

    virtual void battleEffect(CEnemy* enemy) override = 0;
    virtual void battleBuff(CEnemy* enemy, bool& endRound) override = 0;

    /**
     * @brief swordFilter
     * @return a filter function to filter sword items from std containers
     */
    static std::function<bool(const CItem*)> swordFilter();
};
