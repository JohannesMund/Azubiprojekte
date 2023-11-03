#pragma once

#include "ccompanion.h"
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
    static CCompanion* getCompanionInstance();

    void start();

private:
    CMap _map;
    CPlayer _player;
    CInventory _inventory;
    CCompanion _companion;

    bool _isGameOver = false;

    void printHUD();
    void printMap();
    void printInventory();
    std::string printNavigation();

    void executeTurn();
    void handlePlayerDeath();

    void init();
    void gameLoop();
    void lookForTrouble();

    CMap* getMap();
    CPlayer* getPlayer();
    CInventory* getInventory();
    CCompanion* getCompanion();

    CGameManagement();
};
