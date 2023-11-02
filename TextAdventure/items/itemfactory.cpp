#include "itemfactory.h"

#include "chealingpotion.h"
#include "cphoenixfeather.h"
#include "crubbishitem.h"
#include "cshield.h"
#include "csword.h"

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
    case EItemType::ePhoenixFeather:
        return new CPhoenixFeather();
    case EItemType::eSword:
        return new CSword();
    case EItemType::eShield:
        return new CShield();
    case EItemType::eRubbishItem:
        return new CRubbishItem();
    default:
        break;
    }
    return nullptr;
}
