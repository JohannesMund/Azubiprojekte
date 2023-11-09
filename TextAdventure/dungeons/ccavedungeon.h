#pragma once

#include "cdungeon.h"

class CCaveDungeon : public CDungeon
{
public:
    CCaveDungeon();

    virtual void execute() override;
};
