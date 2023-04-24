#include "computerenemy.h"
#include "playfield.h"

#include <QVector>
#include <algorithm>
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
    std::random_device rd;
    std::mt19937 g(rd());

    QVector<PlayFieldCoords> emptyFields = snapShot.getEmptyFields();

    std::shuffle(emptyFields.begin(), emptyFields.end(), g);
    return PlayFieldCoords(emptyFields.first());
}

PlayFieldCoords ComputerEnemy::getWinningMove(const PlayField& snapShot, const PlayerManagement::Player p)
{
    /**
     * Einfach mal jedes feld nacheinander besetzen und gucken ob wir gewinnen
     */
    const auto emptyFields = snapShot.getEmptyFields();

    for (const auto& field : emptyFields)
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
    /**
     * Straight forward: wir gucken einfach ob der gegner mit einem Zug gewinnen kann, und verhindern das, indem wir
     * statt ihm diesen zug machen
     */
    return getWinningMove(snapShot, PlayerManagement::humanPlayer);
}

PlayFieldCoords ComputerEnemy::getIdealFirstMove(const PlayField& snapShot)
{
    /**
     * Sind wir erster, besetzen wir eine Ecke.
     * Sind wir zweiter, besetzen wir die Ecke, wenn der Gegner nicht in einer Ecke begonnen hat, ansonsten die Mitte
     */

    const auto emptyFields = snapShot.getEmptyFields();
    const auto sz = emptyFields.size();
    if (sz == 9)
    {
        return {0, 0};
    }
    if (sz == 8)
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
    /**
     * Wir besetzen nacheinander jedes leere Feld und bewerten den Zug.
     * Der Beste Zug wird dann gemacht.
     */

    const auto emptyFields = snapShot.getEmptyFields();

    PlayFieldCoords bestCoords;
    int bestValue = INT_MIN;
    for (const auto& f : emptyFields)
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
        /**
         * Wenn wir einen Move machen, der das Spiel beendet, wird bewerted
         */
        return calculateValueForFinishedBoard(snapShot, depth);
    }

    depth++;

    const auto emptyFields = snapShot.getEmptyFields();

    int value;

    /**
     * Wir spielen rekursiv jede Möglichkeit durch
     */

    if (p == PlayerManagement::computerPlayer)
    {
        /**
         * Sind wir der Menschenspieler, interessiert uns der wertlosesten Move
         */
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
        /**
         * Sind wir der Computerspieler, interessiert uns der wertvollste move
         */
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
    /**
     * Trivial: je Weiter weg der move ist, desto irellevanter ist der am ende
     */
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
