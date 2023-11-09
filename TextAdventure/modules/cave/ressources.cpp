#include "ressources.h"
#include "randomizer.h"

#include <vector>

std::string CaveRessources::getRandomDescription()
{
    std::vector<std::string> _roomDescriptions = {
        "A cave, what do you expect? it's dirty, it*s dark, it's stuffy. Not the place to be right now.",

        "A cave, just a cave, but here are huge stalagmites and stalagtites. but which is which? ",

        "It is especially muddy here. It smells musty. There is a mushroom, and it is glowing green. Maybe, if you are "
        "very hungry. Well, very, very very hungry"};
    return _roomDescriptions.at(Randomizer::getRandom(_roomDescriptions.size()));
}

std::string CaveRessources::getModuleName()
{
    return "Mysterious Cave";
}

std::string CaveRessources::getRandomEnemyName()
{
    std::vector<std::string> names = {
        "Cave Troll",
        "Spider",
        "Bat",
        "Cave Gnoll",
    };
    return names.at(Randomizer::getRandom(names.size()));
}

std::string CaveRessources::getRandomEnemyWeapon()
{
    std::vector<std::string> weapons = {
        "shabby board with a rusty nail hammered through", "sharp teeth", "sheer muscle power", "a club with spikes"};
    return weapons.at(Randomizer::getRandom(weapons.size()));
}
