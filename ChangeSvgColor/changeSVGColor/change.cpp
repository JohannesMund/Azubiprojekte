#include "change.h"
#include <QTextStream>
#include <QRegExp>
#include <QDate>


Change::Change(QFileInfoList list)
{
    fileList = list;
}

bool Change::colorChange(const QString startColor, const QString newColor)
{




    for(auto a : fileList){
        int l = 0;
        auto fileInfo = fileList.at(l);
        auto b = fileInfo.suffix();


        if(b.compare("svg") == 0){

            //vergleich ob die Datei eine .svg Datei ist

            QFile svgFile(a.absoluteFilePath());



            if( !svgFile.open(QFile::ReadOnly | QFile::Text) )
            {
                return false;
            }
             QString s = svgFile.readAll();

                //liest die SVGFile aus und überträgt sie in einen QString

             Qt::CaseSensitivity cs = Qt::CaseInsensitive;


             s.replace(startColor, newColor, cs);

                //überschreibt den alten Hexcode im QString

             svgFile.resize(0);
             svgFile.close();


            if(!svgFile.open(QFile::WriteOnly | QFile::Text)){
                return false;
            }
            QTextStream out(&svgFile);
            out << s;
            svgFile.flush();

                //fügt den geänderten QString in die SVGFile

            svgFile.close();





        }
        else{
            return false;
        }
        l++;
    }

    std::fstream safeColors("Log", std::ios::app);
    safeColors << startColor.toStdString() << " to " << newColor.toStdString() << " ";
    safeColors << QDate::currentDate().toString().toStdString() <<  std::endl;
    safeColors.close();
    //fügt eine neue Zeile in safedColors.txt ein
    //mit altem Hexcode, neuem Hexcode und Datum
    return true;

}

bool Change::fileListValid() const
{
    if(fileList.isEmpty())
    {
        return false;
    }

    return true;
}

bool Change::isValid(const QString hexCode) const
{

    QRegExp exp("#[A-Fa-f0-9]{6}");
    QRegExp ex("#[A-Fa-f0-9]{3}");

    if(exp.exactMatch(hexCode)){
        return true;
    }
    else if(ex.exactMatch(hexCode)){
        return true;
    }
    else {
    return false;
    }

        //prüft ob der eingegebene Hexcode gültig ist

}



