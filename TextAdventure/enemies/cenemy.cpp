#include "cenemy.h"
#include "cgamemanagement.h"
#include "randomizer.h"

CEnemy::CEnemy()
{
}

void CEnemy::preBattle()
{
}

void CEnemy::preBattleAction()
{
    _battleDecision = {};
}

void CEnemy::battleAction(bool& endRound)
{
    if (endRound)
    {
        return;
    }

    int range = _extendedWeaponChoice ? 5 : 3;
    _battleDecision = static_cast<CBattle::EWeapons>(Randomizer::getRandom(range));

    endRound = false;
}

void CEnemy::postBattleAction()
{
}

void CEnemy::postBattle()
{
}

void CEnemy::spoilsOfWar()
{
    CGameManagement::getPlayerInstance()->addXp(Randomizer::getRandom(_level * 75) + _level * 75);
    if (Randomizer::getRandom(2) == 0)
    {
        CGameManagement::getPlayerInstance()->addGold(Randomizer::getRandom(_level * 33) + _level * 25);
    }
}

std::string CEnemy::name() const
{
    return _name;
}

std::string CEnemy::weapon() const
{
    return _weapon;
}

unsigned int CEnemy::initiative() const
{
    return _initiative;
}

bool CEnemy::isDead() const
{
    return _hp <= 0;
}

bool CEnemy::hasExtendedWeaponChoice() const
{
    return _extendedWeaponChoice;
}

void CEnemy::addHp(const int i)
{
    _hp += i;
    if (_hp < 0)
    {
        _hp = 0;
    }
}

unsigned int CEnemy::hp() const
{
    return _hp;
}

std::optional<CBattle::EWeapons> CEnemy::peek()
{
    return _battleDecision;
}
