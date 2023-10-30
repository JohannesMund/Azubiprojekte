#pragma once

#include <optional>
#include <string>

namespace Console
{
enum class EAlignment
{
    eLeft,
    eCenter,
    eRight
};

void confirmToContinue();

void hr();
void br();
void cls();
void printLn(std::string text, const EAlignment align = EAlignment::eLeft, const bool nobr = false);

void echo(const bool on);

char getAcceptableInput(std::string accepableChars);
std::optional<int> getNumberInputWithEcho(const int min = 0, const int max = __INT_MAX__);
} // namespace Console
