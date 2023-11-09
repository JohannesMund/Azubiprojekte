#include "ccavedungeon.h"
#include "cdungeonmap.h"

CCaveDungeon::CCaveDungeon()
{
}

void CCaveDungeon::execute()
{
    CDungeonMap map(15, 15);
    map.init();

    map.setStartingPosition({0, 0});

    dungeonLoop(&map);
}
