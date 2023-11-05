#pragma once

#include <functional>
#include <string>

class CEncounter
{
public:
    CEncounter();
    virtual ~CEncounter()
    {
    }

    virtual void execute() = 0;
    virtual unsigned int encounterChance() const = 0;
    virtual std::string name() const = 0;

    static std::function<bool(const CEncounter*)> nameFilter(const std::string& name);
};

#
