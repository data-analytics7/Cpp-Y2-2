#ifndef PROCESS_H
#define PROCESS_H

#include <cmath>
#include <map>
#include <vector>
#include "WindLogType.h"
#include "Tree.h"
#include "Callback.h"

class Process
{
    private:

        float avgWindSpeed;     ///average wind speed

        float avgAmbAirTemp;    ///average ambient air temperature

        float totSolarRad;      ///total solar radiation

        map<unsigned, map<unsigned, vector<WindLogType>>> windLogMap;   ///vector inside a nested map

    public:
        /**
         * @brief default constructor for the Process class
         * @param none
         * @pre none
         * @post default values are set
         * @return void
         */
        Process();

        /**
         * @brief get method for average wind speed
         * @param none
         * @pre none
         * @post none
         * @return float
         */
        float GetAvgWindSpeed() const;

        /**
         * @brief set method for average wind speed
         * @param year, month
         * @pre none
         * @post average wind speed will be set for particular months of a year
         * @return void
         */
        void SetAvgWindSpeed(unsigned year, unsigned month);

        /**
         * @brief get method for average ambient air temperature
         * @param none
         * @pre none
         * @post none
         * @return float
         */
        float GetAvgAmbAirTemp() const;

        /**
         * @brief set method for average ambient air temperature
         * @param year, month
         * @pre none
         * @post average ambient air temperature will be set for particular months of a year
         * @return void
         */
        void SetAvgAmbAirTemp(unsigned year, unsigned month);

        /**
         * @brief get method for total solar radiation
         * @param none
         * @pre none
         * @post none
         * @return float
         */
        float GetTotSolarRad() const;

        /**
         * @brief set method for total solar radiation
         * @param year, month
         * @pre none
         * @post total solar radiation will be set for particular months of a year
         * @return void
         */
        void SetTotSolarRad(unsigned year, unsigned month);

        /**
         * @brief get method for highest solar radiation of the given date
         * @param none
         * @pre none
         * @post none
         * @return float
         */
        float GetHighSolarRad(unsigned year, unsigned month, unsigned day) const;

        /**
         * @brief checks if the given year key exists in the map
         * @param year
         * @pre none
         * @post none
         * @return bool
         */
        bool mapKeyExists(unsigned year);

        /**
         * @brief check if the given year and month keys exist in the map
         * @param year, month
         * @pre none
         * @post none
         * @return bool
         */
        bool mapKeyExists(unsigned year, unsigned month);

        /**
         * @brief get method for windlog object
         * @param index, year, month
         * @pre none
         * @post none
         * @return windlog object
         */
        const WindLogType& GetWindLog(unsigned index, unsigned year, unsigned month) const;

         /**
         * @brief set method for windlog object
         * @param windlog object
         * @pre none
         * @post windlog object is set in the map for a given years and months
         * @return void
         */
        void SetWindLog(const WindLogType &W);
};
#endif // PROCESS_H
