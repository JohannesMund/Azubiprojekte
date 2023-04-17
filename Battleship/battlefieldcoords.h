#pragma once

namespace BattleFieldCoords
{
enum class EDirections
{
    eHorizontal,
    eVertical
};

struct BattleFieldCoords
{
    unsigned int x;
    unsigned int y;

    bool operator==(const BattleFieldCoords& other) const
    {
        return x == other.x && y == other.y;
    }

    void transpose(const EDirections dir, const bool min)
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

    void inc(const EDirections dir)
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
    void dec(EDirections dir)
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
};

struct ShipAtCoords
{
    BattleFieldCoords coords;
    unsigned int shipId;
};

} // namespace BattleFieldCoords
