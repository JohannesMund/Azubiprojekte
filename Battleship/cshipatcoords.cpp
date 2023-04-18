#include "cshipatcoords.h"
#include "cgamemanagement.h"
CShipAtCoords::CShipAtCoords() : _coords{0, 0}, _shipId(-1)
{
}

CShipAtCoords::CShipAtCoords(const BattleFieldCoords::BattleFieldCoords& coords, const unsigned int shipId) :
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
