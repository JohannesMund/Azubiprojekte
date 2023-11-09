#ifndef CCAVEDUNGEONROOM_H
#define CCAVEDUNGEONROOM_H

#include <cdungeonroom.h>

class CCaveDungeonRoom : public CDungeonRoom
{
public:
    CCaveDungeonRoom();

    void execute() override;
};

#endif // CCAVEDUNGEONROOM_H
