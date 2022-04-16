#ifndef TESTDEFINES_H
#define TESTDEFINES_H

#include "playermanagement.h"
#include "playfield.h"
#include "playfieldcoords.h"

Q_DECLARE_METATYPE(PlayerManagement::Player)
Q_DECLARE_METATYPE(PlayFieldCoords)
using PlayFieldRepresentation = QVector<QPair<PlayFieldCoords, PlayerManagement::Player>>;

inline PlayField populatePlayField(const PlayFieldRepresentation& fieldRep)
{

    PlayField field;
    for (const auto f : fieldRep)
    {
        field.set(f.first, f.second);
    }
    return field;
}

#endif // TESTDEFINES_H
