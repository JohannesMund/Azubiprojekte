#ifndef PLAYERMANAGEMENT_H
#define PLAYERMANAGEMENT_H

#include <QColor>
#include <QString>

/**
 * @brief The PlayerManagement class
 * Klasse um die SPieler zu verwalten
 */

class PlayerManagement
{
public:

    enum class Player{
        none,
        plX,
        plO
    };

    /**
     * @brief setComputerEnemy
     * Gibt an ob ein computer im spiel ist
     * @param b ja oder nein
     */
    void setComputerEnemy(const bool b);

    /**
     * @brief togglePlayer
     *Schaltet den current player um
     */
    void togglePlayer();

    /**
     * @brief currentPlayerText
     * @return Buttonbeschriftung des aktuellen Spielers
     */
    QString currentPlayerText() const;

    /**
     * @brief currentPlayerColor
     * @return passende Farbe für den aktuellen Spieler
     */
    QColor currentPlayerColor() const;

    /**
     * @brief getCurrentPlayer
     * @return der aktuelle Spieler
     */
    Player getCurrentPlayer() const;

    /**
     * @brief currentPlayerName
     * @return name des aktuellen Spielers
     */
    QString currentPlayerName() const;

    /**
     * @brief isPlayerTurn
     * @return ist ein Spieler am zug oder der Computer
     */
    bool isPlayerTurn() const;


private:

    static QString playerToText(const Player& p);
    static QColor playerToColor(const Player& p);
    static Player computerPlayer();

    QString playerName(const Player& p) const;


    Player _currentPlayer;

    bool _computerEnemy = false;

};

#endif // PLAYERMANAGEMENT_H
