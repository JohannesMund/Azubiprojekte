#include "ccave.h"
#include "ccavedungeon.h"
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
        Console::printLn("Let's go!");

        CCaveDungeon dungeon;
        dungeon.execute();
    }

    CField::execute();
}

std::string CCave::mapSymbol() const
{
    return "C";
}
