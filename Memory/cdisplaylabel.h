#pragma once

#include <QFrame>
#include <QLabel>

/**
 * @brief Handelt die Anzeige des Spielstandes
 */

class CDisplayLabel : public QFrame
{
    Q_OBJECT
public:
    CDisplayLabel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    static QColor getCurrentPlayerColor();

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

private:
    int _pointsPlayer1 = 0;
    int _pointsPlayer2 = 0;
    int _turns = 0;

    QLabel* _player1Text;
    QLabel* _player2Text;
    QLabel* _arrow;
    QLabel* _turnsText;

    static const QColor _player1Color;
    static const QColor _player2Color;

    void print();
};
