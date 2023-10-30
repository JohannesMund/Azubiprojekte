#include "cinventory.h"
#include "console.h"

#include <algorithm>
#include <format>
#include <string>
#include <utility>

CInventory::CInventory()
{
}

bool CInventory::hasItem(const std::string& name)
{
    return std::find_if(_inventory.begin(), _inventory.end(), CItem::nameFilter(name)) != _inventory.end();
}

void CInventory::addItem(CItem* item)
{
    _inventory.push_back(item);
}

void CInventory::removeItem(CItem* item)
{
    auto found = std::find_if(_inventory.begin(), _inventory.end(), CItem::nameFilter(item->name()));
    if (found != _inventory.end())
    {
        _inventory.erase(found);
    }
}

void CInventory::print(const Scope& scope)
{
    Console::printLn("You look through your backpack and find the following:");
    printInventory(scope);

    char input = ' ';
    while (input != 'x')
    {
        auto acceptableInputs = printInventoryNav();
        input = Console::getAcceptableInput(acceptableInputs);
        if (input == 'u')
        {
            printUsableItems(Scope::eInventory);
        }
        if (input == 'v')
        {
            printViewableItems();
        }
    }
}

void CInventory::printInventory(const Scope& scope)
{
    auto itemMap = getInventoryCompressedForScope(scope);

    std::vector<CItem*> usableItems;

    for (auto item : itemMap)
    {
        std::string s;
        if ((!usableInScope(item.second, scope)))
        {
            s = std::format("      {} (x{})", item.second->name(), item.first);
        }
        else
        {
            usableItems.push_back(item.second);
            s = std::format("[{:3}] {} (x{})", usableItems.size(), item.second->name(), item.first);
        }
        Console::printLn(s);
    }

    if (usableItems.size())
    {
        auto item = Console::getNumberInputWithEcho(1, usableItems.size());
        if (item.has_value())
        {
            if (scope == Scope::eView)
            {
                viewItem(usableItems.at(0));
            }
            else
            {
                useItem(usableItems.at(0));
            }
        }
    }
}

std::string CInventory::printInventoryNav() const
{
    Console::hr();
    Console::printLn("Inventory");
    Console::printLn("[U]se Item [V]iew Item E[x]it", Console::EAlignment::eRight);
    return "uvx";
}

CInventory::CompressedItemMap CInventory::getInventoryCompressedForScope(const Scope& scope)
{

    CompressedItemMap itemMap;
    for (auto item : _inventory)
    {
        if (!usableInScope(item, scope) && scope != Scope::eList)
        {
            continue;
        }

        auto foundItem = std::find_if(itemMap.begin(),
                                      itemMap.end(),
                                      [&item](const std::pair<unsigned int, CItem*>& p) -> bool
                                      { return p.second->name().compare(item->name()) == 0; });
        if (foundItem == itemMap.end())
        {
            auto count =
                std::count_if(_inventory.begin(),
                              _inventory.end(),
                              [&item](const CItem* it) -> bool { return it->name().compare(item->name()) == 0; });

            itemMap.insert(std::make_pair(count, item));
        }
    }
    return itemMap;
}

bool CInventory::usableInScope(const CItem* item, const Scope& scope)
{
    switch (scope)
    {
    case Scope::eNone:
    default:
    case Scope::eList:
        return false;
    case Scope::eView:
        return true;
    case Scope::eInventory:
        return item->isUsableFromInventory();
    case Scope::eBattle:
        return item->isUsableFromBattle();
    case Scope::eDeath:
        return item->isUsableUponDeath();
    }
}

void CInventory::printUsableItems(const Scope& scope)
{
    Console::printLn("Select item to use");
    Console::hr();
    printInventory(scope);
}

void CInventory::printViewableItems()
{
    Console::printLn("Select item to view");
    Console::hr();
    printInventory(Scope::eView);
}

void CInventory::useItem(CItem* item)
{
    if (item == nullptr)
    {
        return;
    }

    Console::hr();
    Console::printLn(std::format("You decide to use: {}", item->name()));
    item->use();
    if (item->isConsumable())
    {
        removeItem(item);
    }
}

void CInventory::viewItem(CItem* item)
{
    if (item == nullptr)
    {
        return;
    }
    Console::hr();
    Console::printLn(std::format("You decide to take a look at: {}", item->name()));
    Console::printLn(item->description());
}

CItem* CInventory::getItem(const unsigned int index)
{
    if (_inventory.size() < index)
    {
        return nullptr;
    }
    return _inventory.at(index);
}
