#include "cencounter.h"
#include "console.h"

#include <format>

CEncounter::CEncounter()
{
}

void CEncounter::execute(const std::string_view&)
{
    Console::printLn(std::format("Encounter: {}", name()));
    Console::br();
}

std::function<bool(const CEncounter*)> CEncounter::nameFilter(const std::string& name)
{
    return [&name](const CEncounter* encounter) { return encounter->name().compare(name) == 0; };
}

bool CEncounter::canBeExecuted(const EEncounterType& type) const
{
    if ((_type & type) != type)
    {
        return false;
    }
    return !(_isSingleExecution && _hasBeenExecuted);
}
