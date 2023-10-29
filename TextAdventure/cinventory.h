#pragma once

#include "citem.h"

#include <string>
#include <vector>

class CInventory
{
public:
    CInventory();

    enum class Scope
    {
        eNone,
        eView,
        eInventory,
        eBattle,
        eDeath
    };

    bool hasItem(const std::string& name);
    void addItem(CItem* item);
    void removeItem(CItem* item);

    void print(const Scope& scope = Scope::eNone);

private:
    void printInventory(const Scope& scope);
    std::string printInventoryNav() const;

    static bool usableInScope(const CItem* item, const Scope& scope);

    void printUsableItems(const Scope& scope);
    void printViewableItems();

    void useItem(CItem* item);
    void viewItem(CItem* item);

    CItem* getItem(const unsigned int index);

    std::vector<CItem*> _inventory;
};
