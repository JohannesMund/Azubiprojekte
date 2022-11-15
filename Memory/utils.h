#include <QDirIterator>

#pragma once

/**
 * Hilfsfunktionen
 */

/**
 *@brief Randomizer Hilfsfunktionen rund um den Zufall
 */

namespace Randomizer
{
/**
 * @brief shuffle mischelt einen Vektor
 */
void shuffle(std::vector<unsigned int>& v);
} // namespace Randomizer
