#include "Temperature.h"

Temperature::Temperature()
{
    temperature = 0;
}

float Temperature::GetTemp() const
{
    return temperature;
}

/*************Set Methods***************/
void Temperature::SetTemp(float t)
{
    temperature = t;
}

bool Temperature::operator > ( const Temperature& TM) const
{
    if (temperature > GetTemp())
        return true;

    return false;
}

bool Temperature::operator < ( const Temperature& TM) const
{
    if (temperature < GetTemp())
        return true;

    return false;
}
