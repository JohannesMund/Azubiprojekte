#include "conio.h"
#include "ressources.h"

#include <format>
#include <iostream>
#include <string>
#include <termios.h>

using namespace std;
void ConIO::confirmToContinue()
{
    cout << "[Press <ENTER> to Continue]";
    cin.ignore();
    cout << endl;
}

void ConIO::cls()
{
    system("clear");
}

char ConIO::getAcceptableInput(string acceptableChars)
{
    bool found = false;
    char input;
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
    return input;
}

void ConIO::hr()
{
    for (int i = 0; i < Ressources::Settings::consoleWidth; i++)
    {
        cout << "=";
    }

    cout << endl;
}

void ConIO::echo(const bool on)
{
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
}

void ConIO::printLn(std::string text, const EAlignment align, const bool nobr)
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

void ConIO::br()
{
    cout << endl;
}

std::optional<int> ConIO::getNumberInputWithEcho(const int min, const int max)
{
    cout << std::format("[Enter number between {} and {}]", min, max);

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
