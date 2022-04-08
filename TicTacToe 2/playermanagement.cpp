#include "playermanagement.h"

void PlayerManagement::setComputerEnemy(const bool b)
{
    _computerEnemy = b;
}

void PlayerManagement::togglePlayer()
{
    if( _currentPlayer == Player::plX )
        _currentPlayer = Player::plO;
    else
        _currentPlayer = Player::plX;

}

QColor PlayerManagement::currentPlayerColor() const
{
    return playerToColor(_currentPlayer);
}

PlayerManagement::Player PlayerManagement::getCurrentPlayer() const
{
    return _currentPlayer;
}

QString PlayerManagement::playerName(const PlayerManagement::Player &p) const
{
    if( _computerEnemy )
    {
        if(p == computerPlayer())
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
    if(_computerEnemy && _currentPlayer == computerPlayer())
    {
        return false;
    }
    return true;
}

QColor PlayerManagement::playerToColor(const Player &p)
{
    if( p == Player::plX)
    {
        return QColor(Qt::red);
    }
    else if( p == Player::plO )
    {
        return QColor(Qt::blue);
    }
    else
    {
        return QColor(Qt::black);
    }
}

PlayerManagement::Player PlayerManagement::computerPlayer()
{
    return Player::plX;
}

QString PlayerManagement::currentPlayerText() const
{
    return playerToText(_currentPlayer);
}

QString PlayerManagement::playerToText(const Player &p)
{
    if( p == Player::plX)
    {
        return "X";
    }
    else if( p == Player::plO )
    {
        return "O";
    }
    else
    {
        return "PlayerManagement::none";
    }
}
