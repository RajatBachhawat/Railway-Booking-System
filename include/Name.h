
//Rajat Bachhawat
//Roll No: 19CS10073
// #define _DEBUG
#ifndef NAME_H
#define NAME_H
#include <iostream>
#include <string>
using namespace std;
class Passenger;

class Name {
private:
    const string firstName_;
    const string middleName_;
    const string lastName_;
   
public:
    static void UnitTest();

    Name(const string &firstName, const string &lastName, const string &middleName = "");
    ~Name();

    friend ostream &operator<<(ostream &out, const Name &n);
    friend Passenger;
};

#endif //NAME_H