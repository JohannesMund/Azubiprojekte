#include "cabstractbattlefield.h"
#include "cgamemanagement.h"

#pragma once
class QLabel;
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
    void set(const CAbstractBattleField::BattleFieldCoords coords);

    void printPlacementText(QLabel* label);

signals:
    void unsetButtons(const std::vector<CAbstractBattleField::BattleFieldCoords>);
    void setButton(const CAbstractBattleField::BattleFieldCoords coords, const int shipId);

private:
    int _currentId;
    CGameManagement::ShipVector _ships;

    bool isInLineWithRest(const CAbstractBattleField::BattleFieldCoords coords);
    QString placementText() const;

    std::vector<CAbstractBattleField::BattleFieldCoords> _moves;

    QLabel* _label;
};
