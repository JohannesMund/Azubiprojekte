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
    eHeartContainer,

    eJunkItem,

    eUrzasGlasses
};

CItem* makeItem(const EItemType tp);
CItem* makeShopItem();
CItem* makeAwesomneItem();

} // namespace ItemFactory
