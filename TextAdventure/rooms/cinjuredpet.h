#pragma once

#include "cfield.h"

class CInjuredPet : public CField
{
public:
    CInjuredPet();

    virtual void execute() override;
    virtual std::string mapSymbol() override;

private:
    bool _petIsDead = false;
};
