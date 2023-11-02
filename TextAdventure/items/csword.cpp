#include "csword.h"
#include "cenemy.h"
#include "console.h"

#include <format>
#include <string>
CSword::CSword()
{
    _isConsumable = false;
    _isUsableFromBattle = false;
    _isUsableFromInventory = false;
    _hasDeathEffect = false;

    _hasBattleEffect = true;
    _hasDurableBattleEffect = true;
    _hasShieldingAction = false;

    _name = "Sword";
    _description = "Am old worn-out, wooden sword. Used for training... Used for training often...";
}
void CSword::battleEffect(CEnemy* enemy)
{
    if (_level < 1)
    {
        Console::printLn(std::format(
            "You draw your sword at {} and try to look dangerous. The sword is not helpful at all.", enemy->name()));
    }
}

void CSword::durableBattleEffect(CEnemy* enemy)
{
}
