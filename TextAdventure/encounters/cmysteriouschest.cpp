#include "cmysteriouschest.h"
#include "cgamemanagement.h"
#include "clivingchest.h"
#include "cmenu.h"
#include "console.h"
#include "itemfactory.h"
#include "randomizer.h"

CMysteriousChest::CMysteriousChest() : CEncounter()
{
    _isSingleExecution = false;
    _type = CEncounter::eField;
}

void CMysteriousChest::execute(const std::string& moduleName)
{
    CEncounter::execute();
    _hasBeenExecuted = true;

    Console::printLn(
        "Wandering through the lands, you see a mysterious chest, standing there. It does not make any sense to put a "
        "chest there. It is rather odd, to see a chest at this place. This could be a trap!");
    Console::printLn("But after all, this is a chest. we should open it!");

    CMenu menu;
    menu.addMenuGroup({menu.createAction("Open the chest")}, {menu.createAction("Go away")});

    if (menu.execute().key == 'g')
    {
        Console::br();
        Console::printLn(
            "This chest does not belong there, and you should not open it. You here the cackle of a chicken from far.");
        return;
    }

    Console::br();
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

    auto reward = Randomizer::getRandom(15) + goodStuffBonus;
    unsigned int gold = CGameManagement::getPlayerInstance()->level() * 750;

    if (reward >= 15)
    {
        CGameManagement::getInventoryInstance()->addItem(ItemFactory::makeAwesomneItem());
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

unsigned int CMysteriousChest::encounterChance(const EEncounterType& tp) const
{
    if (!canBeExecuted(tp))
    {
        return 0;
    }
    return 3;
}

std::string CMysteriousChest::name() const
{
    return "Myterious Chest";
}
