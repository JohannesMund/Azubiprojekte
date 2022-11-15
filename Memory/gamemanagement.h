#pragma once
#include <QMapIterator>
#include <QString>

/**
 * @brief handelt das GameManagement
 * @remark als namespace implementiert, da es global verfügbar sein soll und Singletons nicht so geil sind
 */

namespace GameManagement
{

enum class EPlayer
{
    ePlayer1,
    ePlayer2
};

/**
 * @brief toggleCurrentPlayer schaltet zwischen den aktiven Spielern hin und her
 */
void toggleCurrentPlayer();
/**
 * @brief getCurrentPlayer gibt zurück welcher spieler gerade am start ist.
 * @return
 */
EPlayer getCurrentPlayer();

/**
 * @brief isGameRunning ermittelt, ob ein Spiel läuft
 */
bool isGameRunning();

/**
 * @brief startGame startet das Spiel
 */
void startGame();

/**
 * @brief stopGame Beendet das Spiel
 */
void stopGame();

}; // namespace GameManagement
