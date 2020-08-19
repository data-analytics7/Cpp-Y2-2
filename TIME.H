#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string.h>

class Time
{
private:
  unsigned hour;   ///hour
  unsigned minute;    ///minute


public:

     /**
      * @brief default constructor for Time class
      * @param none
      * @pre none
      * @post sets time to default values
      * @return none
      */
    Time();

      /**
      * @brief constructor
      * @param h, m
      * @pre none
      * @post none
      * @return none
      */
    Time(unsigned h, unsigned m);

      /**
      * @brief get method that returns hour value
      * @param none
      * @pre none
      * @post gets hour
      * @return unsigned
      */
    unsigned GetHour() const;

      /**
      * @brief set method that sets value of hour
      * @param h
      * @pre none
      * @post sets value of hour
      * @return void
      */
    void SetHour(unsigned h);

      /**
      * @brief get method that returns minute value
      * @param none
      * @pre none
      * @post gets minutes
      * @return unsigned
      */
    unsigned GetMinute() const;

      /**
      * @brief set method that sets value of minute
      * @param m
      * @pre none
      * @post sets value of minute
      * @return void
      */
    void SetMinute(unsigned m);

    /**
    * @brief Greater than comparison operator overloading
    * @param T
    * @pre none
    * @post greater than operator overloaded
    * @return bool
    */
    bool operator > ( const Time& T) const;

    /**
    * @brief Less than comparison operator overloading
    * @param T
    * @pre none
    * @post less than operator overloaded
    * @return bool
    */
    bool operator < ( const Time& T) const;

    /**
    * @brief Equality operator overloading
    * @param T
    * @pre none
    * @post equality operator overloaded
    * @return bool
    */
    bool operator == ( const Time& T) const;

};

#endif

