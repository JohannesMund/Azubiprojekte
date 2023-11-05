#pragma once

#include "cencounter.h"

class CBattleEncounter : public CEncounter
{
public:
    CBattleEncounter();

    virtual void execute() override;
    virtual unsigned int encounterChance() const override;
    virtual std::string name() const override;
};
