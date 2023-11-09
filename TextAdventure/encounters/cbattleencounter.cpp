#include "cbattleencounter.h"
#include "cbattle.h"
#include "ressources.h"

CBattleEncounter::CBattleEncounter() : CEncounter()
{
    _type = CEncounter::eField | CEncounter::eDungeon;
}

void CBattleEncounter::execute(const std::string& moduleName)
{
    CEncounter::execute(moduleName);

    CBattle battle;
    battle.fight();
}

unsigned int CBattleEncounter::encounterChance(const EEncounterType& tp) const
{
    if (!canBeExecuted(tp))
    {
        return 0;
    }
    return Ressources::Config::fightChance;
}

std::string CBattleEncounter::name() const
{
    return "Battle";
}
