#include "cplayerbattlefield.h"
#include "cabstractbattlefieldlabel.h"
#include "cbattlefieldbutton.h"

CPlayerBattleField::CPlayerBattleField(QWidget* parent) : CAbstractBattleField(parent)
{
    connect(&_placementHelper, &CPlayerPlacement::unsetButtons, this, &CPlayerBattleField::unsetButtons);
    connect(&_placementHelper,
            &CPlayerPlacement::setButton,
            this,
            [this](const BattleFieldCoords::ShipAtCoords s) { get(s.coords)->setHasShip(s.shipId, true); });
}

void CPlayerBattleField::placeBattleShips()
{
    _placementHelper.init(_label);
    enableAll(true);
}

void CPlayerBattleField::unsetButtons(const CShipsAtCoords coords)
{
    for (auto c : coords)
    {
        auto button = get({c.coords.x, c.coords.y});
        button->setHasShip(-1, true);
        button->setEnabled(true);
    }
}

void CPlayerBattleField::startGame()
{
    _label->update();
    enableAll(false);
}

void CPlayerBattleField::buttonToggled(const bool toggleState, const BattleFieldCoords::BattleFieldCoords coords)
{
    if (_placementHelper.isDone())
    {
        return;
    }
    if (toggleState == false)
    {
        return;
    }

    auto button = get(coords);
    if (isMoveValid(coords))
    {
        _placementHelper.set(coords);
    }
    else
    {
        button->setHasShip(-1, true);
    }
}

void CPlayerBattleField::shipHit(const BattleFieldCoords::BattleFieldCoords coords)
{
    auto button = get(coords);
    if (button->hasShip())
    {
        _label->hit(button->getShipId());
    }
    return;
}

bool CPlayerBattleField::isMoveValid(const BattleFieldCoords::BattleFieldCoords coords) const
{
    if (!isInRange(coords))
        return false;

    return !hasShipAround(coords,
                          [this](const BattleFieldCoords::BattleFieldCoords coords) {
                              return get(coords)->hasShip() && get(coords)->getShipId() != _placementHelper.currentId();
                          });
}
