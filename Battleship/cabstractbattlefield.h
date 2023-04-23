#pragma once

#include "battlefieldcoords.h"
#include "cbattlefieldbutton.h"
#include "cbattlefieldgrid.h"
#include <QFrame>

class CAbstractBattleFieldLabel;

/**
 * @brief The CAbstractBattleField class
 * Repräsentiert das Spielfeld.
 * Enthält Spiel-bezogene Convinience-Funktionen.
 * @remark pure virtual. Muss sowohl für den Computerspieler als auch für den Spieler abgeleitet werden.
 */
class CAbstractBattleField : public QFrame
{

public:
    /**
     * @brief begin end
     * Wir haben eine Containerklasse im Bauch, und die hat Iteratoren. Die sollen auch von aussen Nutzbar seinl, also
     * reichen wir begin und end nach draussen durch.
     * @remark Ja, wir erlauben damit public access auf ein privates Member. Bei genauer Betrachtung aber nicht auf das
     * Private member selbst, wir erlauben den Inhalt zu manipulieren. und wir haben immernoch die Kontrolle. wir können
     * die Iteratoren const machen wenn wir das wollen und, und, und...
     */

    auto begin()
    {
        return _grid.begin();
    }

    auto end()
    {
        return _grid.end();
    }

    CAbstractBattleField(QWidget* parent = nullptr);

    /**
     * @brief setLabel
     * Das Spielfeld kennt auch ein Label, dem es mitteilen kann, ob ein Treffer registriert wurde.
     * @param label
     */
    void setLabel(CAbstractBattleFieldLabel* label);

    /**
     * @brief hasShipAround
     * Ermittelt, um sich um ein feld herum ein schiff befindet.
     * @param coords
     * @return
     */
    bool hasShipAround(const BattleFieldCoords::BattleFieldCoords coords) const;

    /**
     *Funktionsdefinition für hasShipAround_if
     *@sa hasShipAround_if
     */
    using fnAround = std::function<bool(const CBattleFieldButton* b)>;

    /**
     * @brief hasShipAround_if
     * Das Gleiche wie hasShipAround, nur kann zusätzlich eine Bedingung angegeben werden
     * @param coords
     * @param fn eine Funktion vom Typ fnAround
     * @sa fnAround
     * @sa hasShipAround
     */
    bool hasShipAround_if(const BattleFieldCoords::BattleFieldCoords coords, fnAround fn) const;

    /**
     * @brief isInRange
     * prüft, ob gegebene Koordinante innerhalb des BattleFields sind.
     * @param coords
     */
    bool isInRange(const BattleFieldCoords::BattleFieldCoords coords) const;

    /**
     * @brief checkForWin
     * Prüft, ob alle Schiffe aufgedeckt sind
     */
    bool checkForWin() const;

    /**
     * @brief at
     * Gibt den Button an den Koordinaten coords zurück
     * @param coords
     */
    CBattleFieldButton* at(const BattleFieldCoords::BattleFieldCoords coords) const;

protected:
    CBattleFieldGrid<CBattleFieldButton*> _grid;

    void init();

    /**
     * @brief placeBattleShips
     * Virtuell - Wird aufgerufen, wenn es an der Zeit ist, Schiffe zu platzieren.
     * @remark Muss von den abgeleiteten Klassen implementiert werden
     */
    virtual void placeBattleShips() = 0;

    /**
     * @brief startGame
     * Virtuell - Wird aufgerufen, wenn das Spiel losgeht
     * @remark Muss von den abgeleiteten Klassen implementiert werden
     */
    virtual void startGame() = 0;

    /**
     * @brief buttonToggled
     * Virtuell - Wird aufgerufen, wenn ein Knopf gedrückt wurde.
     * @remark Muss von den abgeleiteten Klassen implementiert werden
     * @param toggleState
     * @param coords
     */
    virtual void buttonToggled(const bool toggleState, const BattleFieldCoords::BattleFieldCoords coords) = 0;

    /**
     * @brief shipHit
     * Virtuell - Wird aufgerufen, wenn ein Schiff getroffen wurde.
     * @remark Muss von den abgeleiteten Klassen implementiert werden
     * @param coords
     */
    virtual void shipHit(const BattleFieldCoords::BattleFieldCoords coords) = 0;

    void clearGrid();

    void enableAll(const bool bEnable);
    void revealAll();

    CAbstractBattleFieldLabel* _label;
};
