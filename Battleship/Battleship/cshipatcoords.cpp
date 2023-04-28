#include "cshipatcoords.h"
#include "cgamemanagement.h"

CShipAtCoords::CShipAtCoords() : _coords{0, 0}, _shipId(CGameManagement::InvalidShipId)
{
}

CShipAtCoords::CShipAtCoords(const BattleFieldCoords::BattleFieldCoords& coords, const int shipId) :
    _coords(coords),
    _shipId(shipId)
{
}

BattleFieldCoords::BattleFieldCoords CShipAtCoords::getCoords() const
{
    return _coords;
}

unsigned int CShipAtCoords::getShipId() const
{
    return _shipId;
}

void CShipAtCoords::transposeCoords(const BattleFieldCoords::EDirections dir, const bool min)
{
    _coords.transpose(dir, min);
}

CShipAtCoords::fnFilter CShipAtCoords::shipIdFilter(const int shipId)
{
    return [shipId](CShipAtCoords const& s) { return s._shipId == shipId; };
}

CShipAtCoords::fnFilter CShipAtCoords::battleFieldCoordFilter(const BattleFieldCoords::BattleFieldCoords coords)
{
    return [coords](CShipAtCoords const& s) { return s._coords == coords; };
}

CShipAtCoords::fnLT CShipAtCoords::battleFieldCoordLT(const BattleFieldCoords::EDirections dir)
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
