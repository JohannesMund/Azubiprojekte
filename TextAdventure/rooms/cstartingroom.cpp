#include "cstartingroom.h"
#include "cgamemanagement.h"
#include "console.h"
#include "itemfactory.h"

CStartingRoom::CStartingRoom()
{
    _encounterPossible = false;
}

void CStartingRoom::execute()
{
    if (seen())
    {
        CRoom::execute();
        Console::printLn("You can still see, where you woke up, when you started your adventure,");
        return;
    }
    CRoom::execute();

    Console::printLn("You look around, and realize, that you are utterly defenseless. You need something to defend "
                     "yourself. Hidden beneath one of the bushes, you see a stick shaped like a sword. Or a sword "
                     "shaped like a stick. This should do.");

    char input;
    do
    {
        Console::printLn("[T]ake it [L]eave it");
        input = Console::getAcceptableInput("tl");
        if (input == 't')
        {
            Console::printLn("You take the sword and equip ist. It looks good on you.");
            CGameManagement::getInventoryInstance()->addItem(ItemFactory::makeItem(ItemFactory::EItemType::eSword));
        }
        else
        {
            Console::printLn("Your parents always taught you, not to pick up stuff from the ground. Who knows wo owns "
                             "this sword. You leave the Sword where it is and turn around.");
            Console::printLn(
                "Than you start thinking. You are still defenseless. Maybe you should re-think your decision.");
        }
    } while (input != 't');

    Console::printLn("Having the sword, you look further. You still does not feel like a big, sturdy warrior. "
                     "Something is missing.");
    Console::printLn("Wait, is that...?");
    Console::printLn("You see an old, damaged buckler. It is dirty, it is worn out and it has seen a lot of fights, "
                     "but is should still work.");

    do
    {
        Console::printLn("[T]ake it [L]eave it");
        input = Console::getAcceptableInput("tl");
        if (input == 't')
        {
            Console::printLn("You take the shield and equip ist. Now it feels complete.");
            CGameManagement::getInventoryInstance()->addItem(ItemFactory::makeItem(ItemFactory::EItemType::eShield));
        }
        else
        {
            Console::printLn("Ok, by now, you should have realized, that you will not leave without the shield. Let's "
                             "shorten this, ok?");
        }
    } while (input != 't');
    _encounterPossible = true;
}

char CStartingRoom::mapSymbol()
{
    return '*';
}
