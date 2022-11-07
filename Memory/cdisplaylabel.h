#pragma once

#include <QLabel>

/**
 * @brief Handelt das Gamemanagement und die Anzeige des Spielstandes
 * @remark Diese Klasse weiß, welcher Spieler gerade am Zug ist, ob gerade ein SPiel läuft und zählt die Punkte.
 */

class CDisplayLabel : public QLabel
{
    Q_OBJECT
public:
    CDisplayLabel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    /**
     * @brief togglePlayer wechselt den Spieler
     */
    void togglePlayer();

    /**
     * @brief addPoints Der aktuelle Spieler bekommt Punkte
     */
    void addPoints();

    /**
     * @brief reset setzt die Anzeige zurück
     */
    void reset();

    /**
     * @brief gameOver ermittelt den Gewinner und macht eine MessageBox auf
     */
    void gameOver();

    /**
     * @brief isGameRunning ermittelt ob ein Spiel läuft
     */
    bool isGameRunning() const;

private:
    enum class EPlayer
    {
        ePlayer1,
        ePlayer2
    };

    int _pointsPlayer1 = 0;
    int _pointsPlayer2 = 0;
    EPlayer _currentPlayer = EPlayer::ePlayer1;

    bool _gameIsRunning = false;

    void print();
};
