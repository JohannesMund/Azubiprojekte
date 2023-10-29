#include "cgamemanagement.h"
#include "conio.h"
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
    ConIO::hr();
    _player.print();
}

void CGameManagement::printMap()
{
    ConIO::cls();
    _map.printMap();
}

void CGameManagement::printInventory()
{
    ConIO::cls();
    _inventory.print();
}

std::string CGameManagement::printNavigation()
{
    ConIO::hr();
    ConIO::printLn("Go Ahead");

    string acceptableInputs;
    string navigationDisplay;
    if (_map.navAvailable(CMap::EDirections::eNorth))
    {
        navigationDisplay += "[N]orth ";
        acceptableInputs += CMap::direction2Char(CMap::EDirections::eNorth);
    }
    if (_map.navAvailable(CMap::EDirections::eEast))
    {
        navigationDisplay += "[E]ast ";
        acceptableInputs += CMap::direction2Char(CMap::EDirections::eEast);
    }
    if (_map.navAvailable(CMap::EDirections::eSouth))
    {
        navigationDisplay += "[S]outh ";
        acceptableInputs += CMap::direction2Char(CMap::EDirections::eSouth);
    }
    if (_map.navAvailable(CMap::EDirections::eWest))
    {
        navigationDisplay += "[W]est ";
        acceptableInputs += CMap::direction2Char(CMap::EDirections::eWest);
    }

    ConIO::printLn(navigationDisplay);
    ConIO::printLn("[M]ap [I]nventory E[x]it", ConIO::EAlignment::eRight);
    acceptableInputs += "mix";

    return acceptableInputs;
}

void CGameManagement::navigation()
{
    while (true)
    {
        auto acceptableInputs = printNavigation();
        auto input = ConIO::getAcceptableInput(acceptableInputs);

        if (input == 'x')
        {
            _isGameOver = true;
            return;
        }

        if (CMap::char2Direction(input) != CMap::EDirections::eNone)
        {
            _map.movePlayer(CMap::char2Direction(input));
            return;
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
        ConIO::cls();
        printHUD();

        _map.currentRoom()->execute();

        if (_player.isDead())
        {
            playerDeath();
        }

        if (_player.isDead())
        {
            _isGameOver = true;
        }
        else
        {
            navigation();
        }
    }
}

CGameManagement::CGameManagement()
{
}
