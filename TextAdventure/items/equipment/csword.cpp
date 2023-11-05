#include "csword.h"

CSword::CSword() : CEquipment()
{
    _hasBattleEffect = true;
    _hasBattleBuff = true;
}

std::function<bool(const CItem*)> CSword::swordFilter()
{
    return [](const CItem* item) -> bool { return dynamic_cast<const CSword*>(item) != nullptr; };
}
