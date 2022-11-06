#include "cdisplaylabel.h"

#include <QString>

CDisplayLabel::CDisplayLabel(QWidget* parent, Qt::WindowFlags f) : QLabel(parent, f)
{
}

void CDisplayLabel::togglePlayer()
{
    if (_currentPlayer == EPlayer::ePlayer1)
    {
        _currentPlayer = EPlayer::ePlayer2;
    }
    else
    {
        _currentPlayer = EPlayer::ePlayer1;
    }
    print();
}

void CDisplayLabel::addPoints()
{
    if (_currentPlayer == EPlayer::ePlayer1)
    {
        _pointsPlayer1++;
    }
    else
    {
        _pointsPlayer2++;
    }
    print();
}

void CDisplayLabel::reset()
{
    _pointsPlayer1 = 0;
    _pointsPlayer2 = 0;

    print();
}

void CDisplayLabel::print()
{
    QString textPlayer1 = QString("Player1: %1").arg(_pointsPlayer1);
    QString textPlayer2 = QString("Player2: %1").arg(_pointsPlayer2);

    QString pointer = _currentPlayer == EPlayer::ePlayer1 ? "<-" : "->";

    setText(QString("%1 %2 %3").arg(textPlayer1, pointer, textPlayer2));
}
