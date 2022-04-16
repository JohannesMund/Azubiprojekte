#include "computerenemy.h"
#include "playfield.h"

#include <QVector>
#include <random>

void ComputerEnemy::setDifficulty(const ComputerEnemy::Difficulty difficulty)
{
    _difficulty = difficulty;
}

PlayFieldCoords ComputerEnemy::doMove(const PlayField& snapShot) const
{
    if (_difficulty == Difficulty::minmax)
    {
        return getMinMaxEvaluatedMove(snapShot);
    }

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

PlayFieldCoords ComputerEnemy::getMinMaxEvaluatedMove(const PlayField& snapShot)
{
    const auto emptyFields = snapShot.getEmptyFields();

    PlayFieldCoords bestCoords;
    int bestValue = INT_MIN;
    for (const auto f : emptyFields)
    {
        PlayField copyField(snapShot);
        copyField.set(f, PlayerManagement::computerPlayer);
        int value = calculateMoveValue(copyField, PlayerManagement::computerPlayer);
        if (value > bestValue)
        {
            bestCoords = f;
            bestValue = value;
        }
    }
    return bestCoords;
}

int ComputerEnemy::calculateMoveValue(const PlayField& snapShot, PlayerManagement::Player p, int depth)
{
    if (snapShot.getGameOver())
    {
        return calculateValueForFinishedBoard(snapShot, depth);
    }

    depth++;

    const auto emptyFields = snapShot.getEmptyFields();

    int value;

    if (p == PlayerManagement::computerPlayer)
    {
        p = PlayerManagement::humanPlayer;
        value = INT_MAX;

        for (auto f : emptyFields)
        {
            PlayField copyField(snapShot);
            copyField.set(f, p);
            value = std::min(value, calculateMoveValue(copyField, p, depth));
        }
    }
    else
    {
        p = PlayerManagement::computerPlayer;
        value = INT_MIN;

        for (auto f : emptyFields)
        {
            PlayField copyField(snapShot);
            copyField.set(f, p);
            value = std::max(value, calculateMoveValue(copyField, p, depth));
        }
    }

    return value;
}

int ComputerEnemy::calculateValueForFinishedBoard(const PlayField& snapShot, const int depth)
{
    if (snapShot.getWinner() == PlayerManagement::computerPlayer)
    {
        return 10 - depth;
    }
    else if (snapShot.getWinner() == PlayerManagement::humanPlayer)
    {
        return -10 + depth;
    }
    else
    {
        return 0;
    }
}
