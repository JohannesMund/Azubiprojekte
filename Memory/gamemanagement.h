#pragma once

namespace GameManagement
{

enum class EPlayer
{
    ePlayer1,
    ePlayer2
};

enum class EGameMode
{
    eNormal,
    eChicken
};

void toggleCurrentPlayer();
EPlayer getCurrentPlayer();
bool isGameRunning();
void startGame();
void stopGame();

}; // namespace GameManagement
