#include "cenhancableitem.h"

CEnhancableItem::CEnhancableItem()
{
}

unsigned int CEnhancableItem::level() const
{
    return _level;
}

void CEnhancableItem::enhance()
{
    _level++;
}

std::function<bool(const CItem*)> CEnhancableItem::enhancableItemFilter()
{
    return [](const CItem* item) -> bool { return dynamic_cast<const CEnhancableItem*>(item) != nullptr; };
}
