#include "colorconsole.h"

#include <format>
#include <regex>

std::string ColorConsole::foregroundColor(const EColor c)
{
    switch (c)
    {
    case EColor::black:
        return "\e[030m";
    case EColor::red:
        return "\e[031m";
    case EColor::green:
        return "\e[032m";
    case EColor::yellow:
        return "\e[033m";
    case EColor::blue:
        return "\e[034m";
    case EColor::magenta:
        return "\e[035m";
    case EColor::cyan:
        return "\e[036m";
    case EColor::lightGray:
        return "\e[037m";
    case EColor::darkGray:
        return "\e[090m";
    case EColor::lightRed:
        return "\e[091m";
    case EColor::lightGreen:
        return "\e[092m";
    case EColor::lightYellow:
        return "\e[093m";
    case EColor::lightBlue:
        return "\e[094m";
    case EColor::lightMagenta:
        return "\e[095m";
    case EColor::lightCyan:
        return "\e[096m";
    }
}

std::string ColorConsole::backgroundColor(const EColor c)
{
    switch (c)
    {
    case EColor::black:
    default:
        return "\e[040m";
    case EColor::red:
        return "\e[041m";
    case EColor::green:
        return "\e[042m";
    case EColor::yellow:
        return "\e[043m";
    case EColor::blue:
        return "\e[044m";
    case EColor::magenta:
        return "\e[045m";
    case EColor::cyan:
        return "\e[046m";
    case EColor::lightGray:
        return "\e[047m";
    case EColor::darkGray:
        return "\e[100m";
    case EColor::lightRed:
        return "\e[101m";
    case EColor::lightGreen:
        return "\e[102m";
    case EColor::lightYellow:
        return "\e[103m";
    case EColor::lightBlue:
        return "\e[104m";
    case EColor::lightMagenta:
        return "\e[105m";
    case EColor::lightCyan:
        return "\e[106m";
    }
}

std::string ColorConsole::reset()
{
    return "\e[000m";
}

std::string ColorConsole::colorize(const std::string_view s, const EColor c)
{
    return std::format("{}{}{}", foregroundColor(c), s, reset());
}

size_t ColorConsole::colorizedSize(const std::string& s)
{
    const std::regex expression("\\\e\\[(\\d*)m");

    auto beginIt = std::sregex_iterator(s.begin(), s.end(), expression);
    auto endIt = std::sregex_iterator();
    auto count = std::distance(beginIt, endIt);

    return s.size() - (count * colorCodeSize());
}

size_t ColorConsole::colorCodeSize()
{
    return std::string("\e[000m").size();
}
