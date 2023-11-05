#include "cmysteriouschest.h"
#include "cgamemanagement.h"
#include "clivingchest.h"
#include "console.h"
#include "itemfactory.h"
#include "randomizer.h"

CMysteriousChest::CMysteriousChest() : CEncounter()
{
    _isSingleExecution = false;
}

void CMysteriousChest::execute()
{
    CEncounter::execute();
    _hasBeenExecuted = true;

    Console::printLn(
        "Wandering through the lands, you see a mysterious chest, standing there. It does not make any sense to put a "
        "chest there. It is rather odd, to see a chest at this place. This could be a trap!");
    Console::printLn("But after all, this is a chest. we should open it!");

    Console::br();
    Console::printLnWithSpacer("[O]pen the Chest", "[G]o away");
    char input = Console::getAcceptableInput("og");

    Console::br();
    if (input == 'g')
    {
        Console::printLn(
            "This chest does not belong there, and you should not open it. You here the cackle of a chicken from far.");
        return;
    }

    Console::printLn("This is too tempting. You go over to the chest and open it.");

    int goodStuffBonus = 0;
    if (Randomizer::getRandom(3) == 0)
    {
        Console::printLn("just to realize, that this was a mistake! This is a living chest, and it attacks you!");

        CLivingChest* chest = new CLivingChest();
        CBattle battle(chest);
        battle.fight();

        if (CGameManagement::getPlayerInstance()->isDead())
        {
            return;
        }
        if (!chest->isDead())
        {
            Console::printLn("You manage to escape. This was one scary monster!");
            return;
        }
        goodStuffBonus += 2;
    }

    auto reward = Randomizer::getRandom(10) + goodStuffBonus;
    unsigned int gold = CGameManagement::getPlayerInstance()->level() * 750;

    if (reward >= 10)
    {
        Console::printLn("Jackpot ---TBD---");
    }
    if (reward >= 7)
    {
        gold -= CGameManagement::getPlayerInstance()->level() * 250;
        CGameManagement::getInventoryInstance()->addItem(ItemFactory::makeShopItem());
        if (Randomizer::getRandom(2) == 0)
        {
            CGameManagement::getInventoryInstance()->addItem(ItemFactory::makeShopItem());
        }
    }
    if (reward >= 5)
    {
        CGameManagement::getInventoryInstance()->addItem(ItemFactory::makeShopItem());
    }
    CGameManagement::getPlayerInstance()->addGold(gold);
}

unsigned int CMysteriousChest::encounterChance() const
{
    return 1;
}

std::string CMysteriousChest::name() const
{
    return "Myterious Chest";
}
