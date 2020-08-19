#include "time.h"

Time::Time()  //default constructor
{
    hour = 0;
    minute = 0;
}

Time::Time(unsigned h, unsigned m)
{
    hour = h;
    minute = m;
}


unsigned Time::GetHour() const
{
    return hour;
}

unsigned Time::GetMinute() const
{
    return minute;
}

/****************Set Methods******************/
void Time::SetHour(unsigned h)
{
    hour = h;
}

void Time::SetMinute(unsigned m)
{
    minute = m;
}


bool Time::operator > ( const Time& T) const
{
    if(hour > T.GetHour())
    {
        return true;
    }
    else
        if (hour == T.GetHour() && minute > T.GetMinute())
        {
            return true;
        }

    return false;
}

bool Time::operator < ( const Time& T) const
{
    if(hour < T.GetHour())
    {
        return true;
    }
    else
        if (hour == T.GetHour() && minute < T.GetMinute())
        {
            return true;
        }

    return false;
}

bool Time::operator == ( const Time& T) const
{

    if(hour == T.GetHour())
    {
        if(minute == T.GetMinute())
        {
            return true;
        }
    }

    return false;
}

