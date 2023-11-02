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
    Console::printLnWithSpacer("[L]ook for trouble", "[M]ap [I]nventory");
    Console::printLn("[Q]uit Game", Console::EAlignment::eRight);
    acceptableInputs += "lmiq";

    return acceptableInputs;
}

void CGameManagement::executeTurn()
{
    while (true)
    {
        Console::cls();
        printHUD();

        _map.currentRoom()->execute();
        handlePlayerDeath();
        if (_player.isDead())
        {
            _isGameOver = true;
            return;
        }

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
            Console::confirmToContinue();
        }
        if (input == 'm')
        {
            printMap();
            Console::confirmToContinue();
        }
        if (input == 'i')
        {
            printInventory();
        }
    }
}

void CGameManagement::handlePlayerDeath()
{
    if (!_player.isDead())
    {
        return;
    }

    auto items = CGameManagement::getInventoryInstance()->getItemsWithDeathEffect();
    for (auto item : items)
    {
        CGameManagement::getInventoryInstance()->useDeathAction(item);
        if (!_player.isDead())
        {
            Console::confirmToContinue();
            return;
        }
    }

    Console::printLn("      _____      ", Console::EAlignment::eCenter);
    Console::printLn(" ____|R.I.P|____ ", Console::EAlignment::eCenter);
    Console::printLn("|   Here lies   |", Console::EAlignment::eCenter);
    Console::printLn("|____ Player____|", Console::EAlignment::eCenter);
    Console::printLn("     |     |     ", Console::EAlignment::eCenter);
    Console::printLn("     |     |     ", Console::EAlignment::eCenter);
    Console::printLn("     |     |     ", Console::EAlignment::eCenter);
    Console::printLn("     |_____|     ", Console::EAlignment::eCenter);

    Console::printLn("- He died the way he lived -", Console::EAlignment::eCenter);
    Console::printLn(" - naked and alone -", Console::EAlignment::eCenter);
}

void CGameManagement::init()
{
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHealingPotionS));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHealingPotionS));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHealingPotionS));

    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHealingPotionM));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHealingPotionM));

    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::ePhoenixFeather));

    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eJunkItem));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eJunkItem));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eJunkItem));

    Randomizer::init();

    _map.setStartingPosition({3, 5});
    _map.init();
}

void CGameManagement::gameLoop()
{
    while (!_isGameOver)
    {
        Console::cls();

        executeTurn();
        handlePlayerDeath();
        if (_player.isDead())
        {
            _isGameOver = true;
            return;
        }
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
