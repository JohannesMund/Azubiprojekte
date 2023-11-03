#pragma once

#include "ressources.h"

#include <string>

class CEnemy;
class CCompanion
{
public:
    CCompanion();

    std::string name() const;
    std::string description() const;
    unsigned int level() const;
    bool hasCompanion() const;

    void preBattle(CEnemy* enemy);
    void battleAction(CEnemy* enemy, bool& endRound);
    void postBattle(CEnemy* enemy);

    void evolve();

private:
    std::string _description;
    unsigned int _level = 0;

    Ressources::Companion::ECompanionType _companionType;
};
