#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include "playermanagement.h"
#include "playfieldcoords.h"

/**
 * @brief The PlayField class
 * Kapselt das Spielfeld in einerm 3x3 Array
 */
class PlayField
{
public:
    /**
     * @brief setField
     * Setzt ein Feld
     * @param coords die Koordinaten eines Feldes
     * @param p der Spieler der das Feld besetzt
     * @return true, wenns geklappt hat, false, wenn das Feld. z.b. schon besetzt ist.
     */
    bool set(const PlayFieldCoords coords, const PlayerManagement::Player p);

    /**
     * @brief at
     * gibt den Wert eines Feldes zurück
     * @param coords die Koordinaten des Feldes
     * @return den spieler an coords
     */
    PlayerManagement::Player at(const PlayFieldCoords coords) const;

    /**
     * @brief reset
     * Setzt das Spielfeld zurück
     */
    void reset();

    /**
     * @brief getGameOver
     * @return true wenn das spiel vorbei ist
     */
    bool getGameOver() const;

    /**
     * @brief getWinner
     * @return gibt den Sieger zurück, PlayerManagement::Player::none bei
     * unentschieden
     * @remark nur sinnvoll wenn _gameOver == true
     */
    PlayerManagement::Player getWinner() const;

    QVector<PlayFieldCoords> getEmptyFields() const;

private:
    void setGameOver(const PlayerManagement::Player& winner);

    bool areEmptyFieldsLeft() const;
    void checkForWinner();

    PlayerManagement::Player getWinningPlayer() const;

    PlayerManagement::Player _winner = PlayerManagement::Player::none;
    PlayerManagement::Player _grid[3][3];
    bool _gameOver = false;
};

#endif // PLAYFIELD_H
