#pragma once

#include "cblacksmith.h"
#include "cchurch.h"
#include "cfarm.h"
#include "cinventory.h"
#include "croom.h"
#include "cshop.h"

#include <string>

class CItem;
class CTown : public CRoom
{
public:
    CTown();

    virtual void execute() override;
    virtual char mapSymbol() override;

private:
    std::string _name;

    void tavern();
    void farm();

    CShop _shop;
    CChurch _church;
    CBlackSmith _blackSmith;
    CFarm _farm;
};
