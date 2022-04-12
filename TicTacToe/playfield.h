#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include "playermanagement.h"

class PlayField
{
public:
    PlayField();

    bool setField(const int x, const int y, const PlayerManagement::Player p);
    void checkWinner();
    bool gameOver() const;
    PlayerManagement::Player winner() const;
    void reset();

private:
    void haveWinner(const PlayerManagement::Player& p);

    bool _gameOver = false;
    PlayerManagement::Player _winner = PlayerManagement::none;
    PlayerManagement::Player _grid[3][3];
};

#endif // PLAYFIELD_H
