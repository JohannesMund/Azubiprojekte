#ifndef CITEM_H
#define CITEM_H

#include <functional>
#include <string>

class CEnemy;

/**
 * @brief The CItem class
 * Represents one Item. Virtual, Must be derived for full power
 */
class CItem
{
public:
    /**
     * @brief CItem
     * Constructor
     */
    CItem();

    /**
     * @brief use
     * Default items have no power. Needs to be overwritten to un-junk the item
     */
    virtual void useFromInventory()
    {
    }

    virtual void battleEffect(CEnemy*)
    {
    }

    virtual void durableBattleEffect(CEnemy*)
    {
    }

    virtual void view();

    /**
     * @brief name
     * @return name of the item
     */
    std::string name() const;
    /**
     * @brief description
     * @return desctiption of the item
     */
    std::string description() const;

    /**
     * @brief isUsableFromInventory
     * @return can the item be used from the inventory?
     */
    bool isUsableFromInventory() const;
    /**
     * @brief isUsableFromBattle
     * @return can the item be used during Battle?
     */
    bool isUsableFromBattle() const;

    /**
     * @brief isUsableUponDeath
     * @return has the item an effect when the player dies?
     */
    bool isUsableUponDeath() const;

    /**
     * @brief hasBattleEffect
     * @return has the item a passive effect at the start of the battle?
     */
    bool hasBattleEffect() const;

    /**
     * @brief hasDurableBattleEffect
     * @return has the item a passive effect during each battle round
     */
    bool hasDurableBattleEffect() const;

    /**
     * @brief isConsumable
     * @return is the item consumable
     * @remark this is checked everytime the item is used. so when the item has charges or so, set consumable to true,
     * when the charges are used up.
     */

    bool isConsumable() const;

    /**
     * @brief nameFilter
     * @param name
     * @return a name filter function to be used in std containers
     */
    static std::function<bool(const CItem*)> nameFilter(const std::string& name)
    {
        return [&name](const CItem* item) { return item->name().compare(name) == 0; };
    }

    static std::function<bool(const CItem*)> battleEffectFilter()
    {
        return [](const CItem* item) { return item->hasBattleEffect(); };
    }

    static std::function<bool(const CItem*)> durableBattleEffectFilter()
    {
        return [](const CItem* item) { return item->hasDurableBattleEffect(); };
    }

protected:
    std::string _name;
    std::string _description;

    bool _isUsableFromInventory = false;
    bool _isUsableFromBattle = false;
    bool _isUsableUponDeath = false;

    bool _hasBattleEffect = false;
    bool _hasDurableBattleEffect = false;

    bool _isConsumable = false;
};

#endif // CITEM_H
