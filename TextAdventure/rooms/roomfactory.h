#pragma once

class CRoom;
class CTown;
namespace RoomFactory
{

CRoom* makeRoom();
CTown* makeTown();

} // namespace RoomFactory
