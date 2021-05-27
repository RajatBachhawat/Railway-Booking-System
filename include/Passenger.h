
//Rajat Bachhawat
//Roll No: 19CS10073
// #define _DEBUG
#ifndef PASSENGER_H
#define PASSENGER_H

#include "Name.h"
#include "Date.h"
#include "Divyaang.h"
#include "Gender.h"


template<typename T> class BookingCategoryTypes;
template<typename T> class BookingTypes;
class Divyaang;
class DivyaangConcession;
class BookingCategory;
struct PremiumTatkalType;
struct LadiesType;
struct DivyaangType;
struct TatkalType;
struct GeneralType;
struct SeniorCitizenType;

class Passenger
{
private:
    const Name name_;
    const Date dateOfBirth_;
    const Gender &gender_;
    const string aadharNumber_;
    const string mobileNumber_;
    const Divyaang *disabilityType_;
    const string disabilityID_;
    unsigned int age_;
    Passenger(const Name &name, const Date &dateOfBirth, const Gender &gender, const string &aadhar, const string &mobileNo, const Divyaang *disability = NULL, const string &disabilityID = "");    
public:
    static void UnitTest();
    Passenger(const Passenger &copyPassenger);
    bool operator==(const Passenger &p) const;
    static Passenger GetPassenger(const Name &name, const Date &dateOfBirth, const Gender &gender, const string &aadhar, const string &mobileNo, const Divyaang *disability = NULL, const string &disabilityID = "");
    static void IsValid(const Name &name, const Date &dateOfBirth, const Gender &gender, const string &aadhar, const string &mobileNo, const Divyaang *disability , const string &disabilityID );
    friend ostream &operator<<(ostream &out, const Passenger &p);
    friend DivyaangConcession;
    friend BookingCategoryTypes<GeneralType>;
    friend BookingTypes<LadiesType>;
    friend BookingCategoryTypes<TatkalType>;
    friend BookingCategoryTypes<DivyaangType>;
    friend BookingCategoryTypes<PremiumTatkalType>;
    friend BookingTypes<SeniorCitizenType>;
    friend BookingCategoryTypes<LadiesType>;
    friend BookingCategoryTypes<SeniorCitizenType>;
    ~Passenger();
};

#endif //PASSENGER_H