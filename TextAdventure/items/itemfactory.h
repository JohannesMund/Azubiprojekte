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

    eRubbishItem
};

CItem* makeItem(const EItemType tp);

} // namespace ItemFactory
