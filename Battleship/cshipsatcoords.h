#pragma once

#include "battlefieldcoords.h"
#include "cabstractbattlefield.h"
#include "cshipatcoords.h"

#include <vector>

class CShipsAtCoords : public std::vector<CShipAtCoords>
{
public:
    CShipsAtCoords();

    bool contains(const BattleFieldCoords::BattleFieldCoords coords);
    bool contains(const unsigned int shipId);

    bool isInLine(const CShipAtCoords s);

    bool isVerticalLine() const;
    bool isHorizontalLine() const;

    CShipsAtCoords filter(CShipAtCoords::fnFilter fn);

private:
    bool isLine(const BattleFieldCoords::EDirections dir) const;
};
