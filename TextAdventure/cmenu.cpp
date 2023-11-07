#include "cmenu.h"
#include "console.h"

#include <algorithm>
#include <cctype>
#include <format>

CMenu::CMenu()
{
}

void CMenu::addMenuGroup(const std::vector<std::string_view>& list1, const std::vector<std::string_view>& list2)
{
    MenuGroup grp;

    for (auto s : list1)
    {
        grp.first.push_back(createAction(s));
    }
    for (auto s : list2)
    {
        grp.second.push_back(createAction(s));
    }
    _menu.push_back(grp);
}

CMenu::Action CMenu::execute()
{
    for (const auto& group : _menu)
    {
        if (group.first.empty())
        {
            if (group.second.empty())
            {
                continue;
            }
            Console::printLn(halfGroup2String(group.second), Console::EAlignment::eRight);
        }
        else
        {
            if (group.second.empty())
            {
                Console::printLn(halfGroup2String(group.first));
            }
            else
            {
                Console::printLnWithSpacer(halfGroup2String(group.first), halfGroup2String(group.second));
            }
        }
    }

    return findActionByInput();
}

CMenu::Action CMenu::createAction(const std::string_view& s)
{
    Action menuAction;
    menuAction.name = s;
    menuAction.display = s;

    for (char c : s)
    {
        auto cc = std::tolower(c);
        if (_acceptableNavs.find(cc) == std::string::npos)
        {
            _acceptableNavs.push_back(cc);
            auto it = menuAction.display.find(c);
            menuAction.display.replace(it, 1, std::format("[{}]", c));
            menuAction.key = cc;
            return menuAction;
        }
    }
    return {};
}

CMenu::Action CMenu::findActionByInput() const
{
    auto input = Console::getAcceptableInput(_acceptableNavs);
    for (const auto& group : _menu)
    {
        for (const auto& v : {group.first, group.second})
        {
            for (const auto& a : v)
            {
                if (a.key == input)
                {
                    return a;
                }
            }
        }
    }
    return {};
}

std::string CMenu::halfGroup2String(const std::vector<Action>& l) const
{
    std::string s;
    for (const auto& a : l)
    {
        s.append(a.display);
        s.append(" ");
    }
    return s;
}
