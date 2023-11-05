#pragma once

#include "cencounter.h"

class CDeadHero : public CEncounter
{
public:
    CDeadHero();

    virtual void execute() override;
    virtual unsigned int encounterChance() const override;
    virtual std::string name() const override;
};
