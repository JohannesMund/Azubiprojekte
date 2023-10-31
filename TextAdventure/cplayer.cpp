#include "cplayer.h"
#include "console.h"
#include "ressources.h"

#include <format>

CPlayer::CPlayer()
{
    _maxHp = Ressources::Config::maxHp;
    _hp = Ressources::Config::maxHp;
    _gold = Ressources::Config::gold;
}

void CPlayer::print() const
{
    auto player = std::format("HP: {}/{} Gold: {}", _hp, _maxHp, _gold);
    Console::printLn(player);
    Console::hr();
}

void CPlayer::addGold(const int i)
{
    Console::printLn(std::format("You {} {} gold.", lostOrGained(i), i));
    _gold += i;
}

void CPlayer::addHp(const int i)
{
    Console::printLn(std::format("You {} {} Hitpoints.", lostOrGained(i), i));
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

int CPlayer::level() const
{
    return _level;
}

void CPlayer::levelUp()
{
    _level++;
}

std::string CPlayer::increasedOrDecreased(const int i)
{
    return i < 0 ? "decreased" : "increased";
}

std::string CPlayer::lostOrGained(const int i)
{
    return i < 0 ? "lost" : "gained";
}
