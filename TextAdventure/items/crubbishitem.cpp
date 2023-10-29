#include "crubbishitem.h"
#include "ressources.h"

CRubbishItem::CRubbishItem() : CItem()
{
    _isConsumable = false;
    _isUsableFromBattle = false;
    _isUsableFromInventory = false;
    _isUsableUponDeath = false;

    _hasBattleEffect = false;
    _hasDurableBattleEffect = false;

    auto it = Ressources::Items::getRandomRubbishItems();
    _name = it.first;
    _description = it.second;
}
