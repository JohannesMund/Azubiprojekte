#pragma once

/**
 * @brief BattleFieldCoords
 * Koordinaten auf dem Battlefield
 */
namespace BattleFieldCoords
{
/**
 * @brief The EDirections enum
 * Straight Forward, horizontal oder vertikal
 */
enum class EDirections
{
    eHorizontal,
    eVertical
};

/**
 * @brief The BattleFieldCoords struct
 * Repräsentiert Koordinaten auf dem Battlefield
 */
struct BattleFieldCoords
{
    unsigned int x;
    unsigned int y;

    /**
     * @brief operator ==
     * Gleichheitsoperator
     * @param other
     */
    bool operator==(const BattleFieldCoords& other) const;

    /**
     * @brief transpose
     * verschiebt die Koordinaten um 1 Feld Richrung Minimum oder Maximum auf der horizontalen oder vertikalen Achse
     * @param dir
     * @param min
     */

    void transpose(const EDirections dir, const bool min);

    /**
     * @brief inc
     * Inkrementiert die Koordinaten um ein Feld in Richtung dir
     * @param dir
     */
    void inc(const EDirections dir);

    /**
     * @brief dec
     * Dekrementiert die Koordinaten um ein Feld in Richrung dir
     * @param dir
     */
    void dec(EDirections dir);
};

} // namespace BattleFieldCoords
