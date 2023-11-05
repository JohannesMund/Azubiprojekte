#pragma once

#include "carmor.h"

class CJunkArmor : public CArmor
{
public:
    CJunkArmor();

    virtual void battleEffect(CEnemy* enemy) override;
    virtual int shield(const unsigned int i) override;
};
