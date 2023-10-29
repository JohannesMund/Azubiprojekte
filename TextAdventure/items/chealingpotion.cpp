#include "chealingpotion.h"
#include "cgamemanagement.h"
#include "conio.h"
#include "cplayer.h"
#include "randomizer.h"
#include "ressources.h"

CHealingPotion::CHealingPotion(const PotionSize& size) : CItem()
{
    _name = "Potion of Healing";
    _description = "A fancy flask, made of glass with a shimmering, deep-red potion with shiny pink clouds inside. "
                   "Everything is moving magically, this MUST be a healing potion. Oh, and there is a lable stating "
                   "\"Potion of Healing\"";

    switch (size)
    {
    case PotionSize::S:
        _name = "Small " + _name;
        _description.append("\nThe bottle is tiny and not completely full.");
        break;
    case PotionSize::M:
    default:
        break;
    case PotionSize::L:
        _name = "Large " + _name;
        _description.append("\nThe bottle is pretty big.");
        break;
    case PotionSize::XL:
        _name = "Huge " + _name;
        _description.append("\nTHe bottle is huge, and filled to the brim.");

        break;
    }
    _size = size;
    _isConsumable = true;
    _isUsableFromInventory = true;
    _isUsableFromBattle = true;
}

void CHealingPotion::use()
{
    ConIO::printLn("You open the bottle, and swallow it in one draw. Healing potions are disgusting!");
    unsigned int hp;
    switch (_size)
    {
    case PotionSize::S:
        ConIO::printLn("Fortunately, it is not much, You feel a little refreshed!");
        hp = 1;
        break;
    case PotionSize::M:
    default:
        ConIO::printLn("What can you do? Down the neck! You feel very refreshed!");
        hp = Randomizer::getRandom(2) + 1;
        break;
    case PotionSize::L:
        ConIO::printLn("Sooo much potion! But it was worth it, you feel really very refreshed!");
        hp = Randomizer::getRandom(9) + 1;
        break;
    case PotionSize::XL:
        ConIO::printLn("You are flooded by a burst of life! you feel like a new born!");
        hp = 99999;
        break;
    }
    CGameManagement::getPlayerInstance()->addHp(hp);
}
