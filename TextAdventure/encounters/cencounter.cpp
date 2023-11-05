#include "cencounter.h"
#include "console.h"

#include <format>

CEncounter::CEncounter()
{
}

void CEncounter::execute()
{
    Console::printLn(std::format("Encounter: {}", name()));
    Console::br();
}

std::function<bool(const CEncounter*)> CEncounter::nameFilter(const std::string& name)
{
    return [&name](const CEncounter* encounter) { return encounter->name().compare(name) == 0; };
}

bool CEncounter::canBeExecuted() const
{
    return !(_isSingleExecution && _hasBeenExecuted);
}
