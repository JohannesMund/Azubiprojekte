#include "cdungeonroomnoroom.h"

CDungeonRoomNoRoom::CDungeonRoomNoRoom()
{
    _taskPossible = false;
    _encounterPossible = false;

    _pathNorth = false;
    _pathSouth = false;
    _pathEast = false;
    _pathWest = false;

    _seen = false;
}

void CDungeonRoomNoRoom::setSeen(const bool)
{
}
