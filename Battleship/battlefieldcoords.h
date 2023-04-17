#pragma once

namespace BattleFieldCoords
{
struct BattleFieldCoords
{
    unsigned int x;
    unsigned int y;

    bool operator==(const BattleFieldCoords& other) const
    {
        return x == other.x && y == other.y;
    }

    BattleFieldCoords operator+(const BattleFieldCoords& other)
    {
        return {x + other.x, y + other.y};
    }
    BattleFieldCoords operator-(const BattleFieldCoords& other)
    {
        return {x - other.x, y - other.y};
    }
};

struct ShipAtCoords
{
    BattleFieldCoords coords;
    unsigned int shipId;
};

enum class EDirections
{
    eHorizontal,
    eVertical
};
} // namespace BattleFieldCoords
