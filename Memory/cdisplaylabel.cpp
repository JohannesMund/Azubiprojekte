#include "cdisplaylabel.h"

#include <QMessageBox>
#include <QString>

CDisplayLabel::CDisplayLabel(QWidget* parent, Qt::WindowFlags f) : QLabel(parent, f)
{
}

void CDisplayLabel::togglePlayer()
{
    _gameIsRunning = true;
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
    _gameIsRunning = true;
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

    _gameIsRunning = false;
    print();
}

void CDisplayLabel::gameOver()
{
    _gameIsRunning = false;
    QString title("Spielende");
    QString text("");
    if (_pointsPlayer1 > _pointsPlayer2)
    {
        text = "Spieler 1 gewinnt";
    }
    else if (_pointsPlayer1 < _pointsPlayer2)
    {
        text = "Spieler 2 gewinnt";
    }
    else
    {
        text = "Unentschieden";
    }

    QMessageBox::information(0, title, text);
}

bool CDisplayLabel::isGameRunning() const
{
    return _gameIsRunning;
}

void CDisplayLabel::print()
{
    QString textPlayer1 = QString("Player1: %1").arg(_pointsPlayer1);
    QString textPlayer2 = QString("Player2: %1").arg(_pointsPlayer2);

    if (_currentPlayer == EPlayer::ePlayer1)
    {
        setText(QString("[%1] <- %2").arg(textPlayer1, textPlayer2));
    }
    else
    {
        setText(QString("%1 -> [%2]").arg(textPlayer1, textPlayer2));
    }
}
