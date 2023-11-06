#include "colorconsole.h"

#include <format>
#include <regex>

std::string ColorConsole::foregroundColor(const EColor c)
{
    switch (c)
    {
    case EColor::black:
        return "\033[30m";
    case EColor::red:
        return "\033[31m";
    case EColor::green:
        return "\033[32m";
    case EColor::yellow:
        return "\033[33m";
    case EColor::blue:
        return "\033[34m";
    case EColor::magenta:
        return "\033[35m";
    case EColor::cyan:
        return "\033[36m";
    case EColor::lightGray:
        return "\033[37m";
    case EColor::darkGray:
        return "\033[90m";
    case EColor::lightRed:
        return "\033[91m";
    case EColor::lightGreen:
        return "\033[92m";
    case EColor::lightYellow:
        return "\033[93m";
    case EColor::lightBlue:
        return "\033[94m";
    case EColor::lightMagenta:
        return "\033[95m";
    case EColor::lightCyan:
        return "\033[96m";
    }
}

std::string ColorConsole::backgroundColor(const EColor c)
{
    switch (c)
    {
    case EColor::black:
    default:
        return "\033[40m";
    case EColor::red:
        return "\033[41m";
    case EColor::green:
        return "\033[42m";
    case EColor::yellow:
        return "\033[43m";
    case EColor::blue:
        return "\033[44m";
    case EColor::magenta:
        return "\033[45m";
    case EColor::cyan:
        return "\033[46m";
    case EColor::lightGray:
        return "\033[47m";
    }
}

std::string ColorConsole::reset()
{
    return "\033[00m";
}

std::string ColorConsole::colorize(const std::string_view s, const EColor c)
{
    return std::format("{}{}{}", foregroundColor(c), s, reset());
}

size_t ColorConsole::colorizedSize(const std::string& s)
{
    const std::regex expression("\\\033\\[(\\d*)m");

    auto beginIt = std::sregex_iterator(s.begin(), s.end(), expression);
    auto endIt = std::sregex_iterator();
    auto count = std::distance(beginIt, endIt);

    return s.size() - (count * colorCodeSize());
}

size_t ColorConsole::colorCodeSize()
{
    return std::string("\033[00m").size();
}
