#include "ressources.h"
#include "randomizer.h"

#include <algorithm>
#include <map>

std::string Ressources::Rooms::getRandomDescription()
{
    std::vector<std::string> _roomDescriptions = {
        "A Meadow. With grass. A lot of grass. It is green. Did i mention the grass? Oh, there is a sheep. Do you "
        "like sheep? I like sheep. There is one.",

        "A deep, dark Forest. Trees and Bushes around you. The ground is muddy and wet. Was that a fairy? Maybe a "
        "forest "
        "fairy? In this case, her name is probably \"Holla\".",

        "The shore of a lake. This is one big lake, so big, that it should be called \"Lake Enormous\". But it is just "
        "a "
        "lake. On second glance, not even a big one."};
    return _roomDescriptions.at(Randomizer::getRandom(_roomDescriptions.size()));
}

std::pair<std::string, std::string> Ressources::Items::getRandomRubbishItems()
{
    std::vector<std::pair<std::string, std::string>> items = {
        {{"A Stick"},
         {"A stick, just a stick. Maybe magical? There is no label stating \"Godly Magic Stick of the "
          "Whale\". On the "
          "other hand, there no label stating, that this stick is not a \"Godly Magic Stick of the Whale\"."}},
        {{"A Sock"},
         {"A single sock. A single dirty sock. Useless without the other one. Who on earth throws away a "
          "single Sock??"}},
        {{"A Rock"}, {"This is a good rock, so good, that it might be used in an epic \"Rock Paper Sicsors\" battle."}},
        {{"A Boot"},
         {"An old, single boot made from leather.Good, expensive leather. But is damaged and dirty. And it is just "
          "a single boot."}},
        {{"A Vase"},
         {"This is one beautiful vase. It will look nice on your table. or on a sideboard. you could fill it with "
          "flowers. Or you just throw it away, for somone else to find ist."}}

    };

    return items.at(Randomizer::getRandom(items.size()));
}

unsigned int Ressources::Config::getXpForLevel(const unsigned int level)
{
    static const std::vector<int> xpForLevel = {0, 300, 700, 1300, 2000, 4000, 8000, 14000, 20000};
    if (level < xpForLevel.size())
    {
        return xpForLevel.at(level);
    }
    return xpForLevel.at(xpForLevel.size() - 1);
}

std::string Ressources::Enemies::getRandomEnemyName()
{
    std::vector<std::string> names = {"Bob, the Cowboy", "angry Rat", "stinky Bat", "greedy Vulture", "huge Barbarian"};
    return names.at(Randomizer::getRandom(names.size()));
}

std::string Ressources::Enemies::getRandomEnemyWeapon()
{
    std::vector<std::string> weapons = {"shabby board with a rusty nail hammered through",
                                        "sharp teeth",
                                        "sheer muscle power",
                                        "a club with spikes",
                                        "a Nokia 3210"};
    return weapons.at(Randomizer::getRandom(weapons.size()));
}

std::pair<std::string, std::string> Ressources::Rooms::getRandomTown()
{
    std::vector<std::pair<std::string, std::string>> towns = {
        {"Hafnarfjodur", "The City of Elves. Built high in the treetops of ancient Trees"},
        {"Peridotspring", "Deep Caves, carved in huge mountains built this citiy of the dwarfs"},
        {"Wallachei", "An Oasis surrounded by a huge desert."},
        {"Bruchtal", "City of man, capital of the land."},
        {"Mudpool", "The Home of the trolls. Everything is dirty and stinky here."}};
    return towns.at(Randomizer::getRandom(towns.size()));
}

std::string Ressources::Companion::nameForCompanionType(const ECompanionType& tp, const unsigned int level)
{
    std::map<ECompanionType, std::vector<std::string>> companions = {
        {ECompanionType::eBird, {"Chick", "Sparrow", "Parrot", "Griffon", "Phoenix"}},
        {ECompanionType::eDog, {"Whelp", "Dog", "Wolf", "Ice wolf", "Cerberus"}},
        {ECompanionType::eCat, {"Kitten", "Cat", "Lynx", "Tiger", "Sphinx"}},
        {ECompanionType::eDragon,
         {"Baby Dragon", "Young Dragon", "Adult Dragon", "Old Dragon", "Ancient Hellfire Dragon"}}};

    return companions.at(tp).at(std::min(companionLevelCap, std::max(level, 1U)) - 1);
}

Ressources::Companion::ECompanionType Ressources::Companion::getRandomCompanionType()
{
    std::vector<ECompanionType> v;
    v.push_back(ECompanionType::eCat);
    v.push_back(ECompanionType::eCat);
    v.push_back(ECompanionType::eCat);
    v.push_back(ECompanionType::eCat);
    v.push_back(ECompanionType::eCat);

    v.push_back(ECompanionType::eDog);
    v.push_back(ECompanionType::eDog);
    v.push_back(ECompanionType::eDog);
    v.push_back(ECompanionType::eDog);
    v.push_back(ECompanionType::eDog);

    v.push_back(ECompanionType::eBird);
    v.push_back(ECompanionType::eBird);
    v.push_back(ECompanionType::eBird);

    v.push_back(ECompanionType::eDragon);

    std::shuffle(v.begin(), v.end(), Randomizer::getRandomEngine());
    return v.at(0);
}
