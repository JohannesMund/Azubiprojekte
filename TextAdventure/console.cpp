#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
#define _USE_WINDOWS
#else
#define _USE_UNIX
#endif

#include "console.h"
#include "ressources.h"

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
    cout << "[Press <ENTER> to Continue]";
    cin.ignore();
    cout << endl;
}

void Console::cls()
{
#ifdef _USE_WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

char Console::getAcceptableInput(string acceptableChars)
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

void Console::hr()
{
    for (int i = 0; i < Ressources::Settings::consoleWidth; i++)
    {
        cout << "=";
    }

    cout << endl;
}

void Console::echo(const bool on)
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

void Console::printLn(std::string text, const EAlignment align, const bool nobr)
{
    if (text.size() > Ressources::Settings::consoleWidth && !nobr)
    {
        unsigned int written = 0;
        while (written < text.size())
        {
            printLn(text.substr(written, Ressources::Settings::consoleWidth), align, nobr);
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

void Console::br()
{
    cout << endl;
}

std::optional<int> Console::getNumberInputWithEcho(const int min, const int max)
{
    cout << std::format("[Enter number between {} and {} (or anything else to cancel)]", min, max);
    echo(true);

    int input;
    cin >> input;

    echo(false);

    if (input >= min && input <= max)
    {
        return input;
    }
    return {};
}
