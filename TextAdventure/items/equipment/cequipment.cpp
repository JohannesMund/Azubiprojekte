#include "cequipment.h"
#include "console.h"

#include <format>
CEquipment::CEquipment()
{
    _name = "";
}

bool CEquipment::isEnhancable() const
{
    return _level < _levelCap;
}

std::string CEquipment::name() const
{
    if (_namesByLevel.size() == 0)
    {
        return "something";
    }

    if (_level > _namesByLevel.size())
    {
        return _namesByLevel.at(_namesByLevel.size() - 1);
    }
    return _namesByLevel.at(_level);
}

unsigned int CEquipment::level() const
{
    return _level;
}

void CEquipment::enhance()
{
    if (!isEnhancable())
    {
        return;
    }

    _level++;
    Console::printLn(
        std::format("your {} has been upgraded to to a {}", _namesByLevel.at(_level - 1), _namesByLevel.at(_level)));
}

std::function<bool(const CItem*)> CEquipment::equipmentFilter()
{
    return [](const CItem* item) -> bool { return dynamic_cast<const CEquipment*>(item) != nullptr; };
}

std::function<bool(const CItem*)> CEquipment::enhancableEquipmentFilter()
{
    return [](const CItem* item) -> bool
    {
        auto equipment = dynamic_cast<const CEquipment*>(item);
        if (equipment == nullptr)
        {
            return false;
        }
        return equipment->isEnhancable();
    };
}
