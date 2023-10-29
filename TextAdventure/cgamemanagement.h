#pragma once

#include "cinventory.h"
#include "cmap.h"
#include "cplayer.h"

#include <string>

class CGameManagement
{
public:
    static CGameManagement* getInstance();
    static CPlayer* getPlayerInstance();
    static CInventory* getInventoryInstance();
    static CMap* getMapInstance();

    void start();

    CMap* getMap();
    CPlayer* getPlayer();
    CInventory* getInventory();

private:
    CMap _map;
    CPlayer _player;
    CInventory _inventory;

    bool _isGameOver = false;

    void printHUD();
    void printMap();
    void printInventory();
    std::string printNavigation();

    void navigation();
    void playerDeath();

    void init();
    void gameLoop();

    CGameManagement();
};
