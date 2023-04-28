#pragma once

#include "battlefieldcoords.h"
#include "cgamemanagement.h"

#include <functional>

/**
 * @brief The CShipAtCoords class
 * Repräsentiert ein Schiff mit koordinaten
 * Man könnte das auch einfach über ein std::pair<BattleFieldCoords::BattleFieldCoords, int> realisieren, da wir hier
 * nur Getter haben und eine funktion von BattleFieldCoords durchreichen, aber die Filter- und Vergleichsfunktionen in
 * der Klasse zu definieren ist convinient und schön abstrakt.
 */

class CShipAtCoords
{
public:
    CShipAtCoords();
    CShipAtCoords(const BattleFieldCoords::BattleFieldCoords& coords, const int shipId);

    BattleFieldCoords::BattleFieldCoords getCoords() const;
    unsigned int getShipId() const;
    void transposeCoords(const BattleFieldCoords::EDirections dir, const bool min);

    /**
     * Wir definieren Typnamen für die Filter- und Vergleichsfunktionen, um das Handling einfacher zu machen.
     */
    using fnLT = std::function<bool(CShipAtCoords const&, CShipAtCoords const&)>;
    using fnFilter = std::function<bool(CShipAtCoords const&)>;

    /**
     * @brief shipIdFilter
     * gibt einen Funktionspointer zurück, der in einen Containeralgorithmus gegeben werden kann um nach einer
     * spezifischen ID zu filtern
     * @param shipId
     */
    static fnFilter shipIdFilter(const int shipId);

    /**
     * @brief battleFieldCoordFilter
     * gibt einen Funktionspointer zurück, der in einen Containeralgorithmus gegeben werden kann um nach spezifischen
     * Koordinaten zu filtern
     * @param coords
     */
    static fnFilter battleFieldCoordFilter(const BattleFieldCoords::BattleFieldCoords coords);

    /**
     * @brief battleFieldCoordLT
     * Gibt einen Funktionspointer auf eine LessThan Funktion zurück die fpr Containeralgorithmen verwendet werden kann.
     * Es wird die Richtung (horizontal/vertikal) mitgegeben
     * @param dir
     */
    static fnLT battleFieldCoordLT(const BattleFieldCoords::EDirections dir);

private:
    BattleFieldCoords::BattleFieldCoords _coords = {0, 0};
    int _shipId = CGameManagement::InvalidShipId;
};
