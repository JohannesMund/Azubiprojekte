#pragma once

#include "cbattleencounter.h"
#include "cdancingbard.h"
#include "cdeadhero.h"
#include "cgamemanagement.h"
#include "cmysteriouschest.h"

namespace EncounterRegister
{
void encounterRegister()
{
    CGameManagement::getInstance()->registerEncounter(new CMysteriousChest());
    CGameManagement::getInstance()->registerEncounter(new CDeadHero());
    CGameManagement::getInstance()->registerEncounter(new CBattleEncounter());

    CGameManagement::getInstance()->registerEncounter(new CDancingBard());
}
} // namespace EncounterRegister
