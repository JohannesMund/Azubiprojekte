#pragma once

#include "croom.h"

class CInjuredPet : public CRoom
{
public:
    CInjuredPet();

    virtual void execute() override;
    virtual char mapSymbol() override;

private:
    bool _petIsDead = false;
};
