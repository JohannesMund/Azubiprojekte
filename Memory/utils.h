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

/**
 * @brief getRecourceDirectories listet die Karten-Unterverzeichnisse auf, und gibt damit die Spielmodi vor
 * @todo eine IndexDatei reinpacken, die infos über den Spielmodus angibt
 */
const QStringList getRecourceDirectories();

/**
 * @brief getCurrentRecourceDirectory gibt das Unterverzeichnis des aktuellen Modus an
 */
QString getCurrentRecourceDirectory();

/**
 * @brief setGameMode ändert den Spielmodus
 * @remark Es sollte einer sein der in getRecourceDirectories angegeben wurde, es findet keine Prüfung statt
 */
void setGameMode(const QString& s);

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
