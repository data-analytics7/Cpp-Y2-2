/************************************
*Name: Faiz Syed
*Student ID: 33243485
*Unit: ICT283
*Program: Assignment 2
************************************/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Tree.h"
#include "Date.h"
#include "Time.h"
#include "Process.h"
#include "WindLogType.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::istream;


istream & operator >>( istream & input, Date & DT );
istream & operator >>( istream & input, Process & P );
istream & operator >>( istream & input, WindLogType & WL );
istream & operator >>( istream & input, Time & T );

//Function declarations for main
void choiceOne(Process P);
void choiceTwo(Process P);
void choiceThree(Process P);
void choiceFour(Process P);
void choiceFive(Process P);
string getMonthName(unsigned month);

/****************************************Main Function*********************************************/
int main()
{
    string tmp;    //temp file name
    int choice = 0; //menu choice

    Process P; //object of process class

    ifstream indexFile("../data/met_index.txt");  //path for input file
    if(!indexFile)
        return -1;

    string name;   //storing file name temporarily in this line by line
    cout<<"Reading file data..."<<endl;
    while(getline(indexFile,name))
    {
        cout<<name<<endl;
        ifstream inputFile("../data/" + name);  //path for input file

        while(!inputFile.eof()&&!name.empty())
        {
            getline(inputFile, tmp);    //reading csv file headings
            while(getline(inputFile, tmp))
            {
                if(!tmp.empty())    //does not read empty lines-- pops an error if not used
                {
                    stringstream ss (tmp);
                    ss >> P;
                }
            }
                inputFile.close();
        }
    }
     indexFile.close();




    do{
        //Displays menu
        cout<<"\nMenu:\n"<<endl;
        cout<<"1.	The average wind speed and average ambient air temperature for a specified month and year\n"<<endl
            <<"2.	Average wind speed and average ambient air temperature for each month of a specified year\n"<<endl
            <<"3.	Total solar radiation in kWh/m2 for each month of a specified year\n"<<endl
            <<"4.	Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2"<<endl
            <<"        for each month of a specified year\n"<<endl
            <<"5.      Highest solar radiation for the given date\n"<<endl
            <<"6.      Exit\n"<<endl;
        cout<<"\nEnter your choice: ";
        cin >> choice;
        cout<<endl;

        switch(choice)
        {
            case 1: choiceOne(P); //when user inputs 1
                    break;
            case 2: choiceTwo(P); //when user inputs 2
                    break;
            case 3: choiceThree(P); //when user inputs 3
                    break;
            case 4: choiceFour(P); //when user inputs 4
                    break;
            case 5: choiceFive(P); //when user inputs 5
                    break;
            case 6: cout<<"\nMenu closed!"<<endl; //when user inputs 6
                    break;
            default: cout << "Invalid input: Try Again" << endl;
        }

    }while(choice != 6);

    return 0;
}

/**********Function declarations************/
void choiceOne(Process P)
{
    unsigned year, month; //storing user input
    string monthName; //stores month name as a string

    cout << "Enter Year: " << endl; //getting user input
    cin >> year;
    cout << "Enter Month: " << endl;
    cin >> month;

    if(P.mapKeyExists(year, month)) //checks whether the year and month is present in the data structure
    {
        monthName = getMonthName(month); //converts month to string

        cout << monthName << " " << year << ": ";

        P.SetAvgWindSpeed(year, month); //sets average wind speed for the given month
        cout << fixed << setprecision(2) << P.GetAvgWindSpeed() << " km/h, "; //outputs average wind speed with the precision of 2DP

        P.SetAvgAmbAirTemp(year, month); //sets average ambient temperature for the given month
        cout << fixed << setprecision(2) << P.GetAvgAmbAirTemp() << " degrees C" << endl; //outputs average temperature with the precision of 2DP

    }

    else //if data is not present
    {
        monthName = getMonthName(month);
        cout << monthName << ' ' << year << ": No Data available!" << endl;
    }
}//choiceOne ends

