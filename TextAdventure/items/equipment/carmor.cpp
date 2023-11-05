#include "carmor.h"

CArmor::CArmor()
{
    _hasBattleEffect = true;
    _hasShieldingAction = true;
}

std::function<bool(const CItem*)> CArmor::armorFilter()
{
    return [](const CItem* item) -> bool { return dynamic_cast<const CArmor*>(item) != nullptr; };
}
