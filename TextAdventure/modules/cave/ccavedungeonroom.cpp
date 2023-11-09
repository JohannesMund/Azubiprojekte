#include "ressources.h"

#include "ccavedungeonroom.h"
#include "cgamemanagement.h"

CCaveDungeonRoom::CCaveDungeonRoom()
{
    _description = CaveRessources::getRandomDescription();

    _encounterPossible = true;
    _taskPossible = true;
}

void CCaveDungeonRoom::execute()
{
    if (_encounterPossible)
    {
        CGameManagement::getInstance()->executeRandomEncounter(CEncounter::eDungeon, CaveRessources::getModuleName());
    }

    CRoom::execute();
}
