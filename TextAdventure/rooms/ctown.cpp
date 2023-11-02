#include "ctown.h"
#include "cenhancableitem.h"
#include "cgamemanagement.h"
#include "cjunkitem.h"
#include "console.h"
#include "ressources.h"

#include <format>

CTown::CTown()
{
    auto town = Ressources::Rooms::getRandomTown();
    _name = town.first;
    _description = town.second;
}

void CTown::execute()
{

    char input;
    do
    {
        Console::printLn(_name, Console::EAlignment::eCenter);
        Console::br();
        CRoom::execute();
        Console::hr();
        Console::printLn("[B]lacksmith [C]hurch [T]avern [S]hop E[x]it");

        input = Console::getAcceptableInput("bctsx");
        if (input == 'b')
        {
            blacksmith();
        }
        if (input == 'c')
        {
            church();
        }
        if (input == 't')
        {
            tavern();
        }
        if (input == 's')
        {
            shop();
        }
    } while (input != 'x');
}

char CTown::mapSymbol()
{
    return 'T';
}

void CTown::blacksmith()
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

void CTown::enhanceItem()
{
    auto items = CGameManagement::getInventoryInstance()->getEnhancableItems();
    if (items.size() == 0)
    {
        Console::printLn("You look through your pockets and find no enhancable items.");
        return;
    }

    auto enhancementCostForItem = [](const CEnhancableItem* i) { return 150 + (i->level() * 150 * i->level() * 2); };

    int number = 0;
    std::vector<CEnhancableItem*> enhancableItems;
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
            Console::printLn(std::format("    {} ({}Gold)", i->name(), cost));
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

void CTown::church()
{
    char input;
    do
    {
        Console::cls();
        Console::printLn(std::format(
            "The church of {}. An old church, but nice and clean. The priest is an old, friedly man.", _name));
        Console::hr();
        Console::printLnWithSpacer("Get [B]lessing", "E[x]it");

        input = Console::getAcceptableInput("bx");

        if (input == 'b')
        {
            Console::printLn(
                "The priest chants his prayers and a godly light surrounds you. Your wounds close, your pain "
                "vanishes.");
            Console::printLn("You are fully healed.");
            CGameManagement::getPlayerInstance()->addHp(9999);
            Console::confirmToContinue();
        }

    } while (input != 'x');
}

void CTown::shop()
{
    char input;
    do
    {
        Console::cls();
        Console::printLn(
            std::format("The shop of {} looks like any shop in any generic D&D game. Even the cleric looks "
                        "stereotypical. The shop is filled with junk,but who knows, maybe you will find something cool "
                        "here? Or make some food money selling your precious valuables?",
                        _name));
        Console::hr();

        std::string nav;
        std::string acceptableInputs;

        auto junkItems = CGameManagement::getInventoryInstance()->getJunkItems();
        if (junkItems.size())
        {
            int value = 0;
            for (auto j : junkItems)
            {
                if (j->isSellable())
                {
                    value += j->value();
                }
            }
            nav.append(std::format("[S]ell your junk ({} Gold)", value));
            acceptableInputs.append("s");
        }

        Console::printLnWithSpacer(nav, "E[x]it");
        acceptableInputs.append("x");
        input = Console::getAcceptableInput(acceptableInputs);

        if (input == 's')
        {
            for (auto j : junkItems)
            {
                if (j->isSellable())
                {
                    CGameManagement::getPlayerInstance()->addGold(j->value());
                    CGameManagement::getInventoryInstance()->removeItem(j);
                }
            }
            Console::confirmToContinue();
        }

    } while (input != 'x');
}

void CTown::tavern()
{
}
