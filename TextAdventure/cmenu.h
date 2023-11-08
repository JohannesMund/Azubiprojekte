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

    void addMenuGroup(const std::vector<Action>& list1, const std::vector<Action>& list2 = {});
    Action execute();

    Action createAction(const std::string_view& s, const char key = 0);

    static Action executeYesNoMenu();

    static Action yesAction();
    static Action noAction();
    static Action exitAction();

    static bool isYesAction(const Action& a);
    static bool isNoAction(const Action& a);
    static bool isExitAction(const Action& a);

private:
    Action findActionByInput() const;
    std::string halfGroup2String(const std::vector<Action>& l) const;

    bool isNavPossible(const char c) const;
    std::string makeDisplayString(const std::string_view s, const char c) const;

    void addNav(const char c = 0);

    std::string _acceptableNavs;
    std::vector<MenuGroup> _menu;
};