void choiceTwo(Process P)
{
    unsigned year, month; //storing user input
    string monthName; //stores month as a string

    cout << "Enter Year: " << endl; //getting user input
    cin >> year;

    for(month = 1; month <= 12; month++) //looping for every month of the given year
    {
        monthName = getMonthName(month); //getting month as a string

        if(P.mapKeyExists(year, month)) //checking whether year and month exist
        {
            cout << monthName << ": "; //output month as a string

            P.SetAvgWindSpeed(year, month); //sets average wind speed for the given month
            cout << fixed << setprecision(2) << P.GetAvgWindSpeed() << " km/h, "; //outputs average wind speed with the precision of 2DP

            P.SetAvgAmbAirTemp(year, month); //sets average temperature for the given month
            cout << fixed << setprecision(2) << P.GetAvgAmbAirTemp() << " degrees C" << endl; //outputs average ambient temperature with the precision of 2DP
        }

        else //if data is not present
        {
            cout << monthName << ": No Data available for this Month!" << endl;
        }
    }
}//choiceTwo ends

void choiceThree(Process P)
{
    unsigned year, month; //storing user input
    string monthName; //stores month as a string

    cout << "Enter Year: " << endl; //getting user input
    cin >> year;

    for(month = 1; month <= 12; month++) //looping for every month of the given year
    {
        monthName = getMonthName(month); //getting month as a string

        if(P.mapKeyExists(year, month)) //checking whether year and month exists
        {
            P.SetTotSolarRad(year, month); //sets total solar radiation for the given month

            cout << monthName << ": ";

            cout << fixed << setprecision(2) << P.GetTotSolarRad() << " kWh/m^2" << endl; //outputs total solar radiation with the precision of 2DP
        }

        else //if data is not present
        {
            cout << monthName << ": No Data for this Month!" << endl;
        }
    }
}//choiceThree ends

void choiceFour(Process P)
{
    unsigned year, month; //storing user input
    string monthName; //stores month as a string

    ofstream myfile("../data/WindTempSolar.csv");  //output file

    cout << "Enter Year: " << endl; //getting user input
    cin >> year;

    myfile << year << endl;

    for(month = 1; month <= 12; month++) //repeating for everyone month of the chosen year
    {
        monthName = getMonthName(month); //converting month into string format

        if(P.mapKeyExists(year, month)) //checking if the year and month exists
        {
            myfile << monthName << ": ";

            P.SetAvgWindSpeed(year, month); //sets average wind speed for the given month
            myfile << fixed << setprecision(2) << P.GetAvgWindSpeed() << " km/h, "; //outputs average wind speed with the precision of 2DP

            P.SetAvgAmbAirTemp(year, month); //sets average ambient temperature for the given month
            myfile << fixed << setprecision(2) << P.GetAvgAmbAirTemp() << " degrees C, "; //outputs average ambient temperature with the precision of 2DP

            P.SetTotSolarRad(year, month); //sets total solar radiation for a given month
            myfile << fixed << setprecision(2) << P.GetTotSolarRad() << " kWh/m^2" << endl; //outputs total solar radiation with the precision of 2DP

        }
    }

    if(!P.mapKeyExists(year)) //printing a message if no data is present for the given year
    {
        myfile << "No Data";
    }

    cout << "Output successfully written to the file!" << endl;
    myfile.close(); //file close

}//choiceFour ends

