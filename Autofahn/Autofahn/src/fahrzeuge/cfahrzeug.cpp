#include "cfahrzeug.h"

#include <iostream>

using namespace std;

CFahrzeug::CFahrzeug()
{
}


CFahrzeug::~CFahrzeug()
{
}

void CFahrzeug::fahren()
{
    if( c_mitfahrer.size() > 0)
    {
        if( c_mitfahrer.at(0).IsFahrtauglich() == false)
        {
            cout << "Ich wuerde gerne mit meinem " << c_fahrzeugtyp <<  " fahren, " << endl;
            cout << "aber der Fahrer " << c_mitfahrer.at(0).getName() << " ist nicht fahrtauglich." << endl;
        }
        else
        {
            cout << "Ich fahre mit meinem " << c_fahrzeugtyp << endl;
            cout << "Mein " << c_fahrzeugtyp << " ist " << farbe2String(c_farbe) << endl;

            cout << "Der Fahrer ist: " << c_mitfahrer.at(0).getName() << endl;
            cout << "An Bord sind:" << endl;

            for( auto f : c_mitfahrer)
            {
                cout << " * " << f.getName() << endl;
            }

            if( IsSchnell() )
            {
                cout << "Ich fahre echt schnell!" << endl;
            }
        }
    }
    else
    {
        cout << "Ich wuerde gerne mit meinem " << c_fahrzeugtyp <<  " fahren, " << endl;
        cout << "aber keiner sitzt drin" << endl;

    }
}

bool CFahrzeug::einsteigen(const CPerson mitfahrer)
{
    if(IsVoll() == true)
    {
        cout << c_fahrzeugtyp << " ist voll, fuer " << mitfahrer.getName() << " ist kein Platz mehr" << endl;
        return false;
    }

    c_mitfahrer.push_back(mitfahrer);
    return true;
}

string CFahrzeug::farbe2String(const CFahrzeug::EFarben farbe)
{
    std::string f;
    switch(farbe)
    {
        case eRot:
            f = "rot";
            break;
        case eGelb:
            f = "gelb";
            break;
        case eGruen:
            f = "gruen";
            break;
        case eBlau:
            f = "blau";
            break;
        case ePink:
            f = "pink";
        break;
        default:
            f = "keine Ahnung";
            break;
    }
    return f;
}

void CFahrzeug::setFarbe(const CFahrzeug::EFarben farbe)
{
    c_farbe = farbe;
}

void CFahrzeug::setGeschwindigkeit(const int geschwindigkeit)
{
    c_geschwindigkeit = geschwindigkeit;
}

CFahrzeug::EFarben CFahrzeug::getFarbe() const
{
    return c_farbe;
}

int CFahrzeug::getGeschwindigkeit() const
{
    return c_geschwindigkeit;
}




