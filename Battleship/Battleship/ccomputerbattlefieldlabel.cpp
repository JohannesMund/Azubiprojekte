#include "ccomputerbattlefieldlabel.h"

#include <QLabel>

CComputerBattleFieldLabel::CComputerBattleFieldLabel(QWidget* parent) : CAbstractBattleFieldLabel(parent)
{
}

QString CComputerBattleFieldLabel::updateHitArea(const int shipId)
{
    auto ship = _shipsAndHits.at(shipId).first;
    return QString("(%1)").arg(CGameManagement::getSizeOfShip(ship));
}
