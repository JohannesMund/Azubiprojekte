#pragma once

#include "cabstractbattlefield.h"
#include "cgamemanagement.h"
#include "cshipvector.h"

class QLabel;
class CShipAtCoords;

/**
 * @brief The CPlayerPlacement class
 * Hilfsklasse zum Platzieren der Schiffe des Spielers.
 * Verwaltet die Schiffe die zu platzieren sind.
 * Kennt ein Label, auf dass es Text blubbern kann.
 */

class CPlayerPlacement : public QObject
{
    Q_OBJECT

public:
    CPlayerPlacement();

    /**
     * @brief init
     * Initialisierung mit dem Label, auf das man blubbern kann
     * @param label
     */

    void init(QLabel* label);

    /**
     * @brief set
     * Schiebt eine Koordinate ins Placement an die der Spieler ein Schiff platzieren will
     * Das Placement übernimmt den Rest
     * @param coords
     */
    void set(const BattleFieldCoords::BattleFieldCoords coords);

    /**
     * @brief isDone
     * Gibt zurück ob alle Schiffe platziert sind.
     */
    bool isDone() const;

    /**
     * @brief currentId
     * Gibt die aktuelle ID zurück
     */
    int currentId() const;

signals:
    void unsetButtons(const CShipVector& ships);
    void setButton(const CShipAtCoords& ship);

private:
    CGameManagement::EShips currentShip() const;

    void next();
    void printPlacementText(QLabel* label);
    QString placementText() const;

    int _currentId;
    CGameManagement::ShipVector _ships;

    CShipVector _moves;

    QLabel* _label;
};
