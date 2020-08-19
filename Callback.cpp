#include "Callback.h"

std::vector<WindLogType> Callback::windLogVec;

void Callback::funcPntr(const WindLogType &windLog)
{
    windLogVec.push_back(windLog);  //inserting the required weather data into the vector to perform operations and calculations
}
