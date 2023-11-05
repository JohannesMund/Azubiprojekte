#include "cbattleencounter.h"
#include "cbattle.h"
#include "ressources.h"

CBattleEncounter::CBattleEncounter() : CEncounter()
{
}

void CBattleEncounter::execute()
{
    CBattle battle;
    battle.fight();
}

unsigned int CBattleEncounter::encounterChance() const
{
    return Ressources::Config::fightChance;
}

std::string CBattleEncounter::name() const
{
    return "battle";
}
