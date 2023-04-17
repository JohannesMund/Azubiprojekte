#pragma once

#include "battlefieldcoords.h"
#include "cabstractbattlefield.h"

#include <algorithm>
#include <functional>
#include <vector>

class CShipsAtCoords : public std::vector<BattleFieldCoords::ShipAtCoords>
{
public:
    using fnFilter = std::function<bool(BattleFieldCoords::ShipAtCoords const&)>;
    using fnLT = std::function<bool(BattleFieldCoords::ShipAtCoords const&, BattleFieldCoords::ShipAtCoords const&)>;

    static fnFilter shipIdFilter(const unsigned int shipId)
    {
        return [shipId](BattleFieldCoords::ShipAtCoords const& s) { return s.shipId == shipId; };
    }

    static fnFilter battleFieldCoordFilter(const BattleFieldCoords::BattleFieldCoords coords)
    {
        return [coords](BattleFieldCoords::ShipAtCoords const& s) { return s.coords == coords; };
    }

    static fnLT battleFieldCoordLT(const BattleFieldCoords::EDirections dir)
    {
        return [dir](BattleFieldCoords::ShipAtCoords const& s1, BattleFieldCoords::ShipAtCoords const& s2)
        {
            if (dir == BattleFieldCoords::EDirections::eVertical)
            {
                return s1.coords.y < s2.coords.y;
            }
            return s1.coords.x < s2.coords.x;
        };
    }

    CShipsAtCoords();

    bool contains(const BattleFieldCoords::BattleFieldCoords coords);
    bool contains(const unsigned int shipId);

    bool isInLine(const BattleFieldCoords::ShipAtCoords);

    bool isVerticalLine() const;
    bool isHorizontalLine() const;

    CShipsAtCoords filter(CShipsAtCoords::fnFilter fn);

private:
    bool isLine(const bool bVertical) const;
};
