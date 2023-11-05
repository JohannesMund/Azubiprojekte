#pragma once
#include "cmap.h"

#include <string>

class CTask;
class CRoom
{
public:
    CRoom();
    virtual ~CRoom();

    void blockPath(const CMap::EDirections dir, const bool block);

    bool north() const;
    bool east() const;
    bool south() const;
    bool west() const;

    bool seen() const;
    void setSeen(const bool b);

    bool showInFogOfWar() const;

    virtual char mapSymbol();
    virtual void execute();

    void setTask(CTask* task);
    bool isTaskPossible() const;
    bool hasTask() const;

protected:
    bool _pathNorth = true;
    bool _pathEast = true;
    bool _pathSouth = true;
    bool _pathWest = true;

    bool _encounterPossible = true;
    bool _taskPossible = true;

    bool _showInFogOfWar = false;
    bool _seen = false;
    std::string _description;

    CTask* _task = nullptr;
};
