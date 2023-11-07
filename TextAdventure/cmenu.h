#pragma once

#include <string>
#include <vector>

class CMenu
{

    struct Action
    {
        std::string name;
        char key;
    };

    using MenuGroup = std::pair<std::vector<Action>, std::vector<Action>>;

public:
    CMenu();

    void addMenuGroup(const std::vector<std::string_view>& list1, const std::vector<std::string_view>& list2 = {});
    char execute();

private:
    Action createAction(const std::string_view& s);
    std::string halfGroup2String(const std::vector<Action>& l) const;

    std::string _acceptableNavs;
    std::vector<MenuGroup> _menu;
};
