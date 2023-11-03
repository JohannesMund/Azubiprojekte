#pragma once

#include <croom.h>

class CStartingRoom : public CRoom
{
public:
    CStartingRoom();

    virtual void execute() override;
    virtual char mapSymbol() override;
};
