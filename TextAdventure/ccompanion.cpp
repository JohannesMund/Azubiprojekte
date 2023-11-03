#include "ccompanion.h"
#include "cenemy.h"
#include "console.h"
#include "randomizer.h"
#include "ressources.h"

#include <format>

CCompanion::CCompanion()
{
    std::vector<ECompanionType> v;
    v.push_back(ECompanionType::eCat);
    v.push_back(ECompanionType::eCat);
    v.push_back(ECompanionType::eCat);
    v.push_back(ECompanionType::eCat);
    v.push_back(ECompanionType::eCat);

    v.push_back(ECompanionType::eDog);
    v.push_back(ECompanionType::eDog);
    v.push_back(ECompanionType::eDog);
    v.push_back(ECompanionType::eDog);
    v.push_back(ECompanionType::eDog);

    v.push_back(ECompanionType::eBird);
    v.push_back(ECompanionType::eBird);
    v.push_back(ECompanionType::eBird);

    v.push_back(ECompanionType::eDragon);

    std::shuffle(v.begin(), v.end(), Randomizer::getRandomEngine());

    _companionType = v.at(0);
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
}

void CCompanion::battleAction(CEnemy* enemy, bool& endRound)
{
}

void CCompanion::postBattle(CEnemy* enemy)
{
}

void CCompanion::setCompanionType(const ECompanionType tp)
{
    _companionType;
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
