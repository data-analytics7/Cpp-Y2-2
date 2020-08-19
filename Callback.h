#ifndef CALLBACK_H
#define CALLBACK_H

#include <vector>
#include "WindLogType.h"
#include "Date.h"

using std::cout;
using std::endl;
using std::vector;

class Callback
{
    public:
        /**
        * @brief Static callback function that stores required WindLogType data into a vector
        * @param windlog
        * @pre none
        * @post data stored in windLogVec
        * @return void
        */
        static void funcPntr(const WindLogType &windLog);

        static std::vector<WindLogType>windLogVec;  ///static WindLogtype vector
};

#endif // CALLBACK_H

