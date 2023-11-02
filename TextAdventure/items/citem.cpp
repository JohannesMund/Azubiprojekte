#include "citem.h"
#include "console.h"

#include <format>

using namespace std;

CItem::CItem()
{
}

void CItem::view()
{
    Console::printLn(format("You decide to take a look at: {}", _name));
    Console::printLn(_description);
    Console::hr();
}

bool CItem::isUsableFromInventory() const
{
    return _isUsableFromInventory;
}

bool CItem::isUsableFromBattle() const
{
    return _isUsableFromBattle;
}

bool CItem::hasDeathEffect() const
{
    return _hasDeathEffect;
}

bool CItem::hasBattleEffect() const
{
    return _hasBattleEffect;
}

bool CItem::hasDurableBattleEffect() const
{
    return _hasDurableBattleEffect;
}

bool CItem::hasShieldingAction() const
{
    return _hasShieldingAction;
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
