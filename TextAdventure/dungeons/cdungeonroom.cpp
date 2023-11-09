#include "cdungeonroom.h"
#include "cgamemanagement.h"

CDungeonRoom::CDungeonRoom()
{
    _description = "generic dungeon room";
    _encounterPossible = true;
    _taskPossible = true;
}

void CDungeonRoom::execute()
{
    if (_encounterPossible)
    {
        CGameManagement::getInstance()->executeRandomEncounter(CEncounter::eDungeon);
    }

    CRoom::execute();
}

std::string CDungeonRoom::mapSymbol() const
{
    return " ";
}
