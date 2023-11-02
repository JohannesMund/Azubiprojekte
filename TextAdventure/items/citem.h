#pragma once

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
     * Default items have no power. Needs to be overwritten to un-junk the item
     */

    /**
     * @brief useFromInventory
     * Called, when a n item is used from the enventory
     */
    virtual void useFromInventory()
    {
    }

    virtual void useFromBattle()
    {
    }

    virtual void battleEffect(CEnemy*)
    {
    }

    virtual void durableBattleEffect(CEnemy*, bool& endRound)
    {
    }

    virtual int shield(const unsigned int i)
    {
        return i;
    }

    virtual void deathEffect()
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
     * @brief hasDeathEffect
     * @return has the item an effect when the player dies?
     */
    bool hasDeathEffect() const;

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
     * @brief hasShieldingAction
     * @return can the item shield damage
     */
    bool hasShieldingAction() const;

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
    static std::function<bool(const CItem*)> nameFilter(const std::string& name);

    /**
     * @brief battleEffectFilter
     * @return a filter function to filter items with battle effect from std containers
     */
    static std::function<bool(const CItem*)> battleEffectFilter();

    /**
     * @brief durableBattleEffectFilter
     * @return a filter function to filter items with durable battle effect from std containers
     */
    static std::function<bool(const CItem*)> durableBattleEffectFilter();

    /**
     * @brief shieldingActionFilter
     * @return a filter function to filter items with shield action from std containers
     */
    static std::function<bool(const CItem*)> shieldingActionFilter();

    /**
     * @brief deathEffectFilter
     @return a filter function to filter items with death effect from std containers
     */
    static std::function<bool(const CItem*)> deathEffectFilter();

    /**
     * @brief enhancableItemFilter
     * @return a filter function to filter enhancable items from std containers
     */
    static std::function<bool(const CItem*)> enhancableItemFilter();

protected:
    std::string _name;
    std::string _description;

    bool _isUsableFromInventory = false;
    bool _isUsableFromBattle = false;

    bool _hasDeathEffect = false;
    bool _hasBattleEffect = false;
    bool _hasDurableBattleEffect = false;
    bool _hasShieldingAction = false;

    bool _isConsumable = false;
};
