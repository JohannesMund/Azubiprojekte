#pragma once

#include "cmap.h"

#include <optional>

class CDungeonRoom;

/**
 * @brief The CDungeonMap class
 * represents the map of a dungeon. initialiszes the dungeon randomly
 */

class CDungeonMap : public CMap
{
public:
    /**
     * @brief CDungeonMap Constructor
     * @param width width of the dungeon
     * @param height height of the dungeon
     */
    CDungeonMap(const unsigned int width, const unsigned int height);

    /**
     * @brief init populates the dungeon randomly.
     * call, the have the dungeon filled
     * override, to replace certain rooms
     */
    virtual void init() override;

    /**
     * @brief reveal
     * Sets all DungeonRooms to _seen=true;
     * CDungeonRoomNoRoom ignores that
     * @sa CDungeonRoomNoRoom
     */
    void reveal();

protected:
    /**
     * @brief makeDefaultRoom
     * used by init()
     * override to fill the dungeon with custom rooms
     * @sa init()
     * @return a default dungeon room
     */
    virtual CDungeonRoom* makeDefaultRoom() const = 0;

    /**
     * @brief makeNoRoom
     * @return returns a blank field, that cannot be entered
     */
    CDungeonRoom* makeNoRoom() const;

private:
    void makeNextRoom(const CMap::SRoomCoords coords, unsigned int& i);

    void fillWithNoRooms();

    unsigned int _populatedRoomCount = 0;
};
