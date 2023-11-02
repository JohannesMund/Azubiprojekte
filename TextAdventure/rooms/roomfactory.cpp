#include "roomfactory.h"
#include "croom.h"

CRoom* RoomFactory::makeRoom()
{
    return new CRoom();
}
