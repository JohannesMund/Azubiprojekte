#include "cgamemanagement.h"
#include "console.h"

#include <iostream>

using namespace std;

int main()
{
    Console::echo(false);
    Console::cls();
    Console::printLn("T H E   Q E S T  F O R   T H E   F L O I N K", Console::EAlignment::eCenter);
    Console::br();
    Console::printLn("the epic Quest for the legendary Floink", Console::EAlignment::eCenter);
    Console::hr();

    Console::printLn("You can [S]tart a new game oder e[X]it");

    char in = Console::getAcceptableInput("sx");
    if (in == 's')
    {
        CGameManagement::getInstance()->start();
    }

    cout << endl;
    Console::echo(true);
}
