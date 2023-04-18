#pragma once

#include "cabstractbattlefield.h"
#include "cgamemanagement.h"
#include "cshipsatcoords.h"

class QLabel;
class CShipAtCoords;
class CPlayerPlacement : public QObject
{
    Q_OBJECT

public:
    CPlayerPlacement();

    void init(QLabel* label);
    CGameManagement::EShips currentShip() const;
    int currentId() const;

    void next();
    bool isDone() const;

    void set(const BattleFieldCoords::BattleFieldCoords coords);

    void printPlacementText(QLabel* label);

signals:
    void unsetButtons(const CShipsAtCoords& ships);
    void setButton(const CShipAtCoords& ship);

private:
    int _currentId;
    CGameManagement::ShipVector _ships;

    QString placementText() const;

    CShipsAtCoords _moves;

    QLabel* _label;
};
