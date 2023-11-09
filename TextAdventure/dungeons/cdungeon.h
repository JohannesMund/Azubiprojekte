#pragma once

#include "cdungeonmap.h"
#include "croom.h"

/**
 * @brief The CDungeon class
 * Class to handle dungeons.
 * Any Encounter / Task / room, etc can instantiate and execute a dungeon
 * must be derieved to be used.
 */

class CDungeon
{
public:
    /**
     * @brief CDungeon Constructor
     */
    CDungeon();
    virtual ~CDungeon()
    {
    }

    /**
     * @brief execute
     * must be implemented. Init a dungeon map and call dungeonLoop
     * @sa CDungeonMap
     * @sa dungeonLoop
     */
    virtual void execute() = 0;

protected:
    /**
     * @brief dungeonLoop
     * Handles the execution of the dungeon. blocks, until the dungeon is finished
     * @param map
     */
    void dungeonLoop(CDungeonMap* map);
};
