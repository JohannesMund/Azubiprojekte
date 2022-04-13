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
    PlayFieldCoords coords;

    if (_difficulty == Difficulty::insane)
    {
        coords = getIdealFirstMove(snapShot);
    }

    if (_difficulty >= Difficulty::medium && !coords.isValid())
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

PlayFieldCoords ComputerEnemy::getIdealFirstMove(const PlayField& snapShot)
{
    const auto emptyFields = snapShot.getEmptyFields();
    if (emptyFields.size() == 9)
    {
        return {0, 0};
    }
    if (emptyFields.size() == 8)
    {
        if (snapShot.at({1, 1}) == PlayerManagement::humanPlayer)
        {
            return {0, 0};
        }

        if (snapShot.at({0, 0}) == PlayerManagement::humanPlayer ||
            snapShot.at({0, 2}) == PlayerManagement::humanPlayer ||
            snapShot.at({2, 0}) == PlayerManagement::humanPlayer ||
            snapShot.at({2, 2}) == PlayerManagement::humanPlayer)
        {
            return {1, 1};
        }

        if (snapShot.at({0, 1}) == PlayerManagement::humanPlayer ||
            snapShot.at({1, 0}) == PlayerManagement::humanPlayer ||
            snapShot.at({1, 2}) == PlayerManagement::humanPlayer ||
            snapShot.at({2, 1}) == PlayerManagement::humanPlayer)
        {
            return {1, 1};
        }
    }
    return PlayFieldCoords();
}
