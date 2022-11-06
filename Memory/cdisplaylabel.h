#ifndef CDISPLAYLABEL_H
#define CDISPLAYLABEL_H

#include <QLabel>

class CDisplayLabel : public QLabel
{
    Q_OBJECT
public:
    enum class EPlayer
    {
        ePlayer1,
        ePlayer2
    };

    CDisplayLabel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    void togglePlayer();
    void addPoints();
    void reset();

private:
    int _pointsPlayer1 = 0;
    int _pointsPlayer2 = 0;

    void print();

    EPlayer _currentPlayer = EPlayer::ePlayer1;
};

#endif // CDISPLAYLABEL_H
