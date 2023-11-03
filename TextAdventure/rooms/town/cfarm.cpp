#include "cfarm.h"
#include "cgamemanagement.h"
#include "console.h"

#include <format>

CFarm::CFarm()
{
}

void CFarm::execute()
{
    char input;
    do
    {
        Console::cls();
        Console::printLn(std::format("Every good town needs a farm. {} has a beautiful one! {} immediately rushes away "
                                     "to play with the many pets around here.",
                                     _cityName,
                                     CGameManagement::getCompanionInstance()->name()));

        std::string acceptableInputs;
        if (CGameManagement::getCompanionInstance()->level() < Ressources::Companion::companionLevelCap)
        {
            Console::printLn(
                std::format("The farmer takes a look at your friend. \"he looks great! for sure, he is one "
                            "awesomne {}! But i am sure, with a little training, he could be even better.\"",
                            CGameManagement::getCompanionInstance()->type()));
            Console::printLn("You are intrigued, so you ask for prices.");
            Console::printLn(
                std::format("The farmer takes another, closer look at {}, and replies \"I think, {} is a good price.\"",
                            CGameManagement::getCompanionInstance()->name(),
                            getTrainingCost()));

            if (getTrainingCost() <= CGameManagement::getPlayerInstance()->gold())
            {
                Console::printLn("This sounds like a bargain!");

                Console::hr();
                Console::printLnWithSpacer(std::format("[T]rain ({} Gold)", getTrainingCost()), "E[x]it");
                acceptableInputs.append("tx");
            }
            else
            {
                Console::printLn("This is too much! a little running around with you should do the same.");
                Console::hr();
                Console::printLnWithSpacer(std::format("Train ({} Gold)", getTrainingCost()), "E[x]it");
                acceptableInputs.append("x");
            }

            acceptableInputs.append("tx");
        }
        else
        {
            Console::printLn("E[x]it", Console::EAlignment::eRight);
            acceptableInputs.append("x");
        }

        input = Console::getAcceptableInput(acceptableInputs);

        if (input == 't')
        {
            train();
            Console::confirmToContinue();
        }

    } while (input != 'x');
}

void CFarm::train()
{
    Console::printLn(std::format("The farmer disappears with {} for a while and comes back. your {} looks different!",
                                 CGameManagement::getCompanionInstance()->name(),
                                 CGameManagement::getCompanionInstance()->name()));

    CGameManagement::getPlayerInstance()->addGold(getTrainingCost() * -1);
    CGameManagement::getCompanionInstance()->evolve();
}

int CFarm::getTrainingCost() const
{
    return 500 + (CGameManagement::getCompanionInstance()->level() * 500 *
                  CGameManagement::getCompanionInstance()->level() * 3);
}
