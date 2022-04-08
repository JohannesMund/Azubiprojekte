#ifndef PLAYERMANAGEMENT_H
#define PLAYERMANAGEMENT_H

#include <QColor>
#include <QString>



class PlayerManagement
{
public:

    enum class Player{
        none,
        plX,
        plO
    };

    PlayerManagement();

    void setComputerEnemy(const bool b);

    void togglePlayer();
    QString currentPlayerText() const;
    QColor currentPlayerColor() const;

    Player getCurrentPlayer() const;

    QString currentPlayerName() const;

    bool isPlayerTurn() const;

    static QString playerToText(const Player& p);
    static QColor playerToColor(const Player& p);
    static Player computerPlayer();

private:
    QString playerName(const Player& p) const;


    Player _currentPlayer;

    bool _computerEnemy = false;

};

#endif // PLAYERMANAGEMENT_H
