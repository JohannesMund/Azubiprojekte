#include "cgamemanagement.h"

static CGameManagement* _instance = nullptr;

CGameManagement::CGameManagement(QObject* parent) : QObject{parent}
{
    _instance = this;
}

void CGameManagement::initGame()
{
    emit newGame();
}

void CGameManagement::start()
{
    emit startGame();
}

CGameManagement::ShipVector CGameManagement::getAvailableShips() const
{
    return {EShips::eAircrafrCarrier,
            EShips::eBattleShip,
            EShips::eDestroyer,
            EShips::eDestroyer,
            EShips::eCruiser,
            EShips::eSubMarine,
            EShips::eSubMarine};
}

QSize CGameManagement::getGridSize() const
{
    return {10, 10};
}

QString CGameManagement::ship2Text(EShips ship)
{
    switch (ship)
    {
    case EShips::eCruiser:
        return "Cruiser";
    case EShips::eDestroyer:
        return "Detroyer";
    case EShips::eSubMarine:
        return "Submarine";
    case EShips::eAircrafrCarrier:
        return "Aircraft carrier";
    case EShips::eBattleShip:
        return "Battleship";
    }
}

unsigned int CGameManagement::getSizeOfShip(EShips ship)
{
    return static_cast<unsigned int>(ship);
}

CGameManagement* CGameManagement::getInstance()
{
    return _instance;
}

void CGameManagement::playerFinished()
{
    emit computerTurn();
}

void CGameManagement::computerFinished()
{
    emit playerTurn();
}
