#ifndef PLAYERMANAGEMENT_H
#define PLAYERMANAGEMENT_H

#include <QColor>
#include <QString>



class PlayerManagement
{
public:

    enum Player{
        none,
        plX,
        plO
    };

    PlayerManagement();

    void togglePlayer();
    QString currentPlayerText() const;
    QColor currentPlayerColor() const;

    Player getCurrentPlayer() const;

    static QString playerToText(const Player& p);
    static QColor playerToColor(const Player& p);

private:
    Player _currentPlayer;


};

#endif // PLAYERMANAGEMENT_H
