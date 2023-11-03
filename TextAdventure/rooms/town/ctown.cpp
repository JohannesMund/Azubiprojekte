#include "ctown.h"
#include "console.h"
#include "ressources.h"

#include <format>

CTown::CTown()
{
    auto town = Ressources::Rooms::getRandomTown();
    _name = town.first;
    _description = town.second;

    _shop.setCityName(_name);
    _church.setCityName(_name);
}

void CTown::execute()
{
    char input;
    do
    {
        Console::printLn(_name, Console::EAlignment::eCenter);
        Console::br();
        CRoom::execute();
        Console::hr();
        Console::printLn("[B]lacksmith [C]hurch [T]avern [S]hop E[x]it");

        input = Console::getAcceptableInput("bctsx");
        if (input == 'b')
        {
            _blackSmith.execute();
        }
        if (input == 'c')
        {
            _church.execute();
        }
        if (input == 't')
        {
            tavern();
        }
        if (input == 's')
        {
            _shop.execute();
        }
    } while (input != 'x');
}

char CTown::mapSymbol()
{
    return 'T';
}

void CTown::tavern()
{
}
