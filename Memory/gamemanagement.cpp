#include "gamemanagement.h"

namespace
{
GameManagement::EPlayer _currentPlayer = GameManagement::EPlayer::ePlayer1;
bool _gameIsRunning = false;
} // namespace

void GameManagement::toggleCurrentPlayer()
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
}

GameManagement::EPlayer GameManagement::getCurrentPlayer()
{
    return _currentPlayer;
}

bool GameManagement::isGameRunning()
{
    return _gameIsRunning;
}

void GameManagement::startGame()
{
    _gameIsRunning = true;
}

void GameManagement::stopGame()
{
    _gameIsRunning = false;
}
