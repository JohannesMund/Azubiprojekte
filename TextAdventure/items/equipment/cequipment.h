#pragma once

#include <citem.h>

#include <string>
#include <vector>

class CEquipment : public CItem
{
public:
    CEquipment();

    virtual bool isEnhancable() const;
    virtual std::string name() const override;
    virtual std::string typeName() const = 0;

    virtual unsigned int level() const;
    virtual void enhance();

    /**
     * @brief equipmentFiler
     * @return a filter function to filter equipment items from std containers
     */
    static std::function<bool(const CItem*)> equipmentFilter();
    static bool isEquipment(const CItem* item);

    /**
     * @brief enhancableEquipmentFilter
     * @return a filter function to filter equipment items that can be enhanced from std containers
     */
    static std::function<bool(const CItem*)> enhancableEquipmentFilter();

    virtual std::function<bool(const CItem*)> equipmentTypeFilter() const = 0;

protected:
    bool doesEquipmentEffectFire() const;

    int _level = 0;
    std::vector<std::string> _namesByLevel;
    int _levelCap = 0;
};
