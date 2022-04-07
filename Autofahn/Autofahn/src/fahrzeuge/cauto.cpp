#include "cauto.h"

CAuto::CAuto()
    :CFahrzeug()
{
    c_fahrzeugtyp = "Auto";
}

bool CAuto::IsSchnell() const
{
    if( c_geschwindigkeit > 150)
    {
        return true;
    }

    return false;
}

bool CAuto::IsVoll() const
{
    if(c_mitfahrer.size() >= 5)
    {
        return true;
    }
    return  false;
}

CRotesAuto::CRotesAuto()
    :CAuto()
{
    c_farbe = eRot;
}
