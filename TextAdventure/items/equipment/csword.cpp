#include "csword.h"

CSword::CSword()
{
    _hasBattleEffect = true;
    _hasDurableBattleEffect = true;
}

std::function<bool(const CItem*)> CSword::swordFilter()
{
    return [](const CItem* item) -> bool { return dynamic_cast<const CSword*>(item) != nullptr; };
}
