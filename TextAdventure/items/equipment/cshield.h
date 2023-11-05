#pragma once
#include "cequipment.h"

class CEnemy;
class CShield : public CEquipment
{
public:
    CShield();

    virtual void enhance() override;

    virtual void battleEffect(CEnemy* enemy) override;
    virtual int shield(const unsigned int i) override;
};
