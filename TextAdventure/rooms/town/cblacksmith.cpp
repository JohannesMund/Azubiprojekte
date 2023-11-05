#include "cblacksmith.h"
#include "cequipment.h"
#include "cgamemanagement.h"
#include "console.h"

#include <format>

CBlackSmith::CBlackSmith()
{
}

void CBlackSmith::execute()
{
    char input;
    do
    {
        Console::cls();
        Console::printLn(
            "The Blacksmith in town. It is hot, it is dirty, the sound of a hammer hitting an anvil fills the air.");
        Console::printLn(
            "A grumpy old man, probably the blacksmith looks at you suspiciously and asks what he can do for you.");
        Console::hr();
        Console::printLnWithSpacer("[E]nhance Item", "E[x]it");

        input = Console::getAcceptableInput("ex");

        if (input == 'e')
        {
            enhanceItem();
        }

    } while (input != 'x');
}

void CBlackSmith::enhanceItem()
{
    auto items = CGameManagement::getInventoryInstance()->getEnhancableItems();
    if (items.size() == 0)
    {
        Console::printLn("You look through your pockets and find no enhancable items.");
        return;
    }

    auto enhancementCostForItem = [](const CEquipment* i) { return 150 + (i->level() * 150 * i->level() * 2); };

    int number = 0;
    std::vector<CEquipment*> enhancableItems;
    Console::printLn("You look through your pockets and find the following items, that can be enhanced:");
    for (auto i : items)
    {
        auto cost = enhancementCostForItem(i);

        if (cost <= CGameManagement::getPlayerInstance()->gold())
        {
            number++;
            enhancableItems.push_back(i);
            Console::printLn(std::format("[{:3}] {} ({}Gold)", number, i->name(), cost));
        }
        else
        {
            Console::printLn(std::format("[   ] {} ({}Gold)", i->name(), cost));
        }
    }

    if (enhancableItems.size() > 0)
    {
        auto idx = Console::getNumberInputWithEcho(1, number);

        if (idx.has_value())
        {
            auto item = enhancableItems.at(*idx - 1);
            auto cost = enhancementCostForItem(item);
            item->enhance();
            CGameManagement::getPlayerInstance()->addGold(cost * -1);
        }
    }
    Console::confirmToContinue();
}
