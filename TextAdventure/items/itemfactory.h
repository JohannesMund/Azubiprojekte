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

    eRubbishItem
};

CItem* makeItem(const EItemType tp);

} // namespace ItemFactory
