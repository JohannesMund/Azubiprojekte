#include "crubbishitem.h"
#include "ressources.h"

CRubbishItem::CRubbishItem() : CItem()
{
    auto it = Ressources::Items::getRandomRubbishItems();
    _name = it.first;
    _description = it.second;
}
