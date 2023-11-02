#include "cshield.h"
#include "cenemy.h"
#include "console.h"
#include "randomizer.h"

#include <algorithm>
#include <format>

CShield::CShield()
{
    _hasBattleEffect = true;
    _hasShieldingAction = true;

    _name = "Old buckler";
    _description = "Am old worn-out, wooden shield, not very usefull, but better than nothing.";
}

void CShield::enhance()
{
    auto oldName = _name;
    CEnhancableItem::enhance();
    if (_level == 1)
    {
        _name = "Repaired buckler";
        _description = "Still an old, worn-out wooden shield, but now repaired and a little more usefull";
    }
    Console::printLn(std::format("Your {} is now a {}", oldName, _name));
}

void CShield::battleEffect(CEnemy*)
{
    if (_level < 1)
    {
        Console::printLn("You raise your shield to protect you, but it does not look trustworthy at all");
    }
    else
    {
        Console::printLn("You raise your shield to protect you.");
    }
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
