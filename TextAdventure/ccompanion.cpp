#include "ccompanion.h"
#include "cenemy.h"
#include "console.h"
#include "randomizer.h"

#include <format>

CCompanion::CCompanion()
{
    _companionType = Ressources::Companion::getRandomCompanionType();
}

std::string CCompanion::name() const
{
    return Ressources::Companion::nameForCompanionType(_companionType, _level);
}

std::string CCompanion::description() const
{
    return _description;
}

unsigned int CCompanion::level() const
{
    return _level;
}

bool CCompanion::hasCompanion() const
{
    return _level > 0;
}

void CCompanion::preBattle(CEnemy* enemy)
{
    Console::printLn(std::format("{} tries to look dangerous but it does not work. At least it is cute", name()));
}

void CCompanion::battleAction(CEnemy* enemy, bool& endRound)
{
    if (Randomizer::getRandom(2 + (Ressources::Companion::companionLevelCap - _level)) == 0)
    {
        Console::printLn(std::format("Your {} attacks the enemy and deals 1 damage.", name()));
        enemy->addHp(-1);
    }
    else
    {
        Console::printLn(std::format("Your {} jumps around the enemy and plans it's next attack.", name()));
    }
}

void CCompanion::postBattle(CEnemy* enemy)
{
    Console::printLn(std::format("{} looks victorious.", name()));
}

void CCompanion::evolve()
{
    if (_level >= Ressources::Companion::companionLevelCap)
    {
        return;
    }

    auto oldName = Ressources::Companion::nameForCompanionType(_companionType, _level);
    _level++;
    auto newName = Ressources::Companion::nameForCompanionType(_companionType, _level);

    if (_level == 1)
    {
        Console::printLn(std::format(
            "Finally, you found a friend! Your first friend ever! you pet your little {} and continue your journey.",
            newName));
    }
    else
    {
        Console::printLn(std::format("Your {} evolved into a {}", oldName, newName));
    }
}
