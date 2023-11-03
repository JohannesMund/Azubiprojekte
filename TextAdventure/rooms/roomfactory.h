#pragma once

class CRoom;
class CTown;
class CInjuredPet;
namespace RoomFactory
{

CRoom* makeRoom();
CTown* makeTown();
CInjuredPet *makeInjuredPet();

} // namespace RoomFactory
