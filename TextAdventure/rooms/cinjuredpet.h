#pragma once

#include "croom.h"

class CInjuredPet : public CRoom
{
public:
    CInjuredPet();

    virtual void execute() override;
    virtual std::string mapSymbol() override;

private:
    bool _petIsDead = false;
};
