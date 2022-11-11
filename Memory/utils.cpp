#include "utils.h"

#include <algorithm>
#include <random>

namespace
{
unsigned int _numRecourceFiles = (unsigned)-1;
QString _currentRecourceDirectory = ":/cards/normal/";
unsigned int countRecourceFiles(const QString dir)
{
    QDirIterator it(dir);
    unsigned int count = 0;
    while (it.hasNext())
    {
        it.next();
        count++;
    }

    _numRecourceFiles = count;
    return _numRecourceFiles;
}

} // namespace

unsigned int ResourceHelper::countCards()
{
    if (_numRecourceFiles == (unsigned)-1)
    {
        countRecourceFiles(_currentRecourceDirectory);
    }
    return _numRecourceFiles;
}

void Randomizer::shuffle(std::vector<unsigned int>& v)
{
    // Randomisierer initialisieren
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine{seed};

    // Zahlen schön mischeln
    std::shuffle(v.begin(), v.end(), rng);
}

QString ResourceHelper::getCurrentRecourceDirectory()
{
    return _currentRecourceDirectory;
}

const QStringList ResourceHelper::getRecourceDirectories()
{
    QStringList l;
    QDirIterator it(":/cards/");
    while (it.hasNext())
    {
        it.next();
        l << it.fileName();
    }
    return l;
}

void ResourceHelper::setGameMode(const QString& s)
{
    _currentRecourceDirectory = QString(":/cards/%1/").arg(s);
    _numRecourceFiles = (unsigned)-1;
}
