#include "cbattleencounter.h"
#include "cbattle.h"
#include "ressources.h"

CBattleEncounter::CBattleEncounter() : CEncounter()
{
}

void CBattleEncounter::execute()
{
    CEncounter::execute();

    CBattle battle;
    battle.fight();
}

unsigned int CBattleEncounter::encounterChance() const
{
    if (!canBeExecuted())
    {
        return 0;
    }
    return Ressources::Config::fightChance;
}

std::string CBattleEncounter::name() const
{
    return "Battle";
}
