#ifndef COMPUTERENEMY_H
#define COMPUTERENEMY_H

#include "playermanagement.h"
#include "playfieldcoords.h"

#include <QMap>
#include <QString>

class PlayField;

/**
 * @brief The ComputerEnemy class
 * Repräsentiert den COmputergegner
 */

class ComputerEnemy
{
public:
    enum class Difficulty
    {
        easy = 1,
        medium = 2,
        hard = 3
    };

    using DifficultyMap = QMap<Difficulty, QString>;
    using DifficultyMapIterator = QMapIterator<Difficulty, QString>;

    void setDifficulty(const Difficulty difficulty);

    /**
     * @brief getAvailableDifficulties
     * @return gibt eine liste verfügbarer schwierigkeitsstufen zurück
     */
    static DifficultyMap getAvailableDifficulties()
    {
        return {{ComputerEnemy::Difficulty::easy, "leicht"},
                {ComputerEnemy::Difficulty::medium, "medium"},
                {ComputerEnemy::Difficulty::hard, "schwer"}};
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
     * Gibt ein Feld zurück, mit dem Spieler p gewinnen kann (wenn verfügbar)
     * @param p Der Spieler der Gewinnen soll
     * @return Ein Feld, mit dem p auf jeden fall gewinnt oder invalid coords
     * @remark Nicht die effizienteste Art... Es wird nacheinander jedes freie
     * feld besetzt und geschaut ob p damit gewinnt.
     */
    static PlayFieldCoords getWinningMove(const PlayField& snapShot,
                                          const PlayerManagement::Player p = PlayerManagement::computerPlayer);

    /**
     * @brief getPreventLosingMove
     * Gibt ein Feld zurück das eine Niederlage für Spieler p verhindern kann
     * @param p der Spieler der nicht verlieren will
     * @return Ein Feld, das Spieler p besetzen muss um nicht zu verlieren, oder
     * invalid coords
     * @remark Nicht die effizienteste Art... Es wird nacheinander jedes freie
     * feld besetzt und geschaut ob der andere Spieler damit gewinnt.
     */
    static PlayFieldCoords getPreventLosingMove(const PlayField& snapShot);

    Difficulty _difficulty = Difficulty::easy;
};

#endif // COMPUTERENEMY_H
