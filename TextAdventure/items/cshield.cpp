#include "cshield.h"
#include "cenemy.h"
#include "console.h"
#include "randomizer.h"

#include <algorithm>
#include <format>

CShield::CShield()
{
    _isConsumable = false;
    _isUsableFromBattle = false;
    _isUsableFromInventory = false;
    _isUsableUponDeath = false;

    _hasBattleEffect = true;
    _hasDurableBattleEffect = false;
    _hasShieldingAction = true;

    _name = "Shield";
    _description = "Am old worn-out, wooden shield, not very usefull, but better than nothing.";
}

void CShield::battleEffect(CEnemy*)
{
    Console::printLn("You raise your shield to protect you, but it does not loog trustworthy at all");
}

int CShield::shield(const unsigned int i)
{
    int shieldAmount = Randomizer::getRandom(_level + 1);
    if (shieldAmount == 0)
    {
        return i;
    }

    if (Randomizer::getRandom(100) <= _level * 10)
    {
        Console::printLn(std::format("Your shield absorbs {} damage", shieldAmount));
        return std::max(i - shieldAmount, 0U);
    }

    return i;
}
