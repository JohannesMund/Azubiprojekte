#include "cshipvector.h"

#include <algorithm>
#include <functional>

#include <ranges>
CShipVector::CShipVector()
{
}

bool CShipVector::contains(const BattleFieldCoords::BattleFieldCoords coords)
{
    return std::find_if(begin(), end(), CShipAtCoords::battleFieldCoordFilter(coords)) != end();
}

bool CShipVector::contains(const unsigned int shipId)
{
    return std::find_if(begin(), end(), CShipAtCoords::shipIdFilter(shipId)) != end();
}

bool CShipVector::isInLine(const CShipAtCoords s)
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

bool CShipVector::isVerticalLine() const
{
    return isLine(BattleFieldCoords::EDirections::eVertical);
}

bool CShipVector::isHorizontalLine() const
{
    return isLine(BattleFieldCoords::EDirections::eHorizontal);
}

CShipVector CShipVector::filter(const CShipAtCoords::fnFilter fn) const
{
    CShipVector filtered;
    /**
     * Hier benutzen wir std::ranges. Sehr convinient!
     */

    for (auto s : *this | std::views::filter(fn))
    {
        filtered.push_back(s);
    }

    return filtered;
}

bool CShipVector::isLine(const BattleFieldCoords::EDirections dir) const
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
