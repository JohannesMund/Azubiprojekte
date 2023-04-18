#pragma once

#include "battlefieldcoords.h"

#include <functional>

class CShipAtCoords
{

public:
    using fnFilter = std::function<bool(CShipAtCoords const&)>;
    using fnLT = std::function<bool(CShipAtCoords const&, CShipAtCoords const&)>;

    CShipAtCoords();
    CShipAtCoords(const BattleFieldCoords::BattleFieldCoords& coords, const unsigned int shipId);

    BattleFieldCoords::BattleFieldCoords getCoords() const;
    unsigned int getShipId() const;
    void transposeCoords(const BattleFieldCoords::EDirections dir, const bool min);

    static fnFilter shipIdFilter(const unsigned int shipId)
    {
        return [shipId](CShipAtCoords const& s) { return s._shipId == shipId; };
    }

    static fnFilter battleFieldCoordFilter(const BattleFieldCoords::BattleFieldCoords coords)
    {
        return [coords](CShipAtCoords const& s) { return s._coords == coords; };
    }

    static fnLT battleFieldCoordLT(const BattleFieldCoords::EDirections dir)
    {
        return [dir](CShipAtCoords const& s1, CShipAtCoords const& s2)
        {
            if (dir == BattleFieldCoords::EDirections::eVertical)
            {
                return s1._coords.y < s2._coords.y;
            }
            return s1._coords.x < s2._coords.x;
        };
    }

private:
    BattleFieldCoords::BattleFieldCoords _coords;
    unsigned int _shipId;
};
