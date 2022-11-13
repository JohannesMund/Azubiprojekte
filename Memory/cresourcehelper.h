#ifndef CRESOURCEHELPER_H
#define CRESOURCEHELPER_H

#include <QString>
#include <QStringList>

class CResourceHelper
{
public:
    /**
     * @brief getInstance Getter für den Singleton
     */

    static CResourceHelper* getInstance()
    {
        static CResourceHelper instance;
        return &instance;
    }

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
     * @brief getRecourceFileName Gibt den kompletten Resourcendateinamen für fileName zurück
     * @param fileName der Name der Datei ohne Extension
     * @param resourceDirectoy (optional) das unterverzeichnis, wenn leer wird das aktuelle Verzeichnis genommen
     */
    QString getRecourceFileName(const QString& fileName, const QString& resourceDirectoy = QString());

    /**
     * @brief getRecourceFileName Convinience, da die Resourcen durchnummeriert sind kann man auch eine Zahl angeben
     * @see getRecourceFileName(const QString& fileName, const QString& resourceDirectoy = QString())
     */
    QString getRecourceFileName(const unsigned int fileName, const QString& resourceDirectoy = QString());

    /**
     * @brief getCardBackSide gibt den kompletten Resourcendateinamen der Kartenrückseite zurück
     */
    QString getCardBackSide();

    /**
     * @brief setGameMode ändert den Spielmodus
     * @remark Es sollte einer sein der in getRecourceDirectories angegeben wurde, es findet keine Prüfung statt
     */
    void setGameMode(const QString& s);

private:
    CResourceHelper();

    unsigned int countResourceFiles(const QString dir);

    static const QString _resourceDir;
    static const QString _resourceDirInfoFileName;

    QString _currentResourceDirectory;
    unsigned int _currentCardCount;
};

#endif // CRESOURCEHELPER_H
