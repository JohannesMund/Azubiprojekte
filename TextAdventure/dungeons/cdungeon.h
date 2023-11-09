#pragma once

#include "cdungeonmap.h"
#include "croom.h"

class CDungeon
{
public:
    CDungeon();
    virtual ~CDungeon()
    {
    }

    virtual void execute() = 0;

protected:
    void dungeonLoop(CDungeonMap* map);
};
