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
    Console::printLn(std::format(
        "You encounter the enemy {}, who attacks you with his weapon {}!", _enemy->name(), _enemy->weapon()));
    Console::hr();

    Console::printLn("[F]ight [R]un");

    auto input = Console::getAcceptableInput("fr");
    if (input == 'r')
    {
        Console::printLn(std::format("You are too scared of {}, so you decide to run away.", _enemy->name()));

        auto result = Randomizer::getRandom(10);

        if (result < 5)
        {
            Console::printLn(
                std::format("You are much faster than {}, so it was easy and you escape.", _enemy->name()));
            return;
        }
        else if (result < 9)
        {
            Console::printLn(
                std::format("This {} is pretty fast, you manage to escape, but you got hit.", _enemy->name()));
            CGameManagement::getPlayerInstance()->addHp(-1);
            return;
        }
        else
        {
            Console::printLn(std::format(
                "This is bad! {} is really fast, and gets you, there is no way to avoid this fight.", _enemy->name()));
        }
    }

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
        Console::hr();
        Console::printLnWithSpacer(std::format("Your Hp: {}", CGameManagement::getPlayerInstance()->hpAsString()),
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
            {
                Console::printLn("You got hit.");

                int damage = 1;
                auto items = CGameManagement::getInventoryInstance()->getItemsWithShieldingAction();
                for (auto item : items)
                {
                    damage = CGameManagement::getInventoryInstance()->useShieldingAction(item, damage);
                }
                if (damage > 0)
                {
                    CGameManagement::getPlayerInstance()->addHp(-1);
                }

                break;
            }
            case CBattle::EBattleResult::eTie:
                Console::printLn("It's a tie");
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
    if (!_enemy->isDead())
    {
        _enemy->postBattle();
    }

    if (!CGameManagement::getPlayerInstance()->isDead())
    {
        CGameManagement::getPlayerInstance()->postBattle(_enemy);
    }
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
        Console::printLn("Nobody wants to play.");
        return CBattle::EBattleResult::eTie;
    }
    if (!choice.has_value() && other.has_value())
    {
        Console::printLn("Player refuses to play.");
        return CBattle::EBattleResult::eLost;
    }
    if (choice.has_value() && !other.has_value())
    {
        Console::printLn("The enemy refuses to play.");
        return CBattle::EBattleResult::eWon;
    }

    Console::printLnWithSpacer(std::format("Player: {}", weapon2String(*choice)),
                               std::format("Enemy: {}", weapon2String(*other)));

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

std::string CBattle::weapon2String(const EWeapons weapon)
{
    switch (weapon)
    {
    case EWeapons::eRock:
        return "Rock";
    case EWeapons::ePaper:
        return "Paper";
    case EWeapons::eScissors:
        return "Scissors";
    case EWeapons::eLizard:
        return "Lizard";
    case EWeapons::eSpock:
        return "Spock";
    }
    return std::string();
}
