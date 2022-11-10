#include "cplayermanagement.h"

CPlayerManagement::CPlayerManagement()
{
}

void CPlayerManagement::reset()
{
    _currentPlayer = Player::red;
}

CPlayerManagement::Player CPlayerManagement::getCurrentPlayer() const
{
    return _currentPlayer;
}

void CPlayerManagement::toggleCurrentPlayer()
{
    if (_currentPlayer == Player::red)
    {
        _currentPlayer = Player::yellow;
    }
    else
    {
        _currentPlayer = Player::red;
    }
}
