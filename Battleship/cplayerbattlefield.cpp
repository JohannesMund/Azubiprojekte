#include "cplayerbattlefield.h"
#include "cabstractbattlefieldlabel.h"
#include "cbattlefieldbutton.h"

CPlayerBattleField::CPlayerBattleField(QWidget* parent) : CAbstractBattleField(parent)
{
    connect(&_placementHelper, &CPlayerPlacement::unsetButtons, this, &CPlayerBattleField::unsetButtons);
    connect(&_placementHelper,
            &CPlayerPlacement::setButton,
            this,
            [this](const CShipAtCoords s) { at(s.getCoords())->setHasShip(s.getShipId(), true); });
}

void CPlayerBattleField::placeBattleShips()
{
    _placementHelper.init(_label);
    enableAll(true);
}

void CPlayerBattleField::unsetButtons(const CShipsAtCoords& ships)
{
    for (auto ship : ships)
    {
        unsetButton(ship.getCoords());
    }
}

void CPlayerBattleField::unsetButton(const BattleFieldCoords::BattleFieldCoords coords)
{
    auto button = at(coords);
    button->setHasShip(CGameManagement::InvalidShipId, true);
    button->setEnabled(true);
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

    if (isValidMove(coords))
    {
        _placementHelper.set(coords);
    }
    else
    {
        unsetButton(coords);
    }
}

void CPlayerBattleField::shipHit(const BattleFieldCoords::BattleFieldCoords coords)
{
    auto button = at(coords);
    if (button->hasShip())
    {
        _label->hit(button->getShipId());
    }
    return;
}

bool CPlayerBattleField::isValidMove(const BattleFieldCoords::BattleFieldCoords coords) const
{
    if (!isInRange(coords))
        return false;

    return !hasShipAround(coords,
                          [this](const BattleFieldCoords::BattleFieldCoords coords) {
                              return at(coords)->hasShip() && at(coords)->getShipId() != _placementHelper.currentId();
                          });
}
