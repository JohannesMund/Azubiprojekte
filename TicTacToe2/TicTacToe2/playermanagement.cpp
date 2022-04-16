#include "playermanagement.h"

void PlayerManagement::setGameMode(const GameMode mode)
{
    _gameMode = mode;
}

void PlayerManagement::togglePlayer()
{
    if (_currentPlayer == Player::plX)
    {

        _currentPlayer = Player::plO;
    }
    else
    {
        _currentPlayer = Player::plX;
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

QString PlayerManagement::playerName(const PlayerManagement::Player& p) const
{
    if (_gameMode == GameMode::pvc)
    {
        if (p == computerPlayer)
        {
            return "Computer";
        }
        else
        {
            return "Mensch";
        }
    }
    return playerToText(p);
}

QString PlayerManagement::currentPlayerName() const
{
    return playerName(_currentPlayer);
}

bool PlayerManagement::isPlayerTurn() const
{
    if (_gameMode == GameMode::pvc && _currentPlayer == computerPlayer)
    {
        return false;
    }
    return true;
}

QColor PlayerManagement::playerToColor(const Player& p)
{
    if (p == Player::plX)
    {
        return QColor(Qt::red);
    }
    else if (p == Player::plO)
    {
        return QColor(Qt::blue);
    }
    else
    {
        return QColor(Qt::black);
    }
}

QString PlayerManagement::currentPlayerText() const
{
    return playerToText(_currentPlayer);
}

QString PlayerManagement::playerToText(const Player& p)
{
    if (p == Player::plX)
    {
        return "X";
    }
    else if (p == Player::plO)
    {
        return "O";
    }
    else
    {
        return "PlayerManagement::none";
    }
}
