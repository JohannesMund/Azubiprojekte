#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
#define _USE_WINDOWS
#else
#define _USE_UNIX
#endif

#include "console.h"
#include "cgamemanagement.h"
#include "ressources.h"

#include <algorithm>
#include <format>
#include <iostream>
#include <string>

#ifdef _USE_WINDOWS
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#endif

using namespace std;
void Console::confirmToContinue()
{
    cout << "[Press [c] to Continue]";
    getAcceptableInput("c");
    cout << endl;
}

void Console::cls(const bool bHud)
{
#ifdef _USE_WINDOWS
    system("cls");
#else
    system("clear");
#endif
    if (bHud)
    {
        CGameManagement::getInstance()->printHUD();
    }
}

char Console::getAcceptableInput(string_view acceptableChars)
{
    bool found = false;
    char input;
#ifdef _USE_WINDOWS
    while (!found)
    {
        input = _getch();
        if (acceptableChars.find(input) != string::npos)
        {
            found = true;
        }
    }
#else
    system("stty raw");
    while (!found)
    {
        input = getchar();

        if (acceptableChars.find(input) != string::npos)
        {
            found = true;
        }
    }
    system("stty cooked");
#endif
    return input;
}

void Console::br()
{
    cout << endl;
}

void Console::hr()
{
    for (int i = 0; i < Ressources::Settings::consoleWidth; i++)
    {
        cout << "=";
    }

    cout << endl;
}

void Console::setEcho(const bool on)
{

#ifdef _USE_WINDOWS
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    if (on)
    {
        SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT);
    }
    else
    {
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    }
#else
    struct termios term;
    tcgetattr(fileno(stdin), &term);

    if (on)
    {
        term.c_lflag |= ECHO;
    }
    else
    {
        term.c_lflag &= ~ECHO;
    }

    tcsetattr(fileno(stdin), 0, &term);
#endif
}

void Console::printLn(std::string text, const EAlignment align)
{
    if (text.size() > Ressources::Settings::consoleWidth)
    {
        unsigned int written = 0;
        while (written < text.size())
        {
            printLn(text.substr(written, Ressources::Settings::consoleWidth), align);
            written += Ressources::Settings::consoleWidth;
        }
    }
    else
    {
        if (align == EAlignment::eCenter)
        {
            bool toggle = false;
            while (text.size() < Ressources::Settings::consoleWidth)
            {
                text.insert(toggle ? 0 : text.size(), 1, ' ');
                toggle = !toggle;
            }
        }
        else if (align == EAlignment::eRight)
        {
            while (text.size() < Ressources::Settings::consoleWidth)
            {
                text.insert(0, 1, ' ');
            }
        }
        cout << text << endl;
    }
}

std::optional<int> Console::getNumberInputWithEcho(const int min, const int max)
{

    cout << std::format("[Enter number between {} and {} (or 'x' to cancel)]", min, max);

    while (true)
    {
        setEcho(true);
        std::string input;
        cin >> input;
        setEcho(false);

        if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
        {
            int dIn = std::stoi(input);

            if (dIn >= min && dIn <= max)
            {
                return dIn;
            }
        }

        if (input.find('x') != std::string::npos)
        {
            return {};
        }
    }
}

void Console::printLnWithSpacer(const std::string& text1, const std::string& text2)
{
    if (text1.size() + text2.size() > Ressources::Settings::consoleWidth)
    {
        printLn(text1);
        printLn(text2, EAlignment::eRight);
        return;
    }

    std::string out(text1);
    while (out.size() + text2.size() < Ressources::Settings::consoleWidth)
    {
        out.append(" ");
    }
    out.append(text2);
    printLn(out);
}
