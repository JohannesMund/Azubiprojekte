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

private:
    PotionSize _size;
};
