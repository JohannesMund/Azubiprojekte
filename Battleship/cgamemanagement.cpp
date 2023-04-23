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

    text.append(QStringLiteral("<p>playing against:<p><b><font size=\"25\">%1</font></b></p>").arg(opponent));

    QString phase;

    switch (_currentPhase)
    {
    case EPhase::ePlacement:
        phase = "Place your ships!";
        break;
    case EPhase::ePlay:
        phase = "Shoot!";
        break;
    case EPhase::eFinish:
        phase = "Game Over";
    }

    text.append(QStringLiteral("<p>%1</p>").arg(phase));

    if (_currentPhase == EPhase::eFinish && _winner != EPlayer::eNone)
    {
        QString name;
        if (_winner == EPlayer::eComputer)
        {
            name = opponent;
        }
        else
        {
            name = "Player";
        }
        text.append(QStringLiteral("<p>.oO(%1 wins)Oo.</p>").arg(opponent));
    }

    _shoutBox->setText(text);
}

void CGameManagement::initGame(EDifficulty difficulty)
{
    _difficulty = difficulty;
    _currentPhase = EPhase::ePlacement;
    _winner = EPlayer::eNone;
    updateShoutBox();

    emit newGame();
}

void CGameManagement::start()
{
    _currentPhase = EPhase::ePlay;
    updateShoutBox();
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

TGridSize CGameManagement::getGridSize() const
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

void CGameManagement::playerWins()
{
    _winner = EPlayer::ePlayer;
    setGameOver();
}

void CGameManagement::computerWins()
{
    _winner = EPlayer::eComputer;
    setGameOver();
}

void CGameManagement::setGameOver()
{
    _currentPhase = EPhase::eFinish;
    updateShoutBox();
    emit gameOver();
}

unsigned int CGameManagement::getHitsForWin() const
{
    unsigned int num = 0;
    for (auto s : getAvailableShips())
    {
        num += getSizeOfShip(s);
    }
    return num;
}
