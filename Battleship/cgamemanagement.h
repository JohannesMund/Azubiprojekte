#pragma once

#include <QObject>
#include <QSize>

class QLabel;
class CGameManagement : public QObject
{
    friend class MainWindow;
    Q_OBJECT
public:
    enum class EShips
    {
        eNoShip = -1,
        eAircrafrCarrier = 5,
        eBattleShip = 4,
        eCruiser = 3,
        eDestroyer = 2,
        eSubMarine = 1
    };

    enum class EDifficulty
    {
        eEasy,
        eMedium,
        eHard
    };

    enum class EPhase
    {
        ePlacement,
        ePlay,
        eFinish
    };

    static constexpr int InvalidShipId = -1;

    using ShipVector = std::vector<EShips>;

    void initGame(EDifficulty difficulty);
    void start();

    EDifficulty getDifficulty() const;

    ShipVector getAvailableShips() const;
    QSize getGridSize() const;

    void playerFinished();
    void computerFinished();

    static QString ship2Text(EShips ship);
    static unsigned int getSizeOfShip(EShips ship);
    static CGameManagement* getInstance();

signals:
    void newGame();
    void startGame();

    void computerTurn();
    void playerTurn();

private:
    explicit CGameManagement(QObject* parent = nullptr);
    QLabel* _shoutBox = nullptr;

    void setShoutBox(QLabel* shoutBox);

    void updateShoutBox();

    EDifficulty _difficulty;
    EPhase _currentPhase;
};
