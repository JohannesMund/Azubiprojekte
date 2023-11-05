#include "cmap.h"
#include "cinjuredpet.h"
#include "console.h"
#include "croom.h"
#include "cstartingroom.h"
#include "ctask.h"
#include "ctown.h"
#include "randomizer.h"
#include "ressources.h"
#include "roomfactory.h"

#include <algorithm>
#include <iostream>
#include <random>

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
            row.push_back(nullptr);
        }

        _map.push_back(row);
    }
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

void CMap::init()
{
    std::vector<CRoom*> rooms;

    rooms.push_back(RoomFactory::makeInjuredPet());

    for (int i = 0; i < Ressources::Config::numberOfTowns; i++)
    {
        rooms.push_back(RoomFactory::makeTown());
    }

    while (rooms.size() < (Ressources::Config::fieldWidth * Ressources::Config::fieldHeight) - 1)
    {
        rooms.push_back(RoomFactory::makeRoom());
    }

    std::shuffle(rooms.begin(), rooms.end(), std::default_random_engine(Randomizer::getRandomEngineSeed()));

    for (int iRow = 0; iRow < _map.size(); iRow++)
    {
        auto row = _map.at(iRow);
        for (int iCol = 0; iCol < row.size(); iCol++)
        {
            if (iRow == _playerPosition.y && iCol == _playerPosition.x)
            {
                row.at(iCol) = new CStartingRoom();
                continue;
            }

            row.at(iCol) = rooms.at(rooms.size() - 1);
            rooms.pop_back();
        }
        _map.at(iRow) = row;
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

void CMap::setStartingPosition(const SRoomCoords& coords)
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

    auto room = roomAt(coords);
    if (room == nullptr)
    {
        cout << "   ";
        return;
    }

    if (room->seen() == false)
    {
        if (room->showInFogOfWar() && line == 1)
        {
            cout << " " << mapSymbol(coords) << " ";
            return;
        }
        else
        {
            cout << "   ";
            return;
        }
    }

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
    for (unsigned int x = 0; x < _map.at(0).size(); x++)
    {
        auto room = roomAt({x, 0});
        if (room != nullptr && room->seen())
        {
            std::cout << "___";
        }
        else
        {
            std::cout << "   ";
        }
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

            auto room = roomAt({(unsigned)line.size() - 1, y});
            if (room != nullptr && room->seen())
            {
                std::cout << "|" << std::endl;
            }
            else
            {
                std::cout << " " << std::endl;
            }
        }
    }
}

std::string CMap::printNav()
{
    std::string acceptableInputs;
    std::string navigationDisplay;
    if (navAvailable(CMap::EDirections::eNorth))
    {
        navigationDisplay += "[N]orth ";
        acceptableInputs += CMap::direction2Char(CMap::EDirections::eNorth);
    }
    if (navAvailable(CMap::EDirections::eEast))
    {
        navigationDisplay += "[E]ast ";
        acceptableInputs += CMap::direction2Char(CMap::EDirections::eEast);
    }
    if (navAvailable(CMap::EDirections::eSouth))
    {
        navigationDisplay += "[S]outh ";
        acceptableInputs += CMap::direction2Char(CMap::EDirections::eSouth);
    }
    if (navAvailable(CMap::EDirections::eWest))
    {
        navigationDisplay += "[W]est ";
        acceptableInputs += CMap::direction2Char(CMap::EDirections::eWest);
    }

    Console::printLn(navigationDisplay);
    return acceptableInputs;
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

void CMap::setTaskToRandomRoom(CTask* task)
{
    std::vector<CRoom*> possibleRooms;
    for (const auto& row : _map)
    {
        for (auto& room : row)
        {
            if (room->isTaskPossible() && room != currentRoom())
            {
                possibleRooms.push_back(room);
            }
        }
    }

    if (possibleRooms.size() == 0)
    {
        return;
    }

    std::shuffle(
        possibleRooms.begin(), possibleRooms.end(), std::default_random_engine(Randomizer::getRandomEngineSeed()));
    possibleRooms.at(0)->setTask(task);
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
