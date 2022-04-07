#include "search.h"
#include <QDir>


Suche::Suche(const QString pfad)
{
    dataPfad = pfad;
}

QString Suche::hexErkennung(QString hex)
{
    if(hex[4] == ';' || hex[4] == '"' || hex[4] == '/')
    {
        hex.chop(3);
    }

        //erkennt 3stellige Hexcodes

    return hex;
}

void Suche::recurseDir(QDir &d)
{
    QFileInfoList l = d.entryInfoList();


    for( auto i : l)
    {



        if(i.isDir())
        {
            if( i.fileName() == "." || i.fileName() == "..")
            {
                continue;
            }
            d.cd(i.fileName());
            recurseDir(d);
        }
        else
        {
            fileList.append(i);
        }
    }
    d.cdUp();
}

void Suche::list(){



    QDir d(dataPfad);

    if(d.exists())
    {
        recurseDir(d);
    }

        //setzt alle möglichen Dateipfade im angegebenen Ordner in eine Infoliste

}

QFileInfoList Suche::getFileList(){
    return fileList;
}

std::vector<QString> Suche::getSpeicher(){
    return speicher;
}


bool Suche::isSVG(){
    QString b;
    auto a = fileList;
    int c = 0;

    if (a.isEmpty()){
        return false;
    }

    for (auto i : fileList){

        auto fileInfo = a.at(c);
        auto Suffix = fileInfo.suffix();

        if (Suffix.compare("svg") == 0){
            QFile svgFile(i.absoluteFilePath());

           if (!svgFile.open(QFile::ReadOnly | QFile::Text)){
               error.push_back(i.absoluteFilePath());
           }

            //prüfung nach SVGFlie und falls nötigt beendet den Prozess bei einem Fehler

           auto str = svgFile.readAll();
           for(int y = 0; y < str.length(); y++){

               if(str[y] == '#'){

                   QString hex;

                   for (int q = 0; q < 7; q++){
                       hex[q] = str[y + q];
                   }

                        //sucht nach dem Anfang eines Hexcodes und nimmt die nächsten Zeichen auf

                   bool o = true;
                   hex = hexErkennung(hex);

                   for (unsigned int f = 0; f < speicher.size(); f++){

                       if(speicher[f] == hex){
                           o = false;
                           break;
                    }

                        //prüft ob der Hexcode bereits in der Combobox steht

                 }
                 if (o == true){
                    speicher.push_back(hex);

                        //setzt neuen Hexcode an das Ende der Combobox

                 }
              }
               svgFile.close();
           }
           c++;
        }

    }
    return true;
}

void Suche::setDataPfad(QFileInfoList a)
{
   fileList = a;
}

std::vector<QString> Suche::getError()
{
    return error;
}
