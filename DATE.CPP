// DATE.CPP - Course class implementation

#include "date.h"

Date::Date()    //default constructor
{
    month = 0;
    day = 0;
    year = 0 ;
}

Date::Date(unsigned d, unsigned mon, unsigned yr)
{
    day = d;
    month = mon;
    year = yr;
}


unsigned Date::GetDay() const
{
    return day;
}

unsigned Date::GetMonth() const
{
    return month;
}

std::string Date::GetMonthName(unsigned mon)    //returns month value in string for displaying as output
{
   const char * months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   monthName = months[mon-1];
   return monthName;
}

unsigned Date::GetYear() const
{
    return year;
}

/******************************************Set Functions***********************************************************/
void Date::SetDay(unsigned d)
{
    day = d;
}

void Date::SetMonth(int mon)
{
    month = mon;
}

void Date::SetYear(unsigned yr)
{
    year = yr;

}

bool Date::operator < ( const Date& DT) const
{
    if(year < DT.GetYear())
    {
        return true;
    }
    else
        if(year==DT.GetYear()&& month < DT.GetMonth())
        {
            return true;
        }
        else
            if(year==DT.GetYear()&& month == DT.GetMonth()&& day < DT.GetDay())
            {
                return true;
            }

    return false;

}

bool Date::operator > ( const Date& DT) const
{
    if(year > DT.GetYear())
    {
        return true;
    }
    else
        if(year == DT.GetYear()&& month > DT.GetMonth())
        {
            return true;
        }
        else
            if(year==DT.GetYear()&& month == DT.GetMonth()&& day > DT.GetDay())
            {
                return true;
            }

    return false;

}

bool Date::operator == ( const Date& DT) const
{
    if(year == DT.GetYear() && month == DT.GetMonth() && day == DT.GetDay())
    {
        return true;
    }
    return false;

}
