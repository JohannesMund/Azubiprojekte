#pragma once

#include "citem.h"

namespace ItemFactory
{
enum class EItemType
{
    eHealingPotionS,
    eHealingPotionM,
    eHealingPotionL,
    eHealingPotionXL,

    ePhoenixFeather,

    eSword,
    eShield,

    eJunkItem
};

CItem* makeItem(const EItemType tp);
CItem* makeShopItem();

} // namespace ItemFactory
