#include "ccavedungeon.h"
#include "ccavedungeonmap.h"

CCaveDungeon::CCaveDungeon()
{
}

void CCaveDungeon::execute()
{
    CCaveDungeonMap map(15, 15);
    map.setStartingPosition({0, 0});

    map.init();
    dungeonLoop(&map);
}
