#include <iostream>

#include "cgamemanagement.h"
#include "console.h"
#include "croom.h"
#include "ressources.h"

using namespace std;

CRoom::CRoom()
{
    _description = Ressources::Rooms::getRandomDescription();
    _encounterPossible = true;
}

CRoom::~CRoom()
{
}

void CRoom::execute()
{
    Console::printLn(_description);
}

void CRoom::blockPath(const CMap::EDirections dir, const bool block)
{
    switch (dir)
    {
    case CMap::EDirections::eNorth:
        _pathNorth = !block;
        break;
    case CMap::EDirections::eEast:
        _pathEast = !block;
        break;
    case CMap::EDirections::eSouth:
        _pathSouth = !block;
        break;
    case CMap::EDirections::eWest:
        _pathWest = !block;
        break;
    default:
        break;
    }
}

bool CRoom::north() const
{
    return _pathNorth;
}

bool CRoom::east() const
{
    return _pathEast;
}

bool CRoom::south() const
{
    return _pathSouth;
}

bool CRoom::west() const
{
    return _pathWest;
}

char CRoom::mapSymbol()
{
    return '+';
}
