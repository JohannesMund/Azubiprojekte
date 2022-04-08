#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include "playermanagement.h"

class PlayFieldCoords : public QPair<int, int>
{
public:
    PlayFieldCoords() : QPair<int, int>(-1,-1){}
    PlayFieldCoords(const int i1, const int i2) : QPair<int, int>(i1, i2){}

    bool isValid() const {
        return first >= 0 && first<= 2 &&
               second >= 0 && second <= 2;
    };


};


class PlayField
{
public:
    PlayField();

    bool setField(const int x, const int y, const PlayerManagement::Player p);

    void checkWinner();

    bool gameOver() const;
    PlayerManagement::Player winner() const;

    void reset();

    PlayFieldCoords getRandomEmptyField();

    PlayFieldCoords getWinningMove(const PlayerManagement::Player p);
    PlayFieldCoords getPreventLosingMove(const PlayerManagement::Player p);

private:

    void setWinner(const PlayerManagement::Player& p);
    PlayerManagement::Player haveWinner() const;

    bool _gameOver = false;
    PlayerManagement::Player _winner = PlayerManagement::Player::none;

    PlayerManagement::Player _grid[3][3];
    QVector<PlayFieldCoords> getEmptyFields() const;
    bool emptyFieldsLeft() const;

};

#endif // PLAYFIELD_H
