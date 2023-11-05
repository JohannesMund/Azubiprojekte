#ifndef CARMOR_H
#define CARMOR_H

#include "cequipment.h"

class CArmor : public CEquipment
{
public:
    CArmor();

    virtual void battleEffect(CEnemy* enemy) override = 0;
    virtual int shield(const unsigned int i) override = 0;

    /**
     * @brief armorFilter
     * @return a filter function to filter armor items from std containers
     */
    static std::function<bool(const CItem*)> armorFilter();
};

#endif // CARMOR_H
