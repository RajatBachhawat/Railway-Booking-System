
//Rajat Bachhawat
//Roll No: 19CS10073
// #define _DEBUG
#ifndef __DATE_H
#define __DATE_H

#include <sstream>
#include <iostream>
#include <string>
using namespace std;
class Date
{
private:    
    typedef unsigned int UINT;
    static const char sMonthNames[][4];                 //Month names
    Date(UINT, UINT, UINT); //Ctor
    enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
    const UINT date_; const Month month_; const UINT year_;  
    
public:
    Date(const Date&);      //Copy constructor
    friend ostream& operator<<(ostream&, const Date&);  //Output streaming operator 
    // Getter for date_
    UINT GetDay() const 
    {
        return date_;
    }
    //Getter for month_
    Month GetMonth() const 
    {
        return month_;
    }
    //Getter for year_
    UINT GetYear() const 
    {
        return year_;
    }
    static Date GetDate(const UINT, const UINT, const UINT);
    static Date Today();
    static void UnitTest(); //For Unit Testing
    static void IsValid(const UINT, const UINT, const UINT);
    static Date GetDate(const string &dateString);
    static void IsValid(const string &dateString);
    UINT CalculateAge() const;
    int CalculateSpan(const Date &d) const;
    bool IsLeapYear() const;

    //operator==
    bool operator==(const Date&) const;
    
    ~Date();                //Dtor
};

#endif