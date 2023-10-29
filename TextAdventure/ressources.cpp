#include "ressources.h"
#include "randomizer.h"

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
    std::vector<std::pair<std::string, std::string>> _items = {
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

    return _items.at(Randomizer::getRandom(_items.size()));
}
