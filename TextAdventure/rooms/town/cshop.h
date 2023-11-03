#pragma once

#include "cinventory.h"

#include <vector>

class CItem;
class CShop
{
public:
    CShop();

    void execute();
    void setCityName(const std::string& s);

private:
    void sellJunk(CInventory::JunkItemList& junkItems);
    void buyItems();
    void sellItems();
    void buyItem(CItem* item);
    void sellItem(CItem* item);

    void replaceShopItems();
    std::vector<CItem*> _shopItems;
    std::string _cityName;

    unsigned int _playerLevel;
};
