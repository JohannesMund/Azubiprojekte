#pragma once

#include <string>

namespace CC
{

std::string fgBlack();
std::string fgRed();
std::string fgGreen();
std::string fgYellow();
std::string fgBlue();
std::string fgMagenta();
std::string fgCyan();
std::string fgLightGray();
std::string fgDarkGray();
std::string fgLightRed();
std::string fgLightGreen();
std::string fgLightYellow();
std::string fgLightBlue();
std::string fgLightMagenta();
std::string fgLightCyan();

std::string bgBlack();
std::string bgRed();
std::string bgGreen();
std::string bgYellow();
std::string bgBlue();
std::string bgMagenta();
std::string bgCyan();
std::string bgLightGray();
std::string bgDarkGray();
std::string bgLightRed();
std::string bgLightGreen();
std::string bgLightYellow();
std::string bgLightBlue();
std::string bgLightMagenta();
std::string bgLightCyan();

std::string ccReset();
std::string ccInvert();

size_t colorizedSize(const std::string& s);
size_t colorCodeSize();

std::string colorizeString(const std::string_view& s, const std::string_view& c1, const std::string_view& c2);

} // namespace CC
