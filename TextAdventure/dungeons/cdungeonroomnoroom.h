#pragma once

#include <cdungeonroom.h>

class CDungeonRoomNoRoom : public CDungeonRoom
{
public:
    CDungeonRoomNoRoom();

    virtual void setSeen(const bool b) override;
};
