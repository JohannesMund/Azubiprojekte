#include "battlefieldcoords.h"

bool BattleFieldCoords::BattleFieldCoords::operator==(const BattleFieldCoords &other) const
{
    return x == other.x && y == other.y;
}

void BattleFieldCoords::BattleFieldCoords::transpose(const EDirections dir, const bool min)
{
    if (min)
    {
        dec(dir);
    }
    else
    {
        inc(dir);
    }
}

void BattleFieldCoords::BattleFieldCoords::inc(const EDirections dir)
{
    if (dir == EDirections::eHorizontal)
    {
        x++;
    }
    else
    {
        y++;
    }
}

void BattleFieldCoords::BattleFieldCoords::dec(EDirections dir)
{
    if (dir == EDirections::eHorizontal)
    {
        x--;
    }
    else
    {
        y--;
    }
}
