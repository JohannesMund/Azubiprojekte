#ifndef CPLAYERMANAGEMENT_H
#define CPLAYERMANAGEMENT_H

/**
 * @brief CPlayerManagement handelt das PlayerManagement, und weiß, welcher Spieler gerade am Zug ist
 */
class CPlayerManagement
{
public:
    enum class Player
    {
        none,
        red,
        yellow
    };
    CPlayerManagement();

    /**
     * @brief reset setzt das PlayerManagement zurück
     */
    void reset();

    /**
     * @brief gibt den aktuellen Spieler zurück
     */
    Player getCurrentPlayer() const;

    /**
     * @brief toggleCurrentPlayer schaltet den Spieler um
     */
    void toggleCurrentPlayer();

private:
    Player _currentPlayer = Player::none;
};

#endif // CPLAYERMANAGEMENT_H
