#include "cjunksword.h"
#include "cenemy.h"
#include "console.h"

#include <format>
#include <string>

CJunkSword::CJunkSword() : CSword()
{
    _name = "Stick, shaped like a sword";
    _description = "A stick, shaped like a sword. Or a sword, shaped like a stick? It is a sword-stick";
}

void CJunkSword::enhance()
{
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
