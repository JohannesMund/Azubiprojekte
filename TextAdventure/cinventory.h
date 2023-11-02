#pragma once

#include "citem.h"

#include <map>
#include <string>
#include <vector>

class CEnemy;
class CEnhancableItem;
class CInventory
{
public:
    using CompressedItem = std::pair<unsigned int, CItem*>;
    using CompressedItemMap = std::multimap<unsigned int, CItem*>;
    using ItemList = std::vector<CItem*>;
    using EnhancableItemList = std::vector<CEnhancableItem*>;

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

    void print(const Scope& scope = Scope::eNone);

    ItemList getItemsWithBattleEffect();
    void useBattleEffect(CItem* item, CEnemy* enemy);

    ItemList getItemsWithDurableBattleEffect();
    void useDurableBattleEffect(CItem* item, CEnemy* enemy, bool& endRound);

    ItemList getItemsWithShieldingAction();
    unsigned int useShieldingAction(CItem* item, const int damage);

    ItemList getItemsWithDeathEffect();
    void useDeathAction(CItem* item);

    EnhancableItemList getEnhancableItems();

    void printInventory(const Scope& scope);

private:
    std::string printInventoryNav() const;

    CompressedItemMap getInventoryCompressedForScope(const Scope& scope);

    static bool usableInScope(const CItem* item, const Scope& scope);

    void printUsableItems(const Scope& scope);
    void printViewableItems();

    void useItem(CItem* item, const Scope& scope);
    void viewItem(CItem* item);

    CItem* getItem(const unsigned int index);
    ItemList _inventory;
};
