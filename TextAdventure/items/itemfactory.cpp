#include "itemfactory.h"

#include "chealingpotion.h"
#include "crubbishitem.h"

CItem* ItemFactory::makeItem(const EItemType tp)
{
    switch (tp)
    {
    case EItemType::eHealingPotionS:
        return new CHealingPotion(CHealingPotion::PotionSize::S);
    case EItemType::eHealingPotionM:
        return new CHealingPotion(CHealingPotion::PotionSize::M);
    case EItemType::eHealingPotionL:
        return new CHealingPotion(CHealingPotion::PotionSize::L);
    case EItemType::eHealingPotionXL:
        return new CHealingPotion(CHealingPotion::PotionSize::XL);
    case EItemType::eRubbishItem:
        return new CRubbishItem();
    default:
        break;
    }
    return nullptr;
}
