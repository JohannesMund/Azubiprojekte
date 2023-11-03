#include "roomfactory.h"
#include "cinjuredpet.h"
#include "croom.h"
#include "ctown.h"

CRoom* RoomFactory::makeRoom()
{
    return new CRoom();
}

CTown* RoomFactory::makeTown()
{
    return new CTown();
}

CInjuredPet* RoomFactory::makeInjuredPet()
{
    return new CInjuredPet();
}
