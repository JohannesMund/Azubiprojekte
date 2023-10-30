#pragma once
#include "cmap.h"

#include <string>

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

    virtual char mapSymbol();
    virtual void execute();

private:
    bool _pathNorth = true;
    bool _pathEast = true;
    bool _pathSouth = true;
    bool _pathWest = true;

    bool _encounterPossible = true;

    bool _seen = false;
    std::string _description;
};
