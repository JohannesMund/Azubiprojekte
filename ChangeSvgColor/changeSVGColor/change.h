#ifndef CHANGE_H
#define CHANGE_H

#include <QFileInfoList>
#include <fstream>

class Change
{

    QFileInfoList fileList;

public:

    bool fileListValid() const;
    bool isValid(const QString hexCode) const;
    Change(const QFileInfoList list);
    bool colorChange(const QString startColor, const QString newColor);
};

#endif // CHANGE_H
