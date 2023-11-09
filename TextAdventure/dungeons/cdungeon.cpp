#include "cdungeon.h"
#include "cgamemanagement.h"
#include "cmenu.h"
#include "colorconsole.h"
#include "console.h"
#include "cplayer.h"
#include "croom.h"

CDungeon::CDungeon()
{
}

void CDungeon::setDungeonMap(CDungeonMap* map)
{
    _map = map;
}

void CDungeon::dungeonLoop()
{
    while (true)
    {
        Console::cls();
        _map->currentRoom()->execute();
        if (CGameManagement::getPlayerInstance()->isDead())
        {
            return;
        }

        CMenu menu;

        std::vector<CMenu::Action> navs;
        for (auto nav : _map->getDirectionNavs())
        {
            navs.push_back(menu.createAction(nav));
        }

        menu.addMenuGroup(navs, {menu.createAction("Map"), menu.createAction("Inventory")});
        menu.addMenuGroup({menu.createAction("Reveal")}, {CMenu::exitAction()});
        auto input = menu.execute();

        if (CMap::string2Direction(input.name) != CMap::EDirections::eNone)
        {
            _map->movePlayer(CMap::string2Direction(input.name));
        }

        if (input.key == 'm')
        {
            Console::cls();
            _map->printMap();
            Console::confirmToContinue();
        }
        if (input.key == 'i')
        {
            Console::cls();
            CGameManagement::getInventoryInstance()->print(CInventory::Scope::eList);
        }
        if (input.key == 'r')
        {
            Console::cls();
            _map->reveal();
            _map->printMap();
            Console::confirmToContinue();
        }
        if (CMenu::exit(input))
        {
            return;
        }
    }
}
