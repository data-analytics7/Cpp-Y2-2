#ifndef WINDLOGTYPE_H
#define WINDLOGTYPE_H
#include "Date.h"
#include "Time.h"
#include "Temperature.h"


class WindLogType
{
private:
    float speed, temp, solar;  /// speed, temperature and solar radiation
    Date d; ///object of Date class
    Time t; ///object of Time class
    Temperature tm; ///object of Temperature class

public:
     /**
     * @brief default constructor for WindLogType class
     * @param none
     * @pre none
     * @post default values are set
     * @return void
     */
    WindLogType();

    /**
     * @brief get method for wind speed
     * @param none
     * @pre none
     * @post none
     * @return float
     */
    float GetWindSpeed() const;

    /**
     * @brief set method for wind speed
     * @param s
     * @pre none
     * @post none
     * @return void
     */
    void SetWindSpeed(float s);

    /**
    * @brief get method that returns date value from the Date class
    * @param none
    * @pre none
    * @post gets date
    * @return Date
    */
    Date GetDate() const;

    /**
    * @brief set method used to set value of date
    * @param tempDate
    * @pre none
    * @post sets value of date
    * @return void
    */
    void SetDate(const Date &tempDate);

    /**
    * @brief get method that returns time value from the Time class
    * @param none
    * @pre none
    * @post gets time
    * @return Time
    */
    Time GetTime() const;

    /**
    * @brief set method used to set value of time
    * @param tempTime
    * @pre none
    * @post sets value of time
    * @return void
    */
    void SetTime(const Time &tempTime);

    /**
    * @brief get method that returns temperature value
    * @param none
    * @pre none
    * @post gets temperature
    * @return float
    */
    float GetAmbAirTemp() const;

    /**
    * @brief set method used to set value of temperature
    * @param t
    * @pre none
    * @post sets value of temperature
    * @return void
    */
    void SetAmbAirTemp(float t);

    /**
    * @brief get method that returns solar radiation value
    * @param none
    * @pre none
    * @post gets solar radiation value
    * @return float
    */
    float GetSolarRad() const;

    /**
    * @brief set method used to set value of solar radiation
    * @param s
    * @pre none
    * @post sets value of solar radiation
    * @return void
    */
    void SetSolarRad(float s);

    /**
    * @brief Greater than comparison operator overloading
    * @param W
    * @pre none
    * @post greater than operator overloaded
    * @return bool
    */
    bool operator > (const WindLogType& W) const;

     /**
    * @brief Less than comparison operator overloading
    * @param W
    * @pre none
    * @post less than operator overloaded
    * @return bool
    */
    bool operator < (const WindLogType& W) const;

    /**
    * @brief Equality operator overloading
    * @param W
    * @pre none
    * @post equality operator overloaded
    * @return bool
    */
    bool operator == (const WindLogType& W) const;

};

#endif // WINDLOGTYPE_H
