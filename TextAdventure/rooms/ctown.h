#pragma once

#include "croom.h"

#include <string>

class CTown : public CRoom
{
public:
    CTown();

    virtual void execute() override;
    virtual char mapSymbol() override;

private:
    std::string _name;

    void blacksmith();
    void enhanceItem();

    void church();
    void shop();
    void tavern();
};
