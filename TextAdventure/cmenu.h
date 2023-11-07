#pragma once

#include <string>
#include <vector>

class CMenu
{

public:
    struct Action
    {
        std::string name;
        std::string display;
        char key;
    };
    using MenuGroup = std::pair<std::vector<Action>, std::vector<Action>>;

    CMenu();

    void addMenuGroup(const std::vector<std::string_view>& list1, const std::vector<std::string_view>& list2 = {});
    Action execute();

private:
    Action createAction(const std::string_view& s);
    Action findActionByInput() const;
    std::string halfGroup2String(const std::vector<Action>& l) const;

    std::string _acceptableNavs;
    std::vector<MenuGroup> _menu;
};
