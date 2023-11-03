#include "itemfactory.h"

#include "chealingpotion.h"

#include "cheartcontainer.h"
#include "cjunkitem.h"
#include "cphoenixfeather.h"
#include "cshield.h"
#include "csword.h"
#include "randomizer.h"
#include <algorithm>
#include <vector>

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
    case EItemType::eHeartContainer:
        return new CHeartContainer;
    case EItemType::eSword:
        return new CSword();
    case EItemType::eShield:
        return new CShield();
    case EItemType::eJunkItem:
        return new CJunkItem();
    default:
        break;
    }
    return nullptr;
}

CItem* ItemFactory::makeShopItem()
{
    std::vector<EItemType> items = {
        EItemType::eHealingPotionS,  EItemType::eHealingPotionS, EItemType::eHealingPotionS, EItemType::eHealingPotionS,
        EItemType::eHealingPotionS,  EItemType::eHealingPotionS, EItemType::eHealingPotionS, EItemType::eHealingPotionS,
        EItemType::eHealingPotionS,  EItemType::eHealingPotionS,

        EItemType::eHealingPotionM,  EItemType::eHealingPotionM, EItemType::eHealingPotionM, EItemType::eHealingPotionM,
        EItemType::eHealingPotionM,

        EItemType::eHealingPotionL,  EItemType::eHealingPotionL, EItemType::eHealingPotionL,

        EItemType::eHealingPotionXL, EItemType::eHeartContainer, EItemType::ePhoenixFeather};

  std::shuffle(items.begin(), items.end(), std::default_random_engine(Randomizer::getRandomEngineSeed()));

    return makeItem(items.at(0));
}
