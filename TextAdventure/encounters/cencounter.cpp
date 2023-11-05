#include "cencounter.h"

CEncounter::CEncounter()
{
}

std::function<bool(const CEncounter*)> CEncounter::nameFilter(const std::string& name)
{
    return [&name](const CEncounter* encounter) { return encounter->name().compare(name) == 0; };
}
