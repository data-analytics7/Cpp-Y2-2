#include "Process.h"
#include "Callback.h"

Process::Process() //constructor
{
    avgWindSpeed = 0;
    avgAmbAirTemp = 0;
    totSolarRad = 0;
}

float Process::GetAvgWindSpeed() const //function to return average wind speed
{
    return avgWindSpeed;
}

void Process::SetAvgWindSpeed(unsigned year, unsigned month) //function to set average wind speed
{
    BST<WindLogType> BST; //creating BST object that goes out of scope when function ends
    avgWindSpeed = 0;

    for(unsigned i = 0; i < windLogMap.at(year).at(month).size(); i++) //loops through map and stores everything in BST object
    {
        BST.insertElement(GetWindLog(i, year, month));
    }

    BST.inOrderTraversal(Callback::funcPntr); //Inorder traversal is performed and result stored in static vector in Callback class

    for(unsigned i = 0; i < Callback::windLogVec.size(); i++) //loops through static vector and gets wind speed for a month
    {
        avgWindSpeed += Callback::windLogVec.at(i).GetWindSpeed();
    }

    avgWindSpeed = avgWindSpeed*3.6;
    avgWindSpeed = avgWindSpeed/Callback::windLogVec.size(); //computing average wind speed for the month
    Callback::windLogVec.clear(); //clearing static vector after use
}

float Process::GetAvgAmbAirTemp() const //function to return average ambient air temperature
{
    return avgAmbAirTemp;
}

void Process::SetAvgAmbAirTemp(unsigned year, unsigned month) //function to set average ambient air temperature
{
    BST<WindLogType> BST; //creating BST object that goes out of scope when function ends
    avgAmbAirTemp = 0;

    for(unsigned i = 0; i < windLogMap.at(year).at(month).size(); i++) //loops through the map and inserts into the BST object
    {
        BST.insertElement(GetWindLog(i, year, month));
    }

    BST.inOrderTraversal(Callback::funcPntr); //Inorder traversal is performed and output is stored in a static vector in Callback class

    for(unsigned i = 0; i < Callback::windLogVec.size(); i++) //loops through the static vector and gets air temperature for a month
    {
        avgAmbAirTemp += Callback::windLogVec.at(i).GetAmbAirTemp();
    }

    avgAmbAirTemp = avgAmbAirTemp/Callback::windLogVec.size(); //setting the average ambient air temperature for the month
    Callback::windLogVec.clear(); //clearing the static vector after use
}

float Process::GetTotSolarRad() const //function to return total solar radiation
{
    return totSolarRad;
}

void Process::SetTotSolarRad(unsigned year, unsigned month) //function to set total solar radiation
{
    BST<WindLogType> BST; //creating BST object that goes out of scope when function ends
    totSolarRad = 0;

    for(unsigned i = 0; i < windLogMap.at(year).at(month).size(); i++) //loops through the map to and stores data into the BST object
    {
        BST.insertElement(GetWindLog(i, year, month));
    }

    BST.inOrderTraversal(Callback::funcPntr); //Inorder traversal is performed and output is stored in static vector in Callback class

    for(unsigned i = 0; i < Callback::windLogVec.size(); i++) //loops through the vector and gets solar radiation for the month
    {
        if(Callback::windLogVec.at(i).GetSolarRad() >= 100) //any value below 100 gets excluded
            totSolarRad += Callback::windLogVec.at(i).GetSolarRad();
    }

    totSolarRad = (totSolarRad*1/6)/1000; //calculating total solar radiation for the month
    Callback::windLogVec.clear(); //clears static vector after use
}

float Process::GetHighSolarRad(unsigned year, unsigned month, unsigned day) const //function to get the highest solar radiation for a month
{
    BST<WindLogType> BST; //creating BST object that goes out of scope when function ends
    float highSolarRad = 0;

    for(unsigned i = 0; i < windLogMap.at(year).at(month).size(); i++) //loops through the map and finds the data for given day
    {
        if(GetWindLog(i, year, month).GetDate().GetDay() == day) //ensures that the data we are getting is of the given day
        {
            BST.insertElement(GetWindLog(i, year, month));
        }
        else //if the day is not found then return is set to -1
        {
            highSolarRad = -1;
        }
    }

    BST.inOrderTraversal(Callback::funcPntr); //traversing the BST and storing the values in a static vector in Callback class

    for(unsigned i = 0; i < Callback::windLogVec.size(); i++) //loops through the static vector
    {
        if(Callback::windLogVec.at(i).GetSolarRad() > highSolarRad) //compares with the present highest solar radiation
        {
            highSolarRad = Callback::windLogVec.at(i).GetSolarRad();
        }
    }

    return highSolarRad;
}


bool Process::mapKeyExists(unsigned year) //function to check if the year key exists
{
    if(windLogMap.find(year) != windLogMap.end()) //if year key is found function returns true
    {
           return true;
    }

    return false;
}

bool Process::mapKeyExists(unsigned year, unsigned month) //function to check if the year and month key exists
{
    map<unsigned, map<unsigned, vector<WindLogType>>>::iterator i = windLogMap.find(year); //iterator to find the key
    if(i != windLogMap.end())
    {
       map<unsigned, vector<WindLogType>> &innerMap = i -> second;

       map<unsigned, vector<WindLogType>>::iterator ii = i->second.find(month);

       if(ii != innerMap.end()) //if the key is found function returns true
       {
           return true;
       }
    }

    return false;
}

const WindLogType & Process::GetWindLog(unsigned index, unsigned year, unsigned month) const //function the return a windlog object
{
    return windLogMap.at(year).at(month).at(index);
}

void Process::SetWindLog(const WindLogType& W) //function to set a windlog object
{
    unsigned y = W.GetDate().GetYear(); //getting the year of the windlog object to use it as a key in the map
    unsigned m = W.GetDate().GetMonth(); //getting the month of the windlog object to use it as a key in the map

    windLogMap[y][m].push_back(W); //pushing the windlog object as the value of month key, which itself is a value of the year key
}

