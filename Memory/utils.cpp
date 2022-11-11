#include "utils.h"

#include <algorithm>
#include <random>

namespace
{
QString _currentRecourceDirectory = ":/cards/normal/";
unsigned int countResourceFiles(const QString dir)
{
    QDirIterator it(dir);
    unsigned int count = 0;
    while (it.hasNext())
    {
        it.next();

        if (it.fileName() != ".info")
        {
            count++;
        }
    }
    return count;
}

} // namespace

unsigned int ResourceHelper::countCards(const QString& resourceDir)
{
    if (resourceDir.isEmpty())
    {
        return countResourceFiles(_currentRecourceDirectory);
    }
    return countResourceFiles(QString(":/cards/%1/").arg(resourceDir));
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
}

QString ResourceHelper::getResourceName(const QString& resourceDir)
{
    QString resourceFile;
    if (resourceDir.isEmpty())
    {
        resourceFile = QString("%1.info").arg(_currentRecourceDirectory);
    }
    else
    {
        resourceFile = QString(":/cards/%1/.info").arg(resourceDir);
    }

    QFile f(resourceFile);
    if (!f.open(QIODevice::ReadOnly))
    {
        return resourceDir;
    }
    return f.readLine().trimmed();
}
