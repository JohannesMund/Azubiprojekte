#pragma once

class CPlayer
{
public:
    CPlayer();
    void print() const;

    void addGold(const int i);
    void addHp(const int i);

    bool isDead() const;

private:
    int _hp = 10;
    int _maxHp = 10;
    int _gold = 0;
};
