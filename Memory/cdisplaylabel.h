#ifndef CDISPLAYLABEL_H
#define CDISPLAYLABEL_H

#include <QLabel>

/**
 * @brief Die Anzeige des Spielstandes
 * @remark Diese Klasse weiß, welcher Spieler gerade am Zug ist.
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

private:
    enum class EPlayer
    {
        ePlayer1,
        ePlayer2
    };

    int _pointsPlayer1 = 0;
    int _pointsPlayer2 = 0;

    void print();

    EPlayer _currentPlayer = EPlayer::ePlayer1;
};

#endif // CDISPLAYLABEL_H
