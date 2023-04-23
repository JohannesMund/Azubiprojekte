#pragma once

#include "battlefieldcoords.h"
#include "cshipvector.h"

#include <QObject>

#include <optional>

class CAbstractBattleField;
class CShipAtCoords;

/**
 * @brief The CComputerPlayer class
 * Hier haben wir die "KI" implementiert.
 * verbindet das signal "compouterTurn" von CGameManagement mit doMove()
 */

class CComputerPlayer : public QObject
{
public:
    explicit CComputerPlayer(CAbstractBattleField* battleField, QObject* parent = nullptr);

    void init();

private:
    /**
     * @brief doMove
     * Hier gehts los, hier wird die Schwierigkeit geprüft und losgeballert
     */
    void doMove();

    /**
     * @brief hit
     * Bei einem Treffer wird geschaut, ob ein schiff versenkt wurde und sich ansonsten der treffer gemerkt.
     * danach wird wirder doMove aufgerufen. und wenn alle schiffe versenkt wurden, signalisieren wir den Sieg ans
     * GameManagement.
     * @param s
     */
    void hit(const CShipAtCoords& s);

    /**
     * @brief doMoveEasy
     * Der einfache Move. es wird einfach random auf ein verfügbares Feld geschossen
     * @sa justSomRandomMove
     */
    BattleFieldCoords::BattleFieldCoords doMoveEasy() const;

    /**
     * @brief doMoveMedium
     * Mittlschwer, wenn wir halbversenkte Schiffe haben, schießen wir auf die.
     * @sa findNextHit
     * ansonsten
     * @sa justSomeRandimMove
     */
    BattleFieldCoords::BattleFieldCoords doMoveMedium() const;

    /**
     * @brief doMoveHard
     * Schwer, wenn wir halbversenkte Schiffe haben, schießen wir auf die.
     * @sa findNextHit
     * ansonsten wird das BattleField strukturiert abgegrast.
     * @sa strategicMove
     */
    BattleFieldCoords::BattleFieldCoords doMoveHard() const;

    /**
     * @brief justSomeRandomMove
     * der vector aus getAvaikableFields wird gemischelt und das erste Feld beschossen.
     * @sa getAvailableFields
     */
    BattleFieldCoords::BattleFieldCoords justSomeRandomMove() const;

    /**
     * @brief strategicMove
     * grast das Battlefield strukturiert ab
     */
    std::optional<BattleFieldCoords::BattleFieldCoords> strategicMove() const;

    /**
     * @brief getAvailableFields
     */
    std::vector<BattleFieldCoords::BattleFieldCoords> getAvailableFields() const;

    /**
     * @brief findNextHit
     * versucht, halbversenkte Schiffe zu treffen
     * @sa getMinOrMax
     * @sa appendToMinOrMax
     */
    std::optional<BattleFieldCoords::BattleFieldCoords> findNextHit() const;
    CShipVector::const_iterator getMinOrMax(const bool isMin,
                                            const BattleFieldCoords::EDirections dir,
                                            const CShipVector& filtered) const;
    std::optional<BattleFieldCoords::BattleFieldCoords> appendToMinOrMax(const bool isMin,
                                                                         const BattleFieldCoords::EDirections dir,
                                                                         const CShipVector& filtered) const;
    /**
     * @brief isValidMove
     * Prüft, ob ein Move gültig ist
     * @param s
     */
    bool isValidMove(const CShipAtCoords& s) const;

    CAbstractBattleField* _battleField;
    std::vector<unsigned int> _sunkShips = {};
    CShipVector _hits = {};
};
