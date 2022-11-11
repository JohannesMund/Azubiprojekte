#include <QDirIterator>

#pragma once

/**
 * Hilfsfunktionen
 */

/**
 * @brief ResourceHelper Hilfsfunktionen bzgl. der Resourcen
 */
namespace ResourceHelper
{

/**
 * @brief zählt die für uns relevanten Resourcendateien
 * @remark die Zahl wird gecached
 */
unsigned int countCards();
QString getCurrentRecourceDirectory();
} // namespace ResourceHelper

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
