#pragma once

#include <optional>
#include <string>

namespace ConIO
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

void echo(const bool on);

void printLn(std::string text, const EAlignment align = EAlignment::eLeft, const bool nobr = false);

char getAcceptableInput(std::string accepableChars);
std::optional<int> getNumberInputWithEcho(const int min = 0, const int max = __INT_MAX__);
} // namespace ConIO
