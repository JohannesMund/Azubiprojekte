#pragma once

#include "cenhancableitem.h"

class CEnemy;
class CSword : public CEnhancableItem
{
public:
    CSword();

    virtual void battleEffect(CEnemy* enemy) override;
    virtual void durableBattleEffect(CEnemy* enemy) override;
};
