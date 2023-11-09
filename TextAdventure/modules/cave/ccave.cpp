#include "ccave.h"
#include "ccavedungeon.h"
#include "ccavedungeonmap.h"
#include "cmenu.h"
#include "colorconsole.h"
#include "console.h"
CCave::CCave()
{
    _showInFogOfWar = true;
}

void CCave::execute()
{
    Console::printLn("There is a cave, do you want to have a look?");
    if (CMenu::yes(CMenu::executeYesNoMenu()))
    {
        CCaveDungeonMap map(25, 10);
        map.setStartingPosition({0, 0});
        map.init();

        CCaveDungeon dungeon;
        dungeon.setDungeonMap(&map);
        dungeon.execute();
    }

    CField::execute();
}

std::string CCave::mapSymbol() const
{
    return "C";
}
