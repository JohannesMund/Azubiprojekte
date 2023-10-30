#include "cplayer.h"
#include "console.h"
#include "ressources.h"

#include <format>
#include <string>

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
    std::string lostOrGained = i < 0 ? "lost" : "gained";
    Console::printLn(std::format("you {} {} gold.", lostOrGained, i));
    _gold += i;
}

void CPlayer::addHp(const int i)
{
    std::string lostOrGained = i < 0 ? "lost" : "gained";
    Console::printLn(std::format("you {} {} Hitpoints.", lostOrGained, i));

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

bool CPlayer::isDead() const
{
    return _hp <= 0;
}
