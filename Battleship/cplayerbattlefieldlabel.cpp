#include "cplayerbattlefieldlabel.h"

CPlayerBattleFieldLabel::CPlayerBattleFieldLabel(QWidget* parent) : CAbstractBattleFieldLabel(parent)
{
}

QString CPlayerBattleFieldLabel::updateHitArea(const int shipId)
{
    QString hitArea;
    auto ship = _shipsAndHits.at(shipId).first;
    auto hits = _shipsAndHits.at(shipId).second;

    auto hitpoints = CGameManagement::getSizeOfShip(ship);

    for (unsigned int i = 0; i < hitpoints; i++)
    {
        if (hits > i)
        {
            hitArea.append("[X]");
        }
        else
        {
            hitArea.append("[_]");
        }
    }

    return hitArea;
}
