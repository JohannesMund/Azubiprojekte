#include "cgamemanagement.h"

#include <QLabel>

static CGameManagement* _instance = nullptr;

CGameManagement::CGameManagement(QObject* parent) : QObject(parent)
{
    _instance = this;
}

void CGameManagement::setShoutBox(QLabel* shoutBox)
{
    _shoutBox = shoutBox;
    _shoutBox->setContentsMargins(15, 15, 15, 15);
    _shoutBox->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
}

void CGameManagement::updateShoutBox()
{
    QString text;

    QString difficulty;
    QString opponent;
    switch (_difficulty)
    {
    case EDifficulty::eEasy:
        difficulty = "Easy";
        opponent = "Louis<br/>Lusche";
        break;
    case EDifficulty::eMedium:
        opponent = "Melvin<br/>Mediocre";
        difficulty = "Medium";
    default:
        break;
    case EDifficulty::eHard:
        difficulty = "Hard";
        opponent = "Hardy<br/>Hard";
        break;
    };

    text.append(QStringLiteral("<p><b>playing against:</p><p><font size=\"25\">%1</font></b></p>").arg(opponent));

    _shoutBox->setText(text);
}

void CGameManagement::initGame(EDifficulty difficulty)
{
    _difficulty = difficulty;
    updateShoutBox();
    emit newGame();
}

void CGameManagement::start()
{
    emit startGame();
}

CGameManagement::EDifficulty CGameManagement::getDifficulty() const
{
    return _difficulty;
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
    case EShips::eNoShip:
    default:
        break;
    }
    return QString();
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
