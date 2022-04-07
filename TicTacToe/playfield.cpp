#include "playfield.h"

PlayField::PlayField()
{

}

bool PlayField::setField(const int x, const int y, const PlayerManagement::Player p)
{

    if( _grid[x][y] != PlayerManagement::none )
    {
        return false;
    }

    _grid[x][y] = p;

    checkWinner();

    return true;
}

void PlayField::checkWinner()
{

    //Hat ein spieler waagerecht TicTacToe?
    for(int line = 0; line <= 2; line ++)
    {
        if( _grid[line][0] == _grid[line][1] &&
            _grid[line][0] == _grid[line][2] &&
            _grid[line][0] != PlayerManagement::PlayerManagement::none)
        {
            haveWinner(_grid[line][0]);
            return;
        }
    }

    //Hat ein spieler senkrecht TicTacToe?
    for(int col = 0; col <= 2; col ++)
    {
        if( _grid[0][col] == _grid[1][col] &&
            _grid[0][col] == _grid[1][col] &&
            _grid[0][col] != PlayerManagement::none)
        {
            haveWinner(_grid[0][col]);
            return;
        }
    }

    //Hat ein spieler diagonal TicTacToe?
    if(( _grid[0][0] == _grid[1][1] && _grid[0][0] == _grid[2][2]) && _grid[0][0] != PlayerManagement::none)
    {
        haveWinner(_grid[0][0]);
        return;
    }

    if(( _grid[0][2] == _grid[1][1] && _grid[0][2] == _grid[2][0]) && _grid[0][2] != PlayerManagement::none)
    {
        haveWinner(_grid[0][2]);
        return;
    }


    //Es gibt keinen Gewinner.
    //Schauen wir ob es noch leere felder gibt
    bool gameOver = true;

    for(int i = 0; i<=3; i++)
    {
        for(int j = 0; j <=3; j++)
        {
            if(_grid[i][j] == PlayerManagement::none)
            {
                //Es gibt noch ein leeres Feld, also geht es weiter
                gameOver = false;
                break;
            }
        }
    }

    if( gameOver )
    {
        //Es gibt kein gültiges Feld mehr, also unentschieden
        haveWinner(PlayerManagement::none);
    }
}

bool PlayField::gameOver() const
{
    return _gameOver;
}

PlayerManagement::Player PlayField::winner() const
{
    return _winner;
}

void PlayField::reset()
{
    for(int i = 0; i<=2; i++)
    {
        for(int j = 0; j <=2; j++)
        {
            _grid[i][j] = PlayerManagement::none;
        }
    }
    _gameOver = false;
    _winner = PlayerManagement::none;
}

void PlayField::haveWinner(const PlayerManagement::Player &p)
{
    _gameOver = true;
    _winner = p;
}
