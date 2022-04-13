#include "computerenemy.h"
#include "playfield.h"

#include <QVector>
#include <random>

void ComputerEnemy::setDifficulty(const ComputerEnemy::Difficulty difficulty)
{
    _difficulty = difficulty;
}

PlayFieldCoords ComputerEnemy::doMove(const PlayField& snapShot)
{
    PlayField playField(snapShot);

    PlayFieldCoords coords;

    if (_difficulty >= Difficulty::medium)
    {
        coords = getWinningMove(snapShot);
    }

    if (_difficulty >= Difficulty::hard && !coords.isValid())
    {
        coords = getPreventLosingMove(snapShot);
    }

    if (!coords.isValid())
    {
        coords = getRandomEmptyField(snapShot);
    }

    return coords;
}

PlayFieldCoords ComputerEnemy::getRandomEmptyField(const PlayField& snapShot)
{
    QVector<PlayFieldCoords> emptyFields = snapShot.getEmptyFields();
    std::random_shuffle(emptyFields.begin(), emptyFields.end());
    return emptyFields.first();
}

PlayFieldCoords ComputerEnemy::getWinningMove(const PlayField& snapShot, const PlayerManagement::Player p)
{
    const auto emptyFields = snapShot.getEmptyFields();

    for (const auto field : emptyFields)
    {
        assert(snapShot.at(field) == PlayerManagement::Player::none);

        auto playField(snapShot);
        playField.set(field, p);

        if (playField.getGameOver() && playField.getWinner() == p)
        {
            return field;
        }
    }
    return PlayFieldCoords();
}

PlayFieldCoords ComputerEnemy::getPreventLosingMove(const PlayField& snapShot)
{
    return getWinningMove(snapShot, PlayerManagement::humanPlayer);
}
