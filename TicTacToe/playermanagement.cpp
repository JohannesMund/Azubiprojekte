#include "playermanagement.h"

PlayerManagement::PlayerManagement() { }

void PlayerManagement::togglePlayer()
{
    if (_currentPlayer == plX)
    {
        _currentPlayer = plO;
    }
    else
    {
        _currentPlayer = plX;
    }


}

QColor PlayerManagement::currentPlayerColor() const
{
    return playerToColor(_currentPlayer);
}

PlayerManagement::Player PlayerManagement::getCurrentPlayer() const
{
    return _currentPlayer;
}

QColor PlayerManagement::playerToColor(const Player& p)
{
    if (p == plX) {
        return QColor(Qt::red);
    } else if (p == plO) {
        return QColor(Qt::blue);
    } else {
        return QColor(Qt::black);
    }
}

QString PlayerManagement::currentPlayerText() const
{
    return playerToText(_currentPlayer);
}

QString PlayerManagement::playerToText(const Player& p)
{
    if (p == plX) {
        return "X";
    } else if (p == plO) {
        return "O";
    } else {
        return "PlayerManagement::none";
    }
}
