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
    void levelUp();

private:
    int _hp = 10;
    int _maxHp = 10;
    int _gold = 0;

    int _level = 1;

    static std::string increasedOrDecreased(const int i);
    static std::string lostOrGained(const int i);
};
