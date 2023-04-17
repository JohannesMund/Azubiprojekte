#pragma once

#include "cabstractbattlefield.h"

#include <QObject>

#include <optional>

class CComputerPlayer : public QObject
{
public:
    explicit CComputerPlayer(CAbstractBattleField* battleField, QObject* parent = nullptr);

    void init();

private:
    void doMove();
    BattleFieldCoords::BattleFieldCoords doMoveEasy();
    BattleFieldCoords::BattleFieldCoords doMoveMedium();
    BattleFieldCoords::BattleFieldCoords doMoveHard();

    BattleFieldCoords::BattleFieldCoords justSomeRandomMove();
    void hit(const BattleFieldCoords::ShipAtCoords s);

    std::optional<BattleFieldCoords::BattleFieldCoords> findNextHit();

    std::vector<BattleFieldCoords::BattleFieldCoords> getAvailableFields();
    CAbstractBattleField* _battleField;

    std::vector<unsigned int> _sunkShips = {};
    CShipsAtCoords _hits;
};
