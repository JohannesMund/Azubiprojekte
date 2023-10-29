#include "cgamemanagement.h"
#include "conio.h"

#include <iostream>

using namespace std;

int main()
{
    ConIO::echo(false);
    ConIO::cls();
    ConIO::printLn("T H E   Q E S T  F O R   T H E   F L O I N K", ConIO::EAlignment::eCenter);
    ConIO::br();
    ConIO::printLn("the epic Quest for the legendary Floink", ConIO::EAlignment::eCenter);
    ConIO::hr();

    ConIO::printLn("You can [S]tart a new game oder e[X]it");

    char in = ConIO::getAcceptableInput("sx");
    if (in == 's')
    {
        CGameManagement::getInstance()->start();
    }

    cout << endl;
    ConIO::echo(true);
    return 0;
}
