#pragma once

#include "cbattlefieldgrid.h"

#include <QObject>

class QLabel;

/**
 * @brief The CGameManagement class
 * Handelt den Spielablauf
 */
class CGameManagement : public QObject
{
    friend class MainWindow;
    Q_OBJECT
public:
    /**
     * @brief The EShips enum
     * Die verfügbaren Schiffe und ihre Größe
     * @remark wir beschränken uns auf Linien, der Bums hier ist schon komplizert genug.
     */
    enum class EShips
    {
        eNoShip = -1,
        eAircrafrCarrier = 5,
        eBattleShip = 4,
        eCruiser = 3,
        eDestroyer = 2,
        eSubMarine = 1
    };

    /**
     * @brief The EDifficulty enum
     * Der Schwirigkeitsgrad
     */
    enum class EDifficulty
    {
        eEasy,
        eMedium,
        eHard
    };

    /**
     * @brief The EPhase enum
     * Die Phase des Spiels
     */
    enum class EPhase
    {
        ePlacement,
        ePlay,
        eFinish
    };

    /**
     * @brief The EPlayer enum
     * Spieler oder Computer
     */
    enum class EPlayer
    {
        ePlayer,
        eComputer,
        eNone
    };

    /**
     * @brief InvalidShipId
     * eine definition für ein ungültiges Schiff oder kein Schiff oder so.
     */
    static constexpr int InvalidShipId = -1;

    /**
     * @brief ShipVector
     * Eine Definition für einen vektor aus Schiffen
     * @remark Nicht mit CShipVector verwechseln
     */
    using ShipVector = std::vector<EShips>;

    /**
     * @brief initGame
     * Initialisiert das Spiel mit Schwierigkeitsgrad
     * @param difficulty
     */
    void initGame(EDifficulty difficulty);

    /**
     * @brief start
     * Startet das Spiel
     */
    void start();

    /**
     * @brief getDifficulty
     * Getter für den Schwierigkeitsgrad
     */
    EDifficulty getDifficulty() const;

    /**
     * @brief getAvailableShips
     * Getter für die Liste an Schiffen, die platziert werden
     */
    ShipVector getAvailableShips() const;

    /**
     * @brief getGridSize
     * Getter für die Größe des Spielfeldes
     */
    TGridSize getGridSize() const;

    /**
     * @brief getHitsForWin
     * Wieviele Treffer sind für einen Sieg notwendig
     */
    unsigned int getHitsForWin() const;

    /**
     * @brief playerFinished
     * Wird vom Spieler aufgerufen, wenn der Spieler seinen Zug beendet hat.
     */

    void playerFinished();

    /**
     * @brief computerFinished
     * Wird vom Computer aufgerufen, wenn der Computer seinen Zug beendet hat.
     */
    void computerFinished();

    /**
     * @brief playerWins
     * Wird vom Spieler aufgerufen um den Sieg zu signalisieren
     */
    void playerWins();

    /**
     * @brief computerWins
     * Wird vom Computer aufgerufen um den Sieg zu signalisieren
     */
    void computerWins();

    /**
     * @brief ship2Text
     * Der Name zu einer Schiff id
     * @param ship
     */
    static QString ship2Text(EShips ship);

    /**
     * @brief getSizeOfShip
     * Größe eines Schiffes
     * @param ship
     */
    static unsigned int getSizeOfShip(EShips ship);

    /**
     * @brief getInstance
     * CGameManagement ist als Singleton imlementiert, d.h. es gibt nur eine einzige Instanz, die vom CMainWindow
     * angelegt wird. Alle anderen rufen getInstance auf, um an die Instanz zu kommen.
     */
    static CGameManagement* getInstance();

signals:
    /**
     * @brief newGame
     * Signalisiert ein neues Spiel
     */

    void newGame();
    /**
     * @brief startGame
     * Signalisiert den Start des Spiels
     */
    void startGame();

    /**
     * @brief computerTurn
     * Signalisiert dem ComputerSpieler, dass er am Zug ist.
     */
    void computerTurn();

    /**
     * @brief playerTurn
     * Signalisiert dem Spieler, dass er am Zug ist.
     */
    void playerTurn();

    /**
     * @brief gameOver
     * Signalisiert das Spielende
     */
    void gameOver();

private:
    explicit CGameManagement(QObject* parent = nullptr);
    QLabel* _shoutBox = nullptr;

    void setShoutBox(QLabel* shoutBox);

    void setGameOver();
    void updateShoutBox();

    EDifficulty _difficulty;
    EPhase _currentPhase;
    EPlayer _winner = EPlayer::eNone;
};
