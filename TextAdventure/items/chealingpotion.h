#pragma once
#include <citem.h>

class CHealingPotion : public CItem
{
public:
    enum class PotionSize
    {
        S,
        M,
        L,
        XL
    };

    CHealingPotion(const PotionSize& size = PotionSize::M);
    virtual void useFromInventory() override;
    virtual void useFromBattle() override;

private:
    void use();

    PotionSize _size;
};
