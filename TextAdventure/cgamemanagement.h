#pragma once

#include "ccompanion.h"
#include "cinventory.h"
#include "cmap.h"
#include "cplayer.h"

#include <string>

class CEncounter;
class CGameManagement
{
public:
    static CGameManagement* getInstance();
    static CPlayer* getPlayerInstance();
    static CInventory* getInventoryInstance();
    static CMap* getMapInstance();
    static CCompanion* getCompanionInstance();

    void executeRandomEncounter() const;
    void registerEncounter(CEncounter* encounter);
    void unregisterEncounterByName(const std::string& name);

    void start();

    void printHUD();

private:
    CMap _map;
    CPlayer _player;
    CInventory _inventory;
    CCompanion* _companion;

    std::vector<CEncounter*> _encounters;

    bool _isGameOver = false;
    void printMap();
    void printInventory();

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
    ~CGameManagement();
};
