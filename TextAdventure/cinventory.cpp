#include "cinventory.h"
#include "conio.h"

#include <algorithm>
#include <format>
#include <map>
#include <string>
#include <utility>

CInventory::CInventory()
{
}

bool CInventory::hasItem(const std::string& name)
{
    auto itemFinder = [&name](const CItem* item) { return item->name().compare(name) == 0; };
    return std::find_if(_inventory.begin(), _inventory.end(), itemFinder) != _inventory.end();
}

void CInventory::addItem(CItem* item)
{
    _inventory.push_back(item);
}

void CInventory::removeItem(CItem* item)
{
    auto itemFinder = [item](const CItem* it) { return it->name().compare(item->name()) == 0; };
    auto found = std::find_if(_inventory.begin(), _inventory.end(), itemFinder);
    if (found != _inventory.end())
    {
        _inventory.erase(found);
    }
}

void CInventory::print(const Scope& scope)
{
    ConIO::printLn("You look through your backpack and find the following:");
    printInventory(scope);

    char input = ' ';
    while (input != 'x')
    {
        auto acceptableInputs = printInventoryNav();
        input = ConIO::getAcceptableInput(acceptableInputs);
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
    std::multimap<unsigned int, CItem*> itemMap;

    for (auto item : _inventory)
    {
        if (!usableInScope(item, scope))
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

    std::vector<CItem*> usableItems;

    for (auto item : itemMap)
    {
        std::string s;

        if ((!usableInScope(item.second, scope) && scope != Scope::eView) || scope == Scope::eNone)
        {
            s = std::format("      {} (x{})", item.second->name(), item.first);
        }
        else
        {
            usableItems.push_back(item.second);
            s = std::format("[{:3}] {} (x{})", usableItems.size(), item.second->name(), item.first);
        }
        ConIO::printLn(s);
    }

    if (usableItems.size())
    {
        auto item = ConIO::getNumberInputWithEcho(1, usableItems.size());
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
    ConIO::printLn("[U]se Item [V]iew Item E[x]it", ConIO::EAlignment::eRight);
    return "uvx";
}

bool CInventory::usableInScope(const CItem* item, const Scope& scope)
{
    switch (scope)
    {
    case Scope::eNone:
    default:
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
    ConIO::printLn("Select item to use");
    ConIO::hr();
    printInventory(scope);
}

void CInventory::printViewableItems()
{
    ConIO::printLn("Select item to view");
    ConIO::hr();
    printInventory(Scope::eView);
}

void CInventory::useItem(CItem* item)
{
    if (item == nullptr)
    {
        return;
    }

    ConIO::hr();
    ConIO::printLn(std::format("You decide to use: {}", item->name()));
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
    ConIO::hr();
    ConIO::printLn(std::format("You decide to take a look at: {}", item->name()));
    ConIO::printLn(item->description());
}

CItem* CInventory::getItem(const unsigned int index)
{
    if (_inventory.size() < index)
    {
        return nullptr;
    }
    return _inventory.at(index);
}
