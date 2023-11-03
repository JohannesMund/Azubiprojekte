#pragma once

#include <string>

class CEnemy;
class CCompanion
{
public:
    enum class ECompanionType
    {
        eCat,
        eDog,
        eBird,
        eDragon
    };

    CCompanion();

    std::string name() const;
    std::string description() const;
    unsigned int level() const;
    bool hasCompanion() const;

    void preBattle(CEnemy* enemy);
    void battleAction(CEnemy* enemy, bool& endRound);
    void postBattle(CEnemy* enemy);

    void setCompanionType(const ECompanionType tp);

    void evolve();

private:
    std::string _description;
    unsigned int _level = 0;

    ECompanionType _companionType;
};
