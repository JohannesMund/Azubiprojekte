#pragma once

#include "cencounter.h"

class CDeadHero : public CEncounter
{
public:
    CDeadHero();

    virtual void execute(const std::string& moduleName = {}) override;
    virtual unsigned int encounterChance(const EEncounterType& tp) const override;
    virtual std::string name() const override;
};
