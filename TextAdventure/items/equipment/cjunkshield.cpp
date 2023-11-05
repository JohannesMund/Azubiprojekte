#include "cjunkshield.h"
#include "cenemy.h"
#include "console.h"
#include "randomizer.h"

#include <algorithm>
#include <format>

CJunkShield::CJunkShield() : CShield()
{

    _levelCap = 5;
    _namesByLevel = {"Old Buckler", "Repaired Buckler", "Wooden Buckler", "Robust Buckler", "Great Buckler"};
    _description = "A round, savage shield.";
}

void CJunkShield::battleEffect(CEnemy* enemy)
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

void CJunkShield::battleBuff(CEnemy* enemy, bool& endRound)
{
    if (doesEquipmentEffectFire())
    {
        Console::printLn("Your shield protects you from the enemy attack");
        enemy->dealDamage(1);
        endRound = true;
    }
}
