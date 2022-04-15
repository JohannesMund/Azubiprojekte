#ifndef COMPUTERENEMY_H
#define COMPUTERENEMY_H

#include "playermanagement.h"
#include "playfieldcoords.h"

#include <QMap>
#include <QString>

class PlayField;

/**
 * @brief The ComputerEnemy class
 * Repräsentiert den Computergegner
 */

class ComputerEnemy
{
public:
    enum class Difficulty
    {
        easy = 1,
        medium = 2,
        hard = 3,
        insane = 4,
        minmax = 5
    };

    using DifficultyMap = QMap<Difficulty, QString>;
    using DifficultyMapIterator = QMapIterator<Difficulty, QString>;

    void setDifficulty(const Difficulty difficulty);

    /**
     * @brief getAvailableDifficulties
     * @return gibt eine liste verfügbarer Schwierigkeitsstufen zurück
     */
    static DifficultyMap getAvailableDifficulties()
    {
        return {{ComputerEnemy::Difficulty::easy, "Leicht"},
                {ComputerEnemy::Difficulty::medium, "Medium"},
                {ComputerEnemy::Difficulty::hard, "Schwer"},
                {ComputerEnemy::Difficulty::insane, "Insane"},
                {ComputerEnemy::Difficulty::minmax, "MinMax"}};
    }

    /**
     * @brief doMove
     * macht einen Move in abhängigkeit von der Schwierigkeit
     * @param snapShot das Spielfeld
     * @return Gibt die Koordinaten für den Move zurück
     */
    PlayFieldCoords doMove(const PlayField& snapShot);

private:
    /**
     * @brief getRandomEmptyField
     * @return gibt ein zufälliges leeres Feld zurück
     */
    static PlayFieldCoords getRandomEmptyField(const PlayField& snapShot);

    /**
     * @brief getWinningMove
     * Gibt ein Feld zurück, mit dem der Spieler gewinnen kann (wenn verfügbar)
     * @param snapShot Referenz auf das Spielfeld
     * @return Ein Feld, mit dem p auf jeden fall gewinnt oder invalid coords
     * @remark Nicht die effizienteste Art... Es wird nacheinander jedes freie
     * feld besetzt und geschaut ob der Spieler damit gewinnt.
     */
    static PlayFieldCoords getWinningMove(const PlayField& snapShot,
                                          const PlayerManagement::Player p = PlayerManagement::computerPlayer);

    /**
     * @brief getPreventLosingMove
     * Gibt ein Feld zurück das eine Niederlage für den Spieler verhindern kann
     * @param snapshot referenz auf das Spielfeld
     * @return Ein Feld, das der Spieler besetzen muss um nicht zu verlieren, oder
     * invalid coords
     * @remark Nicht die effizienteste Art... Es wird nacheinander jedes freie
     * feld besetzt und geschaut ob der andere Spieler damit gewinnt.
     */
    static PlayFieldCoords getPreventLosingMove(const PlayField& snapShot);

    /**
     * @brief getIdealFirstMove
     * ermittelt den idealen ersten Move
     * @param snapShot
     * @return der beste erste move für den spieler
     */
    static PlayFieldCoords getIdealFirstMove(const PlayField& snapShot);

    /**
     * @brief getMinMaxEvaluatedMove
     * Min-Max Evaluierung des nächsten Moves
     * @param snapShot
     * @return Der nach Min-Max ideale Move
     */
    static PlayFieldCoords getMinMaxEvaluatedMove(const PlayField& snapShot);

    /**
     * @brief calculateMoveValue
     * Funktion zum bewerten eines Spielstandes
     * @param snapShot
     * @param p
     * @param depth
     * @return den Wert des aktuellen Moves
     * @remark Rekursion
     */
    static int calculateMoveValue(const PlayField& snapShot, PlayerManagement::Player p, int depth = 0);

    /**
     * @brief calculateValueForFinishedBoard
     * ermittelt den Wert eines Feldes
     * @param snapShot
     * @return der wert des Feldes
     */
    static int calculateValueForFinishedBoard(const PlayField& snapShot, const int depth);

    Difficulty _difficulty = Difficulty::easy;
};

#endif // COMPUTERENEMY_H
