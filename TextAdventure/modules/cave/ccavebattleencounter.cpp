#include "ccavebattleencounter.h"
#include "cbattle.h"
#include "cencounter.h"
#include "cmobenemy.h"
#include "ressources.h"

CCaveBattleEncounter::CCaveBattleEncounter()
{
    _type = CEncounter::eDungeon;
}

void CCaveBattleEncounter::execute(const std::string_view& moduleName)
{
    CEncounter::execute(moduleName);

    CMobEnemy enemy;
    enemy.setWeapon(CaveRessources::getRandomEnemyWeapon());
    enemy.setName(CaveRessources::getRandomEnemyName());

    CBattle battle;
    battle.fight();
}

unsigned int CCaveBattleEncounter::encounterChance(const EEncounterType& tp, const std::string_view& moduleName) const
{
    if (moduleName.compare(CaveRessources::getModuleName()) != 0)
    {
        return 0;
    }

    if (!canBeExecuted(tp))
    {
        return 0;
    }
    return CaveRessources::fightChance;
}

std::string CCaveBattleEncounter::name() const
{
    return "Battle";
}