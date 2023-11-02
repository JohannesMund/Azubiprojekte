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
