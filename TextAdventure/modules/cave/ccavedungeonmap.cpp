#include "ccavedungeonmap.h"
#include "ccavedungeonroom.h"

CCaveDungeonMap::CCaveDungeonMap(const unsigned int width, const unsigned int height) : CDungeonMap(width, height)
{
}

CDungeonRoom* CCaveDungeonMap::makeDefaultRoom() const
{
    return new CCaveDungeonRoom();
}
