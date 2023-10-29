#ifndef CITEM_H
#define CITEM_H

#include <string>

class CItem
{
public:
    CItem();

    virtual void use(){};

    std::string name() const;
    std::string description() const;

    bool isUsableFromInventory() const;
    bool isUsableFromBattle() const;
    bool isUsableUponDeath() const;

    bool hasBattleEffect() const;
    bool hasDurableBattleEffect() const;

    bool isConsumable() const;

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
