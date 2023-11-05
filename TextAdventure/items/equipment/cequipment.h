#pragma once

#include <citem.h>

class CEquipment : public CItem
{
public:
    CEquipment();

    virtual unsigned int level() const;
    virtual void enhance();

    /**
     * @brief enhancableItemFilter
     * @return a filter function to filter enhancable items from std containers
     */
    static std::function<bool(const CItem*)> enhancableItemFilter();

protected:
    int _level = 0;
};
