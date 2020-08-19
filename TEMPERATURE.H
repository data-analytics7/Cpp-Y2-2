#ifndef TEMPERATURE_H
#define TEMPERATURE_H


class Temperature
{

private:
  float temperature;  ///hour

public:

    /**
    * @brief default constructor for Temperature class
    * @param none
    * @pre none
    * @post sets temperature to default values
    * @return none
    */
    Temperature();

    /**
    * @brief get method that returns ambient temperature value
    * @param none
    * @pre none
    * @post gets hour
    * @return float
    */
    float GetTemp() const;

    /**
    * @brief set method that sets value of ambient air temperature
    * @param t
    * @pre none
    * @post sets value of hour
    * @return void
    */
    void SetTemp(float t);

    /**
    * @brief Greater than comparison operator overloading
    * @param TM
    * @pre none
    * @post greater than operator overloaded
    * @return bool
    */
    bool operator > ( const Temperature& TM) const;

    /**
    * @brief Less than comparison operator overloading
    * @param TM
    * @pre none
    * @post less than operator overloaded
    * @return bool
    */
    bool operator < ( const Temperature& TM) const;

};

#endif // TEMPERATURE_H
