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
 * @brief zählt die für uns relevanten Resourcendateien in resourceDir
 * @param[in] (optional) resourceDir das unterverzeichnis um das es geht. Ist nichts angegeben wird das
 * _currentResourceDir genommen
 * @remark die Zahl wird gecached, wenn es um das aktelle Verzeichnis geht
 */
unsigned int countCards(const QString& resourceDir = QString());

/**
 * @brief Ermittelt den ResourcenNamen in resourceDir
 * @param[in] (optional) resourceDir das unterverzeichnis um das es geht. Ist nichts angegeben wird das
 * _currentResourceDir genommen
 */
QString getResourceName(const QString& resourceDir = QString());

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
