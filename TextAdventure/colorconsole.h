#pragma once

#include <string>

namespace ColorConsole
{

enum class EColor
{
    black,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    lightGray,
    darkGray,
    lightRed,
    lightGreen,
    lightYellow,
    lightBlue,
    lightMagenta,
    lightCyan
};

std::string colorize(const std::string_view s, const EColor c);
std::string foregroundColor(const EColor c);
std::string backgroundColor(const EColor c);
std::string reset();

size_t colorizedSize(const std::string& s);
size_t colorCodeSize();

} // namespace ColorConsole
