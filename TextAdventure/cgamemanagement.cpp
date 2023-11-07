#include "cgamemanagement.h"
#include "cbattleencounter.h"
#include "cdeadhero.h"
#include "cencounter.h"
#include "cmenu.h"
#include "cmysteriouschest.h"
#include "companionfactory.h"
#include "console.h"
#include "croom.h"
#include "encounterregister.h"
#include "itemfactory.h"
#include "randomizer.h"

#include <iostream>
#include <string>
#include <vector>

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

CCompanion* CGameManagement::getCompanionInstance()
{
    return getInstance()->getCompanion();
}

void CGameManagement::start()
{
    init();
    gameLoop();
}

void CGameManagement::executeRandomEncounter() const
{
    if (_encounters.size() == 0)
    {
        return;
    }

    if (Randomizer::getRandom(100) > Ressources::Config::encounterChance)
    {

        return;
    }

    std::vector<unsigned int> indices;

    for (int index = 0; index < _encounters.size(); index++)
    {
        auto chance = _encounters.at(index)->encounterChance();
        if (chance == 0)
        {
            continue;
        }
        for (int i = 0; i < chance; i++)
        {
            indices.push_back(index);
        }
    }

    if (indices.size() == 0)
    {
        return;
    }

    std::shuffle(indices.begin(), indices.end(), std::default_random_engine(Randomizer::getRandomEngineSeed()));
    _encounters.at(indices.at(0))->execute();
    Console::confirmToContinue();
}

void CGameManagement::registerEncounter(CEncounter* encounter)
{
    _encounters.push_back(encounter);
}

void CGameManagement::unregisterEncounterByName(const std::string& name)
{
    auto it = std::remove_if(_encounters.begin(), _encounters.end(), CEncounter::nameFilter(name));
    _encounters.erase(it);
    delete *it;
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

CCompanion* CGameManagement::getCompanion()
{
    return _companion;
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

void CGameManagement::executeTurn()
{
    Console::cls();

    _map.currentRoom()->execute();
    if (_player.isDead())
    {
        return;
    }

    while (true)
    {
        Console::hr();

        CMenu menu;
        menu.addMenuGroup(_map.getDirectionNavs(), {"Map", "Inventory"});
        menu.addMenuGroup({"Look for trouble"}, {"Quit Game"});

        auto input = menu.execute();
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
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eHeartContainer));

    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eJunkItem));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eJunkItem));
    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eJunkItem));

    _inventory.addItem(ItemFactory::makeItem(ItemFactory::EItemType::eUrzasGlasses));

    Randomizer::init();

    EncounterRegister::encounterRegister();
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
    _companion = CompanionFactory::makeRandomCompanion();
}

CGameManagement::~CGameManagement()
{
    delete _companion;
    for (auto e : _encounters)
    {
        delete e;
    }
}
