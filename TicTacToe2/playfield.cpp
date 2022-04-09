#include "playfield.h"

#include <random>
#include <QVector>

bool PlayField::setField(const PlayFieldCoords coords, const PlayerManagement::Player p)
{
    if( !coords.isValid())
    {
            return false;
    }

    if( _grid[coords.x()][coords.y()] != PlayerManagement::Player::none )
    {
        return false;
    }

    _grid[coords.x()][coords.y()] = p;

    checkForWinner();

    return true;
}

void PlayField::checkForWinner()
{
    const auto p = getWinningPlayer();
    if( p != PlayerManagement::Player::none)
    {
        setGameOver(p);
        return;
    }

    //Es gibt keinen Gewinner.
    //Schauen wir ob es noch leere felder gibt

    if( !areEmptyFieldsLeft())
    {
        //Es gibt kein gültiges Feld mehr, also unentschieden
        setGameOver(PlayerManagement::Player::none);
    }
}

bool PlayField::getGameOver() const
{
    return _gameOver;
}

PlayerManagement::Player PlayField::getWinner() const
{
    return _winner;
}

void PlayField::reset()
{
    for(int i = 0; i<=2; i++)
    {
        for(int j = 0; j <=2; j++)
        {
            _grid[i][j] = PlayerManagement::Player::none;
        }
    }
    _gameOver = false;
    _winner = PlayerManagement::Player::none;
}

PlayField::PlayFieldCoords PlayField::getRandomEmptyField()
{
    QVector<PlayFieldCoords> emptyFields = getEmptyFields();
    std::random_shuffle(emptyFields.begin(), emptyFields.end());
    return emptyFields.first();
}

PlayField::PlayFieldCoords PlayField::getWinningMove(const PlayerManagement::Player p)
{
    const auto emptyFields = getEmptyFields();
    for( const auto field : emptyFields)
    {
        assert(_grid[field.x()][field.y()] == PlayerManagement::Player::none);
        _grid[field.x()][field.y()] = p;
        const auto winner = getWinningPlayer();
        _grid[field.x()][field.y()] = PlayerManagement::Player::none;
        if( winner== p)
        {
            return field;
        }
    }
    return PlayFieldCoords();
}

PlayField::PlayFieldCoords PlayField::getPreventLosingMove(const PlayerManagement::Player p)
{
    if( p == PlayerManagement::Player::plX)
        return getWinningMove(PlayerManagement::Player::plO);
    if( p == PlayerManagement::Player::plO)
        return getWinningMove(PlayerManagement::Player::plX);
    return PlayFieldCoords();
}

void PlayField::setGameOver(const PlayerManagement::Player &winner)
{
    _gameOver = true;
    _winner = winner;
}

PlayerManagement::Player PlayField::getWinningPlayer() const
{
    //Hat ein spieler waagerecht TicTacToe?
    for(int line = 0; line <= 2; line ++)
    {
        if( _grid[line][0] == _grid[line][1] &&
            _grid[line][0] == _grid[line][2] &&
            _grid[line][0] != PlayerManagement::Player::none)
        {
            return _grid[line][0];
        }
    }

    //Hat ein spieler senkrecht TicTacToe?
    for(int col = 0; col <= 2; col ++)
    {
        if( _grid[0][col] == _grid[1][col] &&
            _grid[0][col] == _grid[2][col] &&
            _grid[0][col] != PlayerManagement::Player::none)
        {
            return _grid[0][col];
        }
    }

    //Hat ein spieler diagonal TicTacToe?
    if(( _grid[0][0] == _grid[1][1] && _grid[0][0] == _grid[2][2]) && _grid[0][0] != PlayerManagement::Player::none)
    {
        return _grid[0][0];
    }

    if(( _grid[0][2] == _grid[1][1] && _grid[0][2] == _grid[2][0]) && _grid[0][2] != PlayerManagement::Player::none)
    {
        return _grid[0][2];
    }
    return PlayerManagement::Player::none;
}

QVector<PlayField::PlayFieldCoords> PlayField::getEmptyFields() const
{
    QVector<PlayFieldCoords> v;
    for(int i = 0; i<=2; i++)
    {
        for(int j = 0; j <=2; j++)
        {
            if( _grid[i][j] == PlayerManagement::Player::none )
            {
                v.push_back(PlayFieldCoords({i,j}));
            }
        }
    }
    return v;
}

bool PlayField::areEmptyFieldsLeft() const
{
    for(int i = 0; i<=2; i++)
    {
        for(int j = 0; j <=2; j++)
        {
            if(_grid[i][j] == PlayerManagement::Player::none)
            {
                //Es gibt noch ein leeres Feld, also geht es weiter
                return true;
            }
        }
    }
    return false;
}
