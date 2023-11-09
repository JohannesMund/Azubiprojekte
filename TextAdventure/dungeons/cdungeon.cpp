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

void CDungeon::dungeonLoop(CDungeonMap* map)
{
    while (true)
    {
        Console::cls();
        map->currentRoom()->execute();
        if (CGameManagement::getPlayerInstance()->isDead())
        {
            return;
        }

        CMenu menu;

        std::vector<CMenu::Action> navs;
        for (auto nav : map->getDirectionNavs())
        {
            navs.push_back(menu.createAction(nav));
        }

        menu.addMenuGroup(navs, {menu.createAction("Map"), menu.createAction("Inventory")});
        menu.addMenuGroup({menu.createAction("Reveal")}, {CMenu::exitAction()});
        auto input = menu.execute();

        if (CMap::string2Direction(input.name) != CMap::EDirections::eNone)
        {
            map->movePlayer(CMap::string2Direction(input.name));
        }

        if (input.key == 'm')
        {
            Console::cls();
            map->printMap();
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
            map->reveal();
            map->printMap();
            Console::confirmToContinue();
        }
        if (CMenu::exit(input))
        {
            return;
        }
    }
}
