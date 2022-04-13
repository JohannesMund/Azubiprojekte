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
        hard = 3,
        insane = 4
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
        return {{ComputerEnemy::Difficulty::easy, "leicht"},
                {ComputerEnemy::Difficulty::medium, "medium"},
                {ComputerEnemy::Difficulty::hard, "schwer"},
                {ComputerEnemy::Difficulty::insane, "insane"}};
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

    Difficulty _difficulty = Difficulty::easy;
};

#endif // COMPUTERENEMY_H
