#pragma once

#include <map>
#include <vector>

class CRoom;
class CMap
{
public:
    enum class EDirections
    {
        eNone,
        eNorth,
        eEast,
        eSouth,
        eWest
    };

    static const std::map<EDirections, char> _dirMap;

    struct SRoomCoords
    {
        unsigned int x;
        unsigned int y;

        bool operator==(const SRoomCoords& other) const
        {
            return x == other.x && y == other.y;
        }

        void transpose(const EDirections dir)
        {
            switch (dir)
            {
            case EDirections::eNorth:
                y--;
                break;
            case EDirections::eEast:
                x++;
                break;
            case EDirections::eSouth:
                y++;
                break;
            case EDirections::eWest:
                x--;
                break;
            default:
                break;
            }
        }
    };

    static EDirections char2Direction(const char c);
    static char direction2Char(const EDirections dir);

    CMap();
    ~CMap();

    void setPlayerPosition(const SRoomCoords& coords);
    void movePlayer(const EDirections dir);
    SRoomCoords getPlayerPosition() const;
    bool coordsValid(const SRoomCoords& coords) const;
    bool navAvailable(const EDirections dir) const;
    bool navAvailable(const SRoomCoords& coords, const EDirections dir) const;

    void printRoom(const SRoomCoords& coords, const int line);
    void printMap();
    char mapSymbol(const SRoomCoords& coords);

    CRoom* currentRoom() const;

private:
    SRoomCoords _playerPosition;

    std::vector<std::vector<CRoom*>> _map;
    CRoom* roomAt(const EDirections dir) const;
    CRoom* roomAt(const SRoomCoords& coords) const;
};
