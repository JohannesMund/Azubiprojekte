#pragma once

#include "citem.h"

#include <map>
#include <string>
#include <vector>

class CEnemy;
class CEnhancableItem;
class CJunkItem;
class CInventory
{
public:
    using CompressedItem = std::pair<unsigned int, CItem*>;
    using CompressedItemMap = std::vector<CompressedItem>;
    using ItemList = std::vector<CItem*>;
    using EnhancableItemList = std::vector<CEnhancableItem*>;
    using JunkItemList = std::vector<CJunkItem*>;

    CInventory();

    enum class Scope
    {
        eNone,
        eView,
        eList,
        eInventory,
        eBattle,
        eDeath
    };

    bool hasItem(const std::string& name);
    void addItem(CItem* item);

    void removeItem(CItem* item);
    void removeItem(const std::string& name);

    void print(const Scope& scope = Scope::eNone);

    ItemList getItemsWithBattleEffect() const;
    void useBattleEffect(CItem* item, CEnemy* enemy);

    ItemList getItemsWithDurableBattleEffect() const;
    void useDurableBattleEffect(CItem* item, CEnemy* enemy, bool& endRound);

    ItemList getItemsWithShieldingAction() const;
    unsigned int useShieldingAction(CItem* item, const int damage);

    ItemList getItemsWithDeathEffect() const;
    void useDeathAction(CItem* item);

    JunkItemList getJunkItems() const;
    EnhancableItemList getEnhancableItems() const;

    CompressedItemMap getSellableItems() const;

    void printInventory(const Scope& scope);

private:
    std::string printInventoryNav() const;

    CompressedItemMap getCompressedItemMap(std::function<bool(const CItem*)> filter) const;
    CompressedItemMap getInventoryCompressedForScope(const Scope& scope) const;

    static bool usableInScope(const CItem* item, const Scope& scope);

    void printUsableItems(const Scope& scope);
    void printViewableItems();

    void useItem(CItem* item, const Scope& scope);
    void viewItem(CItem* item);

    CItem* getItem(const unsigned int index);
    ItemList _inventory;
};
