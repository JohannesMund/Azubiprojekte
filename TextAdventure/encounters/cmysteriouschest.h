#pragma once

#include "cencounter.h"

class CMysteriousChest : public CEncounter
{
public:
    CMysteriousChest();

    virtual void execute(const std::string& moduleName = {}) override;
    virtual unsigned int encounterChance(const EEncounterType& tp) const override;
    virtual std::string name() const override;
};
