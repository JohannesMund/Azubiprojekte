#include "cdeadhero.h"
#include "cgamemanagement.h"
#include "cjunkarmor.h"
#include "cjunkshield.h"
#include "cjunksword.h"
#include "console.h"

#include <format>

CDeadHero::CDeadHero() : CEncounter()
{
    _isSingleExecution = true;
}

void CDeadHero::execute()
{
    CEncounter::execute();
    _hasBeenExecuted = true;

    CJunkSword sword;
    CJunkShield shield;

    Console::printLn(std::format(
        "Making your way through the world of adventure, you find a body, lying next to a tree. It seems to be a hero, "
        "just like you. He wears the same {} as you, and he wears the same {} as you. But, he was not as lucky as you.",
        sword.name(),
        shield.name()));
    Console::printLn("He is dead. Definitely dead. He lies in a puddle of his own blood, the limbs broken, all his "
                     "treasure gone (if he even had som treasure at all). All of his treasure?");
    Console::printLn("Maybe, just maybe you should have a look.");
    Console::br();
    Console::printLnWithSpacer("[S]earch the body", "[G]o away");
    char input = Console::getAcceptableInput("sg");

    Console::br();
    if (input == 'g')
    {
        Console::printLn(
            "Better safe than sorry is the motto of this adventure. You leave the poor guy be, and leave.");
        Console::printLn("You feel, that this is the last time, you have seen him");
        return;
    }

    Console::printLn("You approach the body, and one thing is for sure: This guy is dead. The opponent must have had "
                     "enormous claws (or a Nokia 3210). But one thing survived the fight. His shirt seems pretty "
                     "unharmed. It could be very usefull for you too.");
    Console::printLn("You wonder, if you should take it.");

    Console::br();
    Console::printLnWithSpacer("[T]ake T-shirt", "[G]o away");
    input = Console::getAcceptableInput("tg");

    Console::br();
    if (input == 'g')
    {
        Console::printLn(
            "Better safe than sorry is the motto of this adventure. You leave the poor guy be, and leave.");
        Console::printLn("You feel, that this is the last time, you have seen him");
        return;
    }

    Console::printLn("Why waste a valuable item, when it can protect you? You take the T-shirt and equip it. You now "
                     "have a shiny new armor to protect you.");

    CGameManagement::getInventoryInstance()->addItem(new CJunkArmor());
    Console::br();
}

unsigned int CDeadHero::encounterChance() const
{
    if (!canBeExecuted())
    {
        return 0;
    }
    return 1;
}

std::string CDeadHero::name() const
{
    return "Dead Hero";
}
