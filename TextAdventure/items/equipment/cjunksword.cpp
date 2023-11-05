#include "cjunksword.h"
#include "cenemy.h"
#include "console.h"

#include <format>
#include <string>

CJunkSword::CJunkSword() : CSword()
{
    _levelCap = 5;
    _namesByLevel = {
        "Stick, shaped like a sword", "Sword, shaped like a stick", "Wooden Sword", "Training Sword", "Sword"};
    _description = "A stick, shaped like a sword. Or a sword, shaped like a stick? It is a sword-stick";
}

void CJunkSword::battleEffect(CEnemy* enemy)
{
}

void CJunkSword::battleBuff(CEnemy* enemy, bool& endRound)
{
    if (_level < 1)
    {
        Console::printLn(std::format(
            "You draw your sword at {} and try to look dangerous. The sword is not helpful at all.", enemy->name()));
    }
}
