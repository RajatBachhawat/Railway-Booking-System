// #define _DEBUG

//Rajat Bachhawat
//Roll No: 19CS10073
#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//NOT EXTENSIBLE, CONCRETE
class Station
{
private:
    const string name_; //Name of the station, const because it doesnt change
    Station(const char *name);
    Station(const string &name); //Overloaded Ctor with argument: const string &
public:
    static Station GetStation(const string &name);               //Get station object from string
    static Station GetStation(const char *name);                 //Get station object from char*
    static void IsValid(const string &name);                     //Checks validity and throws exception
    static void IsValid(const char *name);                       //Checks validity and throws exception
    static void UnitTest();                                      //Unit Testing function
    string GetName() const;                                      //Returns the name of the station
    double GetDistance(const Station &stationTwo) const;         //Returns distance between calling station and station passed as argument
    friend ostream &operator<<(ostream &out, const Station &st); //Output stream operator
    //Overloaded Ctor with argument: const char *
    Station(const Station &copyStation);     
    ~Station();                                                  //Destructor
};

#endif