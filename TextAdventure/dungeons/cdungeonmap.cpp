#include "cdungeonmap.h"
#include "cdungeonroom.h"
#include "cdungeonroomnoroom.h"
#include "randomizer.h"

#include <algorithm>
#include <cmath>

CDungeonMap::CDungeonMap(const unsigned int width, const unsigned int height) : CMap(width, height)
{
}

void CDungeonMap::init()
{
    unsigned int steps = 0;
    _populatedRoomCount = std::ceil((_map.size() * _map.at(0).size()) / 2);

    makeNextRoom(getPlayerPosition(), steps);

    fillWithNoRooms();
}

void CDungeonMap::makeNextRoom(const SRoomCoords coords, unsigned int& i)
{
    _map.at(coords.y).at(coords.x) = makeDefaultRoom();
    i++;
    if (i >= _populatedRoomCount)
    {
        return;
    }

    std::vector<SRoomCoords> possibilities;
    for (const auto dir :
         {CMap::EDirections::eEast, CMap::EDirections::eSouth, CMap::EDirections::eWest, CMap::EDirections::eNorth})
    {
        auto transposedCoords(coords);
        transposedCoords.transpose(dir);
        auto room = roomAt(transposedCoords);
        if (room.has_value() && *room == nullptr)
        {
            possibilities.push_back(transposedCoords);
        }
    }

    if (!possibilities.size())
    {
        return;
    }

    std::shuffle(
        possibilities.begin(), possibilities.end(), std::default_random_engine(Randomizer::getRandomEngineSeed()));

    for (auto c : possibilities)
    {
        makeNextRoom(c, i);
        if (i >= _populatedRoomCount)
        {
            return;
        }
    }
}

CDungeonRoom* CDungeonMap::makeNoRoom() const
{
    return new CDungeonRoomNoRoom();
}

void CDungeonMap::reveal()
{
    for (auto& l : _map)
    {
        for (auto& r : l)
        {
            r->setSeen(true);
        }
    }
}

unsigned int CDungeonMap::roomCount() const
{
    return _populatedRoomCount;
}

unsigned int CDungeonMap::seenRooms() const
{
    int count = 0;
    for (const auto& line : _map)
    {
        for (const auto& room : line)
        {
            if (room->seen())
            {
                count++;
            }
        }
    }
    return count;
}

void CDungeonMap::fillWithNoRooms()
{
    for (unsigned int x = 0; x < _map.size(); x++)
    {
        auto line = _map.at(x);

        for (unsigned int y = 0; y < line.size(); y++)
        {
            if (_map.at(x).at(y) == nullptr)
            {
                _map.at(x).at(y) = makeNoRoom();
            }
        }
    }
}
