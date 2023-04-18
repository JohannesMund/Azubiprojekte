#include "cshipsatcoords.h"

CShipsAtCoords::CShipsAtCoords()
{
}

bool CShipsAtCoords::contains(const BattleFieldCoords::BattleFieldCoords coords)
{
    return std::count_if(begin(), end(), CShipAtCoords::battleFieldCoordFilter(coords)) != 0;
}

bool CShipsAtCoords::contains(const unsigned int shipId)
{
    return std::count_if(begin(), end(), CShipAtCoords::shipIdFilter(shipId)) != 0;
}

bool CShipsAtCoords::isInLine(const CShipAtCoords s)
{
    if (!contains(s.getShipId()))
    {
        return true;
    }

    if (contains(s.getCoords()))
    {
        return false;
    }

    auto filtered = filter(CShipAtCoords::shipIdFilter(s.getShipId()));

    if (s.getCoords().x == filtered.at(0).getCoords().x)
    {
        for (auto m : filtered)
        {
            if (s.getCoords().y == m.getCoords().y + 1 || s.getCoords().y == m.getCoords().y - 1)
            {
                return true;
            }
        }
    }

    if (s.getCoords().y == filtered.at(0).getCoords().y)
    {
        for (auto m : filtered)
        {
            if (s.getCoords().x == m.getCoords().x + 1 || s.getCoords().x == m.getCoords().x - 1)
            {
                return true;
            }
        }
    }

    return false;
}

bool CShipsAtCoords::isVerticalLine() const
{
    return isLine(BattleFieldCoords::EDirections::eVertical);
}

bool CShipsAtCoords::isHorizontalLine() const
{
    return isLine(BattleFieldCoords::EDirections::eHorizontal);
}

CShipsAtCoords CShipsAtCoords::filter(CShipAtCoords::fnFilter fn)
{
    CShipsAtCoords filtered;
    for (auto s : *this)
    {
        if (fn(s))
        {
            filtered.push_back(s);
        }
    }
    return filtered;
}

bool CShipsAtCoords::isLine(const BattleFieldCoords::EDirections dir) const
{
    if (size() <= 1)
    {
        return true;
    }

    auto horizontalOrVerticalCoord = [&dir](const BattleFieldCoords::BattleFieldCoords coords)
    {
        if (dir == BattleFieldCoords::EDirections::eVertical)
        {
            return coords.x;
        }
        return coords.y;
    };

    auto c = horizontalOrVerticalCoord(at(0).getCoords());

    for (auto s : *this)
    {
        if (horizontalOrVerticalCoord(s.getCoords()) != c)
        {
            return false;
        }
    }
    return true;
}
