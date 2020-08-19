#include "WindLogType.h"

WindLogType::WindLogType()
{
    speed = 0;
    solar = 0;
    temp = 0;
}

float WindLogType::GetWindSpeed() const
{
    return speed;
}

void WindLogType::SetWindSpeed(float s)
{
    speed = s;
}

Date WindLogType::GetDate() const
{
    return d;
}

void WindLogType::SetDate(const Date &tempDate)
{
    d = tempDate;
}

Time WindLogType::GetTime() const
{
    return t;
}

void WindLogType::SetTime(const Time &tempTime)
{
    t = tempTime;
}

float WindLogType::GetAmbAirTemp() const
{
    return temp;
}
void WindLogType::SetAmbAirTemp(float t)
{
    temp = t;
}

float WindLogType::GetSolarRad() const
{
   return solar;
}

void WindLogType::SetSolarRad(float s)
{
    solar = s;
}

bool WindLogType::operator > ( const WindLogType& W) const
{                        /*objects of date class are being compared so the comparison
                            operator of the date class gets invoked and used*/
    if(d > W.GetDate())
    {
        return true;
    }
    else
        if(d == W.GetDate() && t > W.GetTime())
        {
            return true;
        }

    return false;
}

bool WindLogType::operator < ( const WindLogType& W) const
{
    if(d < W.GetDate())
    {
       return true;
    }

    else
        if(d == W.GetDate() && t < W.GetTime())
        {
            return true;
        }

    return false;
}

bool WindLogType::operator == ( const WindLogType& W) const
{                                           //Equality operator overloaded

    if(d == W.GetDate())
    {
        if(t == W.GetTime())
        {
            return true;
        }
    }

    return false;
}
