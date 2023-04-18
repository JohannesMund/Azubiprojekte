#pragma once

#include "battlefieldcoords.h"
#include "cgamemanagement.h"

#include <functional>

class CShipAtCoords
{
public:
    using fnLT = std::function<bool(CShipAtCoords const&, CShipAtCoords const&)>;
    using fnFilter = std::function<bool(CShipAtCoords const&)>;

    CShipAtCoords();
    CShipAtCoords(const BattleFieldCoords::BattleFieldCoords& coords, const int shipId);

    BattleFieldCoords::BattleFieldCoords getCoords() const;
    unsigned int getShipId() const;
    void transposeCoords(const BattleFieldCoords::EDirections dir, const bool min);

    static fnFilter shipIdFilter(const int shipId);
    static fnFilter battleFieldCoordFilter(const BattleFieldCoords::BattleFieldCoords coords);
    static fnLT battleFieldCoordLT(const BattleFieldCoords::EDirections dir);

private:
    BattleFieldCoords::BattleFieldCoords _coords = {0, 0};
    int _shipId = CGameManagement::InvalidShipId;
};
