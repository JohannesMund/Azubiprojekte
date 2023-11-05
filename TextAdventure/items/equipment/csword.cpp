#include "csword.h"
#include "cenemy.h"
#include "console.h"

#include <format>
#include <string>
CSword::CSword()
{
    _hasBattleEffect = true;
    _hasDurableBattleEffect = true;

    _name = "Stick, shaped like a sword";
    _description = "A stick, shaped like a sword. Or a sword, shaped like a stick? It is a sword-stick";
}

void CSword::enhance()
{
    auto oldName = _name;
    CEquipment::enhance();
    if (_level == 1)
    {
        _name = "wooden Sword";
        _description = "Am old worn-out, wooden sword. Used for training... Used for training often...";
    }
    Console::printLn(std::format("Your {} is now a {}", oldName, _name));
}
void CSword::battleEffect(CEnemy* enemy)
{
    if (_level < 1)
    {
        Console::printLn(std::format(
            "You draw your sword at {} and try to look dangerous. The sword is not helpful at all.", enemy->name()));
    }
}

void CSword::battleBuff(CEnemy* enemy, bool& endRound)
{
}
