#include "cpanzer.h"

CPanzer::CPanzer()
    :CFahrzeug()
{
    c_fahrzeugtyp = "Panzer";
    c_farbe = eGruen;
}

bool CPanzer::IsSchnell() const
{
    if( c_geschwindigkeit > 30)
    {
        return true;
    }

    return false;
}

bool CPanzer::IsVoll() const
{
    if(c_mitfahrer.size() > 8)
    {
        return true;
    }
    return  false;
}
