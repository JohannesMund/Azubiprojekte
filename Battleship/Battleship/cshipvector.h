#pragma once

#include "battlefieldcoords.h"
#include "cabstractbattlefield.h"
#include "cshipatcoords.h"

#include <vector>

/**
 * @brief The CShipVector class
 * Ein Vektor mit Elementen CShipAtCoords
 * Wir leiten das ab, um ein paar Convinience funktionen zu bekommen.
 */

class CShipVector : public std::vector<CShipAtCoords>
{
public:
    CShipVector();

    /**
     * @brief contains
     * Convinience: Prüft, ob der Vektor ein Schiff mit gegebenen Coordinaten enthält.
     * @param coords
     * @remark bentutzt std::vector::find_if
     */
    bool contains(const BattleFieldCoords::BattleFieldCoords coords);

    /**
     * @brief contains
     * Convinience: Prüft, ob der Vektor ein Schiff mit gegebener ID enthält.
     * @param shipId
     * @remark bentutzt std::vector::find_if
     */
    bool contains(const unsigned int shipId);

    /**
     * @brief isInLine
     * Prüft, ob ein Schiff in einer Reihe oder Spalte mit den Schiffen im Vektor ist
     * @param s
     * @remark macht am ehesten sinn, wenn alle Schiffe im Vektor in einer Reihe oder Spalte sind
     */
    bool isInLine(const CShipAtCoords s);

    /**
     * @brief isVerticalLine
     * Prüft, ob alle Schiffe im Vektor eine vertikale Linie bilden
     */
    bool isVerticalLine() const;

    /**
     * @brief isVerticalLine
     * Prüft, ob alle Schiffe im Vektor eine horizontale Linie bilden
     */
    bool isHorizontalLine() const;

    /**
     * @brief filter
     * Filtert den Vektor mit einer Filterfunktion
     * @sa CShipAtCoords::fnFilter
     * @param fn
     */
    CShipVector filter(const CShipAtCoords::fnFilter fn) const;

private:
    bool isLine(const BattleFieldCoords::EDirections dir) const;
};
