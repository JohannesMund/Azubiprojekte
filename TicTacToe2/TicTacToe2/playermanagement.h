#pragma once

#include <QColor>
#include <QString>

/**
 * @brief The PlayerManagement class
 * Klasse um die SPieler zu verwalten
 */

class PlayerManagement
{
public:
    /**
     * @brief The Player enum
     * Spieler X, Spieler O oder keiner
     */

    enum class Player
    {
        none,
        plX,
        plO
    };

    enum class GameMode
    {
        pvp,
        pvc
    };

    static constexpr Player computerPlayer = Player::plX;
    static constexpr Player humanPlayer = Player::plO;

    /**
     * @brief setComputerEnemy
     * Gibt an ob ein computer im spiel ist
     * @param b ja oder nein
     */
    void setGameMode(const GameMode mode);

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

    QString playerName(const Player& p) const;

    Player _currentPlayer;

    GameMode _gameMode = GameMode::pvp;
};
