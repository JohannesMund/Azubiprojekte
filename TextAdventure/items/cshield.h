#pragma once
#include "cenhancableitem.h"

class CEnemy;
class CShield : public CEnhancableItem
{
public:
    CShield();

    virtual void enhance() override;

    virtual void battleEffect(CEnemy* enemy) override;
    virtual int shield(const unsigned int i) override;
};
