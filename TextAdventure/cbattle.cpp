#include "cbattle.h"
#include "cenemy.h"
#include "cgamemanagement.h"
#include "cmobenemy.h"
#include "console.h"
#include "randomizer.h"

#include <format>

CBattle::CBattle() : CBattle(new CMobEnemy)
{
}

CBattle::CBattle(CEnemy* enemy)
{
    _enemy = enemy;
}

CBattle::~CBattle()
{
    if (_enemy != nullptr)
    {
        delete _enemy;
    }
}

void CBattle::fight()
{
    Console::cls();
    Console::printLn(std::format("You encounter the enemy {}. get Ready for Battle!", _enemy->name()));
    Console::confirmToContinue();
    preBattle();
    battleLoop();
    postBattle();

    if (_enemy->isDead())
    {
        Console::printLn("You are victorious!");
        _enemy->spoilsOfWar();
    }
}

bool CBattle::isBattleOver() const
{
    if (_enemy == nullptr)
    {
        return true;
    }

    return CGameManagement::getPlayerInstance()->isDead() || _enemy->isDead();
}

void CBattle::preBattle()
{
    if (_enemy == nullptr)
    {
        return;
    }
    _enemy->preBattle();
    CGameManagement::getPlayerInstance()->preBattle(_enemy);
}

void CBattle::battleLoop()
{
    while (!isBattleOver())
    {
        Console::cls;
        Console::hr();
        Console::printWithSpacer(std::format("Your Hp: {}", CGameManagement::getPlayerInstance()->hpAsString()),
                                 std::format("Enemy Hp: {}", _enemy->hp()));
        Console::hr();
        Console::printLn("New turn");

        _enemy->preBattleAction();
        bool endRound = false;

        std::optional<EWeapons> playersChoice;
        if (doesPlayerGoFirst())
        {
            Console::printLn("You go first");
            playersChoice = CGameManagement::getPlayerInstance()->battleAction(_enemy, endRound);
            _enemy->battleAction(endRound);
        }
        else
        {
            Console::printLn("The enemy is faster.");
            playersChoice = CGameManagement::getPlayerInstance()->battleAction(_enemy, endRound);
            _enemy->battleAction(endRound);
        }
        if (!endRound)
        {
            switch (hasWonAgainst(playersChoice, _enemy->peek()))
            {
            case CBattle::EBattleResult::eWon:
                Console::printLn("You hit the enemy.");
                _enemy->addHp(-1);
                break;
            case CBattle::EBattleResult::eLost:
                Console::printLn("You got hit.");
                CGameManagement::getPlayerInstance()->addHp(-1);
                break;
            case CBattle::EBattleResult::eTie:
                break;
            }
        }
        if (!_enemy->isDead())
        {
            _enemy->postBattleAction();
        }
    }
}

void CBattle::postBattle()
{
}

bool CBattle::doesPlayerGoFirst()
{
    return Randomizer::getRandom(CGameManagement::getPlayerInstance()->initiative() + _enemy->initiative()) <
           CGameManagement::getPlayerInstance()->initiative();
}

CBattle::EBattleResult CBattle::hasWonAgainst(const std::optional<CBattle::EWeapons> choice,
                                              const std::optional<CBattle::EWeapons> other)
{

    if (!choice.has_value() && !other.has_value())
    {
        return CBattle::EBattleResult::eTie;
    }
    if (!choice.has_value() && other.has_value())
    {
        return CBattle::EBattleResult::eLost;
    }
    if (choice.has_value() && !other.has_value())
    {
        return CBattle::EBattleResult::eWon;
    }

    if (*choice == *other)
    {
        return CBattle::EBattleResult::eTie;
    }
    switch (*choice)
    {
    case EWeapons::eRock:
        if (*other == EWeapons::eScissors || *other == EWeapons::eLizard)
        {
            return CBattle::EBattleResult::eWon;
        }
        return CBattle::EBattleResult::eLost;
    case EWeapons::ePaper:
        if (*other == EWeapons::eRock || *other == EWeapons::eSpock)
        {
            return CBattle::EBattleResult::eWon;
        }
        return CBattle::EBattleResult::eLost;
    case EWeapons::eScissors:
        if (*other == EWeapons::ePaper || *other == EWeapons::eLizard)
        {
            return CBattle::EBattleResult::eWon;
        }
        return CBattle::EBattleResult::eLost;
    case EWeapons::eLizard:
        if (*other == EWeapons::eSpock || *other == EWeapons::ePaper)
        {
            return CBattle::EBattleResult::eWon;
        }
    case EWeapons::eSpock:
        if (*other == EWeapons::eRock || *other == EWeapons::eScissors)
        {
            return CBattle::EBattleResult::eWon;
        }
        return CBattle::EBattleResult::eLost;
    }
    return CBattle::EBattleResult::eTie;
}
