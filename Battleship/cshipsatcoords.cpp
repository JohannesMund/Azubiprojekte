#include "cshipsatcoords.h"

CShipsAtCoords::CShipsAtCoords()
{
}

bool CShipsAtCoords::contains(const BattleFieldCoords::BattleFieldCoords coords)
{
    return std::count_if(begin(), end(), battleFieldCoordFilter(coords)) != 0;
}

bool CShipsAtCoords::contains(const unsigned int shipId)
{
    return std::count_if(begin(), end(), shipIdFilter(shipId)) != 0;
}

bool CShipsAtCoords::isInLine(const BattleFieldCoords::ShipAtCoords s)
{
    if (!contains(s.shipId))
    {
        return true;
    }

    if (contains(s.coords))
    {
        return false;
    }

    auto filtered = filter(shipIdFilter(s.shipId));

    if (s.coords.x == filtered.at(0).coords.x)
    {
        for (auto m : filtered)
        {
            if (s.coords.y == m.coords.y + 1 || s.coords.y == m.coords.y - 1)
            {
                return true;
            }
        }
    }

    if (s.coords.y == filtered.at(0).coords.y)
    {
        for (auto m : filtered)
        {
            if (s.coords.x == m.coords.x + 1 || s.coords.x == m.coords.x - 1)
            {
                return true;
            }
        }
    }

    return false;
}

bool CShipsAtCoords::isVerticalLine() const
{
    return isLine(true);
}

bool CShipsAtCoords::isHorizontalLine() const
{
    return isLine(false);
}

CShipsAtCoords CShipsAtCoords::filter(fnFilter fn)
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

bool CShipsAtCoords::isLine(const bool bVertical) const
{
    if (size() <= 1)
    {
        return true;
    }

    auto horizontalOrVerticalCoord = [bVertical](const BattleFieldCoords::BattleFieldCoords coords)
    {
        if (bVertical)
        {
            return coords.y;
        }
        return coords.x;
    };

    auto c = horizontalOrVerticalCoord(at(0).coords);

    for (auto s : *this)
    {
        if (horizontalOrVerticalCoord(s.coords) != c)
        {
            return false;
        }
    }
    return true;
}
