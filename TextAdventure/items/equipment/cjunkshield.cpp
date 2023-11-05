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

int CJunkShield::shield(const unsigned int i)
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
