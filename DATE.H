// COURSE.H - Course class definition
// author Faiz

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string.h>
using std::string;

class Date
{

private:
  unsigned month;  ///month
  unsigned day; ///day
  unsigned year;  ///year
  string monthName; ///month in string format


public:

    /**
    * @brief default constructor for Date class
    * @param none
    * @pre none
    * @post sets default values to zero
    * @return
    */
    Date();

    /**
    * @brief constructor
    * @param d, mon, yr
    * @pre none
    * @post set to default values
    * @return none
    */
    Date(unsigned d, unsigned mon, unsigned yr);

    /**
    * @brief get method that returns day
    * @param none
    * @pre none
    * @post gets day
    * @return unsigned
    */
    unsigned GetDay() const;

    /**
    * @brief set method that sets the value of day
    * @param d
    * @pre none
    * @post sets value of day
    * @return void
    */
    void SetDay(unsigned d);

    /**
    * @brief get method that returns month
    * @param none
    * @pre none
    * @post gets month
    * @return unsigned
    */
    unsigned GetMonth() const;

    /**
    * @brief Get function that returns month name as a string
    * @param none
    * @pre none
    * @post gets month
    * @return string - month
    */
    string GetMonthName(unsigned mon);

    /**
    * @brief set method that sets the value of month
    * @param mon
    * @pre none
    * @post sets value of month
    * @return void
    */
    void SetMonth(int mon);

    /**
    * @brief get method that returns year
    * @param none
    * @pre none
    * @post gets year
    * @return unsigned
    */
    unsigned GetYear() const;

    /**
    * @brief set method that sets the value of year
    * @param yr
    * @pre none
    * @post sets value of year
    * @return void
    */
    void SetYear(unsigned yr);

    /**
    * @brief Less than comparison operator overloading
    * @param DT
    * @pre none
    * @post less than operator overloaded
    * @return bool
    */
    bool operator < ( const Date& DT) const;

    /**
    * @brief Greater than comparison operator overloading
    * @param DT
    * @pre none
    * @post greater than operator overloaded
    * @return bool
    */
    bool operator > ( const Date& DT) const;

    /**
    * @brief Equality operator overloading
    * @param DT
    * @pre none
    * @post equality operator overloaded
    * @return bool
    */
    bool operator == ( const Date& DT) const;

};

#endif
