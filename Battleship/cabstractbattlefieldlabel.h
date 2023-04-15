#pragma once

#include "cgamemanagement.h"

#include <QLabel>

class CAbstractBattleFieldLabel : public QLabel
{
public:
    CAbstractBattleFieldLabel(QWidget* parent = nullptr);

    void hit(const int id);
    void update();

protected:
    void init();

    virtual QString updateHitArea(const int shipId) = 0;

    std::vector<std::pair<CGameManagement::EShips, unsigned int>> _shipsAndHits;
};
