#pragma once

#include <string>
#include <vector>

namespace Ressources
{

namespace Settings
{
static const unsigned int consoleWidth = 60;
}

namespace Config
{
static const unsigned int fieldWidth = 10;
static const unsigned int fieldHeight = 10;
static const unsigned int encounterChance = 5;
static const unsigned int fightRate = 75;

static const unsigned int maxHp = 10;
static const unsigned int gold = 10;

} // namespace Config

namespace Rooms
{
std::string getRandomDescription();
} // namespace Rooms

namespace Items
{
std::pair<std::string, std::string> getRandomRubbishItems();
}

} // namespace Ressources
