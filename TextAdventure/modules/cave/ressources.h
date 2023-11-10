#pragma once

#include <string>
#include <utility>

namespace CaveRessources
{

static const unsigned int fightChance = 15;

std::string getRandomEnemyName();
std::string getRandomEnemyWeapon();

std::string getModuleName();
std::string getRandomDescription();

std::string getWellDescription(const int i);
std::string getWellQuestion(const int i);
std::string getWellEffect(const int i);

std::string getMapRoomDescription();

std::string getColoredBosString();
std::pair<std::string, std::string> getBoss();

} // namespace CaveRessources
