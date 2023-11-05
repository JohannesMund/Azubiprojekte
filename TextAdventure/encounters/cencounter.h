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

    virtual void execute();
    virtual unsigned int encounterChance() const = 0;
    virtual std::string name() const = 0;

    static std::function<bool(const CEncounter*)> nameFilter(const std::string& name);

protected:
    bool canBeExecuted() const;
    bool _isSingleExecution = false;
    bool _hasBeenExecuted = false;
};

#
