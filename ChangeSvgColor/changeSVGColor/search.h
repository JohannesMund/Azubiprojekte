#ifndef SEARCH_H
#define SEARCH_H


#include <vector>
#include <QString>
#include <QFile>
#include <QFileInfoList>

class Suche
{
private:
    std::vector<QString> speicher;
    QFileInfoList fileList;
    QString dataPfad;
    void recurseDir(QDir &d);
    std::vector<QString> error;


public:
    Suche(const QString pfad);
    void list();
    QFileInfoList getFileList();
    bool isSVG();
    std::vector<QString> getSpeicher();
    void setDataPfad(QFileInfoList a);
    QString hexErkennung(QString hex);
    std::vector<QString> getError();
};

#endif // SEARCH_H
