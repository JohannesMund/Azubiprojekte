#ifndef CSTARTINGROOM_H
#define CSTARTINGROOM_H

#include <croom.h>

class CStartingRoom : public CRoom
{
public:
    CStartingRoom();

    virtual void execute() override;
    virtual char mapSymbol() override;
};

#endif // CSTARTINGROOM_H
