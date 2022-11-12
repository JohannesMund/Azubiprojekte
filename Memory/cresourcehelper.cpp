#include "cresourcehelper.h"

#include <QDirIterator>
#include <QFile>

const QString CResourceHelper::_resourceDir = ":/cards/%1/";
const QString CResourceHelper::_resourceDirInfoFileName = ".info";

CResourceHelper::CResourceHelper() : _currentRecourceDirectory(_resourceDir.arg("normal"))
{
    _currentCardCount = countCards("normal");
}

unsigned int CResourceHelper::countCards(const QString& resourceDir)
{
    if (resourceDir.isEmpty())
    {
        return _currentCardCount;
    }
    return countResourceFiles(_resourceDir.arg(resourceDir));
}

QString CResourceHelper::getCurrentRecourceDirectory()
{
    return _currentRecourceDirectory;
}

const QStringList CResourceHelper::getRecourceDirectories()
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

void CResourceHelper::setGameMode(const QString& s)
{
    _currentRecourceDirectory = _resourceDir.arg(s);
    _currentCardCount = countCards(s);
}

QString CResourceHelper::getResourceName(const QString& resourceDir)
{
    QString resourceFile;
    if (resourceDir.isEmpty())
    {
        resourceFile = QString("%1.info").arg(_currentRecourceDirectory);
    }
    else
    {
        resourceFile = _resourceDir.arg(resourceDir) + _resourceDirInfoFileName;
    }

    QFile f(resourceFile);
    if (!f.open(QIODevice::ReadOnly))
    {
        return resourceDir;
    }
    return f.readLine().trimmed();
}

unsigned int CResourceHelper::countResourceFiles(const QString dir)
{
    QDirIterator it(dir);
    unsigned int count = 0;
    while (it.hasNext())
    {
        it.next();

        if (it.fileName() != _resourceDirInfoFileName)
        {
            count++;
        }
    }
    return count;
}
