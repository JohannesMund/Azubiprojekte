#pragma once
#include <QMapIterator>
#include <QString>

namespace GameManagement
{

enum class EPlayer
{
    ePlayer1,
    ePlayer2
};

void toggleCurrentPlayer();
EPlayer getCurrentPlayer();

bool isGameRunning();
void startGame();
void stopGame();

}; // namespace GameManagement
