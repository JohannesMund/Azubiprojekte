#pragma once

#include <QPair>

/**
 * @brief The PlayFieldCoords struct
 * Koordinaten auf dem Spielfeld, mit valid funktion
 */
struct PlayFieldCoords : public QPair<int, int>
{
public:
    PlayFieldCoords();

    PlayFieldCoords(const PlayFieldCoords&);

    PlayFieldCoords(const int i1, const int i2);

    bool isValid() const;
    int x() const;
    int y() const;
};
