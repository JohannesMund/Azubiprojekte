#include "cgamemanagement.h"

#include "console.h"
#include "croom.h"
#include "items/itemfactory.h"
#include "randomizer.h"

#include <format>
#include <iostream>
#include <string>

using namespace std;

CGameManagement* _instance = nullptr;

CGameManagement* CGameManagement::getInstance()
{
    if (_instance == nullptr)
    {
        static CGameManagement instance;
        _instance = &instance;
    }

    return _instance;
}

CPlayer* CGameManagement::getPlayerInstance()
{
    return getInstance()->getPlayer();
}

CInventory* CGameManagement::getInventoryInstance()
{
    return getInstance()->getInventory();
}

CMap* CGameManagement::getMapInstance()
{
    return getInstance()->getMap();
}

void CGameManagement::start()
{
    init();
    gameLoop();
}

CMap* CGameManagement::getMap()
{
    return &_map;
}

CPlayer* CGameManagement::getPlayer()
{
    return &_player;
}

CInventory* CGameManagement::getInventory()
{
    return &_inventory;
}

void CGameManagement::printHUD()
{
    Console::hr();
    _player.print();
}

void CGameManagement::printMap()
{
    Console::cls();
    _map.printMap();
}

void CGameManagement::printInventory()
{
    Console::cls();
    _inventory.print(CInventory::Scope::eList);
}

std::string CGameManagement::printNavigation()
{
    Console::hr();
    string acceptableInputs = _map.printNav();
    Console::printWithSpacer("[L]ook for trouble", "[M]ap [I]nventory");
    Console::printLn("[Q]uit Game", Console::EAlignment::eRight);
    acceptableInputs += "lmiq";

    return acceptableInputs;
}

void CGameManagement::navigation()
{
    while (true)
    {
        auto acceptableInputs = printNavigation();
        auto input = Console::getAcceptableInput(acceptableInputs);

        if (input == 'q')
        {
            _isGameOver = true;
            return;
        }

        if (CMap::char2Direction(input) != CMap::EDirections::eNone)
        {
            _map.movePlayer(CMap::char2Direction(input));
            return;
        }

        if (input == 'l')
        {
            lookForTrouble();
            if (_player.isDead())
            {
                return;
            }
        }
        if (input == 'm')
        {
            printMap();
        }
        if (input == 'i')
        {
            printInventory();
        }
    }
}

void CGameManagement::playerDeath()
{
    Console::printLn("You are dead");
}

void CGameManagement::init()
{
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHealingPotionS));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHealingPotionS));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHealingPotionS));

    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHealingPotionM));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHealingPotionM));

    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eRubbishItem));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eRubbishItem));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eRubbishItem));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eRubbishItem));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eRubbishItem));

    Randomizer::init();
}

void CGameManagement::gameLoop()
{
    while (!_isGameOver)
    {
        Console::cls();
        printHUD();

        _map.currentRoom()->execute();

        if (!_player.isDead())
        {
            navigation();
        }
        playerDeath();
        _isGameOver = true;
    }
}

void CGameManagement::lookForTrouble()
{
    CBattle battle;
    battle.fight();
}

CGameManagement::CGameManagement()
{
}
