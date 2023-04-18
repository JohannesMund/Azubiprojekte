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
    std::optional<BattleFieldCoords::BattleFieldCoords> findNextHit();

    void hit(const CShipAtCoords s);

    std::vector<BattleFieldCoords::BattleFieldCoords> getAvailableFields();
    bool isValidField(const CShipAtCoords s) const;
    CShipsAtCoords::const_iterator getMinOrMax(const bool isMin,
                                               const BattleFieldCoords::EDirections dir,
                                               const CShipsAtCoords& filtered) const;
    std::optional<BattleFieldCoords::BattleFieldCoords> appendToMinOrMax(const bool isMin,
                                                                         const BattleFieldCoords::EDirections dir,
                                                                         const CShipsAtCoords& filtered) const;

    CAbstractBattleField* _battleField;

    std::vector<unsigned int> _sunkShips = {};
    CShipsAtCoords _hits = {};
};
