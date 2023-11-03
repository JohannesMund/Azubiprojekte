#include "cinventory.h"
#include "cenhancableitem.h"
#include "cjunkitem.h"
#include "console.h"

#include <algorithm>
#include <format>
#include <ranges>
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
    Console::printLn(std::format("You optained {}", item->name()));
    _inventory.push_back(item);
}

void CInventory::removeItem(CItem* item)
{
    removeItem(item->name());
}
void CInventory::removeItem(const std::string& name)
{
    auto found = std::find_if(_inventory.begin(), _inventory.end(), CItem::nameFilter(name));
    if (found != _inventory.end())
    {
        delete *found;
        _inventory.erase(found);
    }
}

void CInventory::print(const Scope& scope)
{
    Console::printLn("You look through your backpack and find the following:");
    printInventory(scope);

    char input;
    do
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
    } while (input != 'x');
}

CInventory::ItemList CInventory::getItemsWithBattleEffect() const
{
    ItemList itemsWithBattleEffect;
    std::copy_if(
        _inventory.begin(), _inventory.end(), std::back_inserter(itemsWithBattleEffect), CItem::battleEffectFilter());
    return itemsWithBattleEffect;
}

void CInventory::useBattleEffect(CItem* item, CEnemy* enemy)
{
    if (item == nullptr)
    {
        return;
    }
    item->battleEffect(enemy);
    if (item->isConsumable())
    {
        removeItem(item);
    }
}

CInventory::ItemList CInventory::getItemsWithDurableBattleEffect() const
{
    ItemList itemsWithBattleEffect;
    std::copy_if(_inventory.begin(),
                 _inventory.end(),
                 std::back_inserter(itemsWithBattleEffect),
                 CItem::durableBattleEffectFilter());
    return itemsWithBattleEffect;
}

void CInventory::useDurableBattleEffect(CItem* item, CEnemy* enemy, bool& endRound)
{
    if (item == nullptr)
    {
        return;
    }

    item->battleBuff(enemy, endRound);
    if (item->isConsumable())
    {
        removeItem(item);
    }
}

CInventory::ItemList CInventory::getItemsWithShieldingAction() const
{
    ItemList itemsWithShieldingAction;
    std::copy_if(_inventory.begin(),
                 _inventory.end(),
                 std::back_inserter(itemsWithShieldingAction),
                 CItem::shieldingActionFilter());
    return itemsWithShieldingAction;
}

unsigned int CInventory::useShieldingAction(CItem* item, const int damage)
{
    if (item == nullptr)
    {
        return damage;
    }
    return item->shield(damage);
}

CInventory::ItemList CInventory::getItemsWithDeathEffect() const
{
    ItemList itemsWithDeathEffect;
    std::copy_if(
        _inventory.begin(), _inventory.end(), std::back_inserter(itemsWithDeathEffect), CItem::deathEffectFilter());
    return itemsWithDeathEffect;
}

void CInventory::useDeathAction(CItem* item)
{
    if (item == nullptr)
    {
        return;
    }
    item->deathEffect();
    if (item->isConsumable())
    {
        removeItem(item);
    }
}

CInventory::JunkItemList CInventory::getJunkItems() const
{
    JunkItemList junkItems;
    for (const auto item : _inventory | std::views::filter(CJunkItem::junkItemFilter()))
    {
        auto junkItem = dynamic_cast<CJunkItem*>(item);
        if (junkItem != nullptr)
        {
            junkItems.push_back(junkItem);
        }
    }

    return junkItems;
}

CInventory::EnhancableItemList CInventory::getEnhancableItems() const
{
    EnhancableItemList enhancableItems;
    for (const auto item : _inventory | std::views::filter(CEnhancableItem::enhancableItemFilter()))
    {
        auto enhancableItem = dynamic_cast<CEnhancableItem*>(item);
        if (enhancableItem != nullptr)
        {
            enhancableItems.push_back(enhancableItem);
        }
    }
    return enhancableItems;
}

CInventory::CompressedItemMap CInventory::getSellableItems() const
{
    return getCompressedItemMap([](const CItem* item) { return item->isSellable(); });
}

CInventory::CompressedItemMap CInventory::getInventoryCompressedForScope(const Scope& scope) const
{
    return getCompressedItemMap([&scope](const CItem* item)
                                { return usableInScope(item, scope) || scope == Scope::eList; });
}

CInventory::CompressedItemMap CInventory::getCompressedItemMap(std::function<bool(const CItem*)> filter) const
{
    CompressedItemMap itemMap;
    for (auto item : _inventory)
    {
        if (!filter(item))
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

            itemMap.push_back(std::make_pair(count, item));
        }
    }
    return itemMap;
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
                viewItem(usableItems.at(*item - 1));
            }
            else
            {
                useItem(usableItems.at(*item - 1), scope);
            }
        }
    }
}

std::string CInventory::printInventoryNav() const
{
    Console::hr();
    Console::printLn("[U]se Item [V]iew Item", Console::EAlignment::eRight);
    Console::printLn("E[x]it Inventory", Console::EAlignment::eRight);
    return "uvx";
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
        return item->hasDeathEffect();
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

void CInventory::useItem(CItem* item, const Scope& scope)
{
    if (item == nullptr)
    {
        return;
    }

    if (scope != Scope::eInventory && scope != Scope::eBattle)
    {
        return;
    }

    Console::hr();
    Console::printLn(std::format("You decide to use: {}", item->name()));

    if (scope == Scope::eInventory)
    {
        item->useFromInventory();
    }
    if (scope == Scope::eBattle)
    {
        item->useFromBattle();
    }

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
    item->view();
}

CItem* CInventory::getItem(const unsigned int index)
{
    if (_inventory.size() < index)
    {
        return nullptr;
    }
    return _inventory.at(index);
}
