#include "cgamemanagement.h"
#include "console.h"

#include <iostream>

using namespace std;

int main()
{
    Console::setEcho(false);
    Console::cls();
    Console::printLn("T H E   Q E S T  F O R   T H E   F L O I N K", Console::EAlignment::eCenter);
    Console::br();
    Console::printLn("the epic Quest for the legendary Floink", Console::EAlignment::eCenter);
    Console::hr();

    Console::printLn("[S]tart a new game", Console::EAlignment::eCenter);
    Console::printLn("[Q]uit game", Console::EAlignment::eCenter);

    char in = Console::getAcceptableInput("sq");
    if (in == 's')
    {
        CGameManagement::getInstance()->start();
    }

    cout << endl;
    Console::setEcho(true);
}
