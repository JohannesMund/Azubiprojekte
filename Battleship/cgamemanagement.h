#pragma once

#include <QObject>
#include <QSize>

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

    using ShipVector = std::vector<EShips>;

    void initGame();
    void start();

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
};
