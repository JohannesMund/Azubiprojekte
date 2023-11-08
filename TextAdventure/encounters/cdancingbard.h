#pragma ince

#include "cencounter.h"

class CDancingBard : public CEncounter
{
public:
    CDancingBard();

    virtual void execute() override;
    virtual unsigned int encounterChance(const EEncounterType& tp) const override;
    virtual std::string name() const override;
};
