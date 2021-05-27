// #define _DEBUG

//Rajat Bachhawat
//Roll No: 19CS10073
#ifndef RAILWAYS_H
#define RAILWAYS_H

#include <map>
#include <vector>
#include "Station.h"

using namespace std;
class Railways
{
private:
    static const vector<string> sStations;                        //Stations
    static const map<pair<string, string>, double> sDistStations; //pairwise distances between all stations
    Railways();                                                   // constructor
    Railways(const Railways &);                                   //Blocked copy constructor
    Railways operator=(const Railways &);                         //Blocked copy assignment operator
    ~Railways();                                                  //destructor

public:
    static const Railways &Type(); //Returns a singleton const static object of the class
    static void UnitTest();        //Unit Testing
    double GetDistance(const Station &startSt, const Station &endSt) const; //Returns the distance between the start and end stations passed as arguments
    static void IsValid();
    friend ostream &operator<<(ostream &out, const Railways &rlw);          //Output streaming operator 
};

#endif