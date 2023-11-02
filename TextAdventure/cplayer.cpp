#include "cplayer.h"
#include "cenemy.h"
#include "cgamemanagement.h"
#include "console.h"
#include "ressources.h"

#include <format>
#include <string>

CPlayer::CPlayer()
{
    _maxHp = Ressources::Config::maxHp;
    _hp = Ressources::Config::maxHp;
    _gold = Ressources::Config::gold;
    _initiative = Ressources::Config::initiative;
}

void CPlayer::print() const
{
    Console::printLn(std::format("HP: {}/{} Gold: {}", _hp, _maxHp, _gold));
    Console::printLn(std::format("Level: {} Experience: {}/{}", _level, _xp, xpForNextLevel()));
    Console::hr();
}

void CPlayer::addGold(const int i)
{
    Console::printLn(std::format("You {} {} gold.", lostOrGained(i), std::abs(i)));
    _gold += i;
}

void CPlayer::addHp(const int i)
{
    Console::printLn(std::format("You {} {} Hitpoints.", lostOrGained(i), std::abs(i)));
    _hp += i;
    if (_hp <= 0)
    {
        _hp = 0;
    }
    if (_hp > _maxHp)
    {
        _hp = _maxHp;
    }
}

void CPlayer::addMaxHp(const int i)
{
    _maxHp += i;
    if (_maxHp < Ressources::Config::maxHpMin)
    {
        _maxHp = Ressources::Config::maxHpMin;
    }
    if (i < 0 && _hp > _maxHp)
    {
        _hp = _maxHp;
    }
    Console::printLn(std::format(
        "Your maximum Hitpoints have been {}, you now have {}/{} HP", increasedOrDecreased(i), _hp, _maxHp));
}

bool CPlayer::isDead() const
{
    return _hp <= 0;
}

unsigned int CPlayer::level() const
{
    return _level;
}

unsigned int CPlayer::gold() const
{
    return _gold;
}

void CPlayer::addXp(const int i)
{
    Console::printLn(std::format("You {} {} Experience.", lostOrGained(i), std::abs(i)));
    _xp += i;

    if (_xp > xpForNextLevel())
    {
        levelUp();
    }
}

void CPlayer::levelUp()
{
    Console::printLn("You gained one level");
    _level++;
}

std::string CPlayer::printBattleNav(const bool extended)
{
    std::string battleNav = "[R]ock [P]aper [S]cissors";
    std::string acceptableInputs = "rps";

    if (extended)
    {
        battleNav.append(" [L]izard Sp[o]ck");
        acceptableInputs.append("lo");
    }

    Console::printLn(battleNav);

    Console::printLn("[I]nventory", Console::EAlignment::eRight);
    acceptableInputs.append("i");

    return acceptableInputs;
}

void CPlayer::preBattle(CEnemy* enemy)
{
    auto items = CGameManagement::getInventoryInstance()->getItemsWithBattleEffect();
    for (auto item : items)
    {
        CGameManagement::getInventoryInstance()->useBattleEffect(item, enemy);
    }
}

std::optional<CBattle::EWeapons> CPlayer::battleAction(CEnemy* enemy, bool& endRound)
{
    if (endRound)
    {
        return {};
    }

    auto items = CGameManagement::getInventoryInstance()->getItemsWithDurableBattleEffect();
    for (auto item : items)
    {
        CGameManagement::getInventoryInstance()->useDurableBattleEffect(item, enemy, endRound);
        if (endRound || enemy->isDead())
        {
            return {};
        }
    }

    while (true)
    {
        std::string acceptableInputs = printBattleNav(enemy->hasExtendedWeaponChoice());
        auto input = Console::getAcceptableInput(acceptableInputs);
        if (input == 'r')
        {
            return CBattle::EWeapons::eRock;
        }
        if (input == 'p')
        {
            return CBattle::EWeapons::ePaper;
        }
        if (input == 's')
        {
            return CBattle::EWeapons::eScissors;
        }
        if (input == 'l')
        {
            return CBattle::EWeapons::eLizard;
        }
        if (input == 'o')
        {
            return CBattle::EWeapons::eSpock;
        }
        if (input == 'i')
        {
            CGameManagement::getInventoryInstance()->printInventory(CInventory::Scope::eBattle);
        }
    }
    endRound = false;
    return {};
}

void CPlayer::postBattle(CEnemy* enemy)
{
}

std::string CPlayer::hpAsString() const
{
    return std::format("{}/{}", _hp, _maxHp);
}

unsigned int CPlayer::initiative() const
{
    return _initiative;
}

unsigned int CPlayer::xpForNextLevel() const
{
    return Ressources::Config::getXpForLevel(_level);
}

std::string CPlayer::increasedOrDecreased(const int i)
{
    return i < 0 ? "decreased" : "increased";
}

std::string CPlayer::lostOrGained(const int i)
{
    return i < 0 ? "lost" : "gained";
}
