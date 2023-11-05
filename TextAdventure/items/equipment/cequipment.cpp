#include "cequipment.h"

CEquipment::CEquipment()
{
}

unsigned int CEquipment::level() const
{
    return _level;
}

void CEquipment::enhance()
{
    _level++;
}

std::function<bool(const CItem*)> CEquipment::enhancableItemFilter()
{
    return [](const CItem* item) -> bool { return dynamic_cast<const CEquipment*>(item) != nullptr; };
}
