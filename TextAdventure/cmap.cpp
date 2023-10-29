#include "cmap.h"
#include "croom.h"
#include "ressources.h"
#include "roomfactory.h"

#include <iostream>

const std::map<CMap::EDirections, char> CMap::_dirMap = {{EDirections::eNorth, 'n'},
                                                         {EDirections::eSouth, 's'},
                                                         {EDirections::eWest, 'w'},
                                                         {EDirections::eEast, 'e'},
                                                         {EDirections::eNone, 'x'}};

CMap::CMap()
{
    for (int x = 0; x < Ressources::Config::fieldHeight; x++)
    {
        std::vector<CRoom*> row;

        for (int y = 0; y < Ressources::Config::fieldWidth; y++)
        {
            row.push_back(RoomFactory::makeRoom());
        }

        _map.push_back(row);
    }
    setPlayerPosition({0, 0});
}

CMap::~CMap()
{
    for (auto& line : _map)
    {
        for (auto& room : line)
        {
            if (room != nullptr)
            {
                delete room;
            }
        }
    }
}

CMap::EDirections CMap::char2Direction(const char c)
{
    for (const auto& [key, value] : _dirMap)
    {
        if (key != EDirections::eNone && value == c)
        {
            return key;
        }
    }
    return EDirections::eNone;
}

char CMap::direction2Char(const EDirections dir)
{
    return _dirMap.at(dir);
}

void CMap::setPlayerPosition(const SRoomCoords& coords)
{
    if (coordsValid(coords))
    {
        _playerPosition = coords;
    }
}

void CMap::movePlayer(const EDirections dir)
{
    if (dir == EDirections::eNone)
    {
        return;
    }

    SRoomCoords coords(_playerPosition);

    if (dir == EDirections::eNorth)
    {
        coords.y--;
    }
    if (dir == EDirections::eEast)
    {
        coords.x++;
    }
    if (dir == EDirections::eSouth)
    {
        coords.y++;
    }
    if (dir == EDirections::eWest)
    {
        coords.x--;
    }

    if (coordsValid(coords))
    {
        _playerPosition = coords;
    }
}

bool CMap::coordsValid(const SRoomCoords& coords) const
{
    if (coords.x < 0 || coords.x >= _map.at(0).size())
    {
        return false;
    }

    if (coords.y < 0 || coords.y >= _map.size())
    {
        return false;
    }

    return true;
}

bool CMap::navAvailable(const EDirections dir) const
{
    return navAvailable(_playerPosition, dir);
}

bool CMap::navAvailable(const SRoomCoords& coords, const EDirections dir) const
{
    auto room = roomAt(coords);
    if (room == nullptr)
    {
        return false;
    }

    auto transposedCoords(coords);
    transposedCoords.transpose(dir);

    auto nextRoom = roomAt(transposedCoords);
    if (nextRoom == nullptr)
    {
        return false;
    }

    switch (dir)
    {
    case EDirections::eNorth:
        return room->north() && nextRoom->south();
    case EDirections::eEast:
        return room->east() && nextRoom->west();
    case EDirections::eSouth:
        return room->south() && nextRoom->north();
    case EDirections::eWest:
        return room->west() && nextRoom->east();
    default:
        return false;
    }

    return false;
}

void CMap::printRoom(const SRoomCoords& coords, const int line)
{
    using namespace std;

    bool left = navAvailable(coords, EDirections::eWest);

    if (line == 1)
    {
        cout << string{left ? " " : "|"};
        cout << mapSymbol(coords);
        cout << " ";
    }

    if (line == 2)
    {
        bool bottom = navAvailable(coords, EDirections::eSouth);
        cout << string{left ? bottom ? " " : "_" : "|"};
        cout << string{bottom ? "  " : "__"};
    }
}

void CMap::printMap()
{
    if (!_map.size())
    {
        return;
    }

    std::cout << " ";
    for (unsigned int x = 0; x < _map.at(0).size() * 3 - 1; x++)
    {
        std::cout << "_";
    }
    std::cout << std::endl;

    for (unsigned int y = 0; y < _map.size(); y++)
    {
        auto line = _map.at(y);

        for (auto i : {1, 2})
        {
            for (unsigned int x = 0; x < line.size(); x++)
            {
                printRoom({x, y}, i);
            }
            std::cout << "|" << std::endl;
        }
    }
}

char CMap::mapSymbol(const SRoomCoords& coords)
{
    if (coords == _playerPosition)
    {
        return 'X';
    }

    auto room = roomAt(coords);
    if (room != nullptr)
    {
        return room->mapSymbol();
    }

    return ' ';
}

CRoom* CMap::currentRoom() const
{
    return roomAt(_playerPosition);
}

CRoom* CMap::roomAt(const EDirections dir) const
{
    auto coords = _playerPosition;
    coords.transpose(dir);
    if (!coordsValid(coords))
    {
        return nullptr;
    }

    return roomAt(coords);
}

CRoom* CMap::roomAt(const SRoomCoords& coords) const
{
    if (!coordsValid(coords))
    {
        return nullptr;
    }

    return _map.at(coords.y).at(coords.x);
}

CMap::SRoomCoords CMap::getPlayerPosition() const
{
    return _playerPosition;
}
