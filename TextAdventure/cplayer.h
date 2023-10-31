#pragma once

#include <string>

class CPlayer
{
public:
    CPlayer();
    void print() const;

    void addGold(const int i);
    void addHp(const int i);
    void addMaxHp(const int i);

    bool isDead() const;

    int level() const;
    void addXp(const int i);
    void levelUp();

private:
    int _hp = 10;
    int _maxHp = 10;
    int _gold = 0;

    int _level = 1;
    int _xp = 0;

    int xpForNextLevel() const;

    static std::string increasedOrDecreased(const int i);
    static std::string lostOrGained(const int i);
};
