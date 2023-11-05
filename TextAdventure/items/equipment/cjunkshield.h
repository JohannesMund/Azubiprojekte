#pragma once

#include "cshield.h"

class CJunkShield : public CShield
{
public:
    CJunkShield();

    virtual void battleEffect(CEnemy* enemy) override;
    virtual int shield(const unsigned int i) override;
};
