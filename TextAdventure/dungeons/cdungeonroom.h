#pragma once

#include "croom.h"

#include <string>
class CDungeonRoom : public CRoom
{
public:
    CDungeonRoom();

    virtual void execute() override;
    virtual std::string mapSymbol() const override;
};
