#pragma once

#include "cmap.h"

#include <optional>

class CDungeonRoom;
class CDungeonMap : public CMap
{
public:
    CDungeonMap(const unsigned int width, const unsigned int height);
    virtual void init() override;

    virtual CDungeonRoom* makeDefaultRoom() const;
    virtual CDungeonRoom* makeNoRoom() const;

    void reveal();

private:
    void makeNextRoom(const CMap::SRoomCoords coords, unsigned int& i);

    void fillWithNoRooms();

    unsigned int _populatedRoomCount = 0;
};