void choiceFive(Process P)
{
    unsigned year, month, day; //storing user input
    float tempSolarRad = -1;

    cout << "Enter Year: " << endl; //getting user input
    cin >> year;

    cout << "Enter Month: " << endl;
    cin >> month;

    cout << "Enter Day: " << endl;
    cin >> day;

    if(P.mapKeyExists(year, month)) //checking if the year and month exists
    {
        tempSolarRad = P.GetHighSolarRad(year, month, day); //gets highest solar radiation for the given date

        if(tempSolarRad != -1) //executes if data is there for the given date--being returned from the process class
        {
            cout << "\nDate: " << day << "/" << month << "/" << year << endl;

            cout << "Highest solar radiation for the day: " << tempSolarRad << " W/m2" << endl << endl;

            cout << "Time:" << endl;

            for(unsigned i = 0; i < Callback::windLogVec.size(); i++) //searching for the time when highest solar radiation was recorded
            {
                if(Callback::windLogVec.at(i).GetSolarRad() == tempSolarRad) //looping through the static vector present in Callback class
                {
                    cout << Callback::windLogVec.at(i).GetTime().GetHour() << ":" //prints time(s)
                         << Callback::windLogVec.at(i).GetTime().GetMinute() << endl;
                }
            }
        }

        else
        {
            cout << endl << "No data for the specified date!" << endl;
        }
    }

    else //output message if the key was not found
    {
        cout << endl << "No data for the specified date!" << endl;
    }
}//choiceFive ends

string getMonthName(unsigned month) //returns month name as a string
{
    string monthName;

    switch(month)
    {
        case 1: monthName = "January"; break;
        case 2: monthName = "February"; break;
        case 3: monthName = "March"; break;
        case 4: monthName = "April"; break;
        case 5: monthName = "May"; break;
        case 6: monthName = "June"; break;
        case 7: monthName = "July"; break;
        case 8: monthName = "August"; break;
        case 9: monthName = "September"; break;
        case 10: monthName = "October"; break;
        case 11: monthName = "November"; break;
        case 12: monthName = "December"; break;
    }

    return monthName;
}


/**********Operator overloading***********/

std::istream & operator >>( istream & input, Process & P )
{
    WindLogType wl;

    input >> wl;  //when an object of WindLogType class is used with ">>" operator----refer below
    P.SetWindLog(wl);
    return input;
}

istream & operator >>( istream & input, WindLogType & WL )
{
  Date dt;
  Time t;
  Temperature tm;
  string tmpDate, tmpTime, tmpSpeed, tmpTemp, tmpSolar;

    //reads data value from the WAST field
  getline(input, tmpDate, ' ');
  stringstream ss (tmpDate);
  ss >> dt;
  WL.SetDate(dt);

    //reads time value from WAST field
  getline(input, tmpTime, ',');
  stringstream SS (tmpTime);
  SS >> t;
  WL.SetTime(t);

  //Wind Speed
  for(unsigned i=0; i<10; i++)
    {
        getline(input, tmpSpeed, ',');
    }
  if(tmpSpeed!="N/A")
  {
      float sp = stof(tmpSpeed);
      WL.SetWindSpeed(sp);
  }

  //Solar radiation
  getline(input, tmpSolar, ',');
  if(tmpSolar!="N/A")
  {
    float sl = stof(tmpSolar);
    WL.SetSolarRad(sl);
  }


  //Air temperature
  for(unsigned i=0; i<7; i++)
    {
        getline(input, tmpTemp, ',');
    }
  if(tmpTemp!="N/A")
  {
    float tp = stof(tmpTemp);
    WL.SetAmbAirTemp(tp);
  }

  return input;
}

istream & operator >>( istream & input, Date & DT )
{
  string tmpDay, tmpMonth, tmpYear;

  getline(input, tmpDay, '/');
  int d=stoi(tmpDay);
//  cout<<d<<endl;
  DT.SetDay(d);

  getline(input, tmpMonth, '/');
  int m=stoi(tmpMonth);
 // cout<<m<<endl;
  DT.SetMonth(m);

   getline(input, tmpYear, ' ');
  int y=stoi(tmpYear);
 //cout<<y<<endl;
  DT.SetYear(y);

  return input;
}



istream & operator >>( istream & input, Time & T )
{
  string tmpHour,tmpMin;

  //reads hour value
  getline(input, tmpHour, ':');
  int h=stoi(tmpHour);  //string to integer
  T.SetHour(h);

  //reads minute value
  getline(input, tmpMin, ',');
  int m=stoi(tmpMin);
  T.SetMinute(m);

  return input;
}


