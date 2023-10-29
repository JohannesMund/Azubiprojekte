#include "citem.h"

using namespace std;

CItem::CItem()
{
}

bool CItem::isUsableFromInventory() const
{
    return _isUsableFromInventory;
}

bool CItem::isUsableFromBattle() const
{
    return _isUsableFromBattle;
}

bool CItem::isUsableUponDeath() const
{
    return _isUsableUponDeath;
}

bool CItem::hasBattleEffect() const
{
    return _hasBattleEffect;
}

bool CItem::hasDurableBattleEffect() const
{
    return _hasDurableBattleEffect;
}

bool CItem::isConsumable() const
{
    return _isConsumable;
}

string CItem::name() const
{
    return _name;
}

string CItem::description() const
{
    return _description;
}
