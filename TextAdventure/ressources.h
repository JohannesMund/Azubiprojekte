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

static const std::vector<int> xpForLevel = {0, 300, 700, 1300, 2000, 4000, 8000, 14000, 20000};
static const unsigned int encounterChance = 5;
static const unsigned int fightRate = 75;

static const unsigned int maxHp = 10;
static const unsigned int maxHpMin = 3;
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
