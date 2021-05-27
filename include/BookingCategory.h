
//Rajat Bachhawat
//Roll No: 19CS10073
#ifndef BOOKING_CATEGORY_H
#define BOOKING_CATEGORY_H

#include <sstream>
#include <string>
#include "Booking.h"
#include <iostream>
#include "Exceptions.h"
class Passenger;
class Booking;
using namespace std;

template <typename T>
class BookingCategoryTypes;
// Tag-types
struct GeneralType
{
};
struct PremiumTatkalType
{
};
struct LadiesType
{
};
struct SeniorCitizenType
{
};
struct DivyaangType
{
};
struct TatkalType
{
};

class BookingCategory
{
private:
    BookingCategory(const BookingCategory &C);

protected:
    BookingCategory();
    ~BookingCategory();

public:
    static void UnitTest();
    // pure virtuals
    virtual string GetName() const = 0;
    virtual void Eligibility(const Passenger &passenger, const Date &dateOfReservation, const Date &dateOfBooking) const = 0;
    // enables virtual construction idiom by targetting corresponding booking sub-type
    virtual Booking *ReserveInCategory(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const BookingClasses &bookingClass, const Passenger &passenger) const = 0;
    
    friend ostream &operator<<(ostream &out, const BookingCategory &bcat);
    // Enumerated sub-types
    typedef BookingCategoryTypes<TatkalType> Tatkal;
    typedef BookingCategoryTypes<PremiumTatkalType> PremiumTatkal;
    typedef BookingCategoryTypes<GeneralType> General;
    typedef BookingCategoryTypes<LadiesType> Ladies;
    typedef BookingCategoryTypes<SeniorCitizenType> SeniorCitizen;
    typedef BookingCategoryTypes<DivyaangType> DivyaangCat;
};

//----------TEMPLATISED SUB CLASSES--------------

template <typename T>
class BookingCategoryTypes : public BookingCategory
{
private:
    BookingCategoryTypes()
    {
#ifdef _DEBUG
        cout << *this << " --CONSTRUCTED" << endl;
#endif
    };
    ~BookingCategoryTypes()
    {
#ifdef _DEBUG
        cout << *this << "  --DESTRUCTED" << endl;
#endif
    };
    BookingCategoryTypes(const BookingCategoryTypes &C);
    static const string sName;

public:
    static const BookingCategoryTypes<T> &Type()
    {
        static const BookingCategoryTypes<T> obj;
        return obj;
    }
    friend ostream &operator<<(ostream &out, const BookingCategoryTypes<T> &bcat)
    {
        out << "Booking Category = " << bcat.GetName();
        return out;
    }
    string GetName() const
    {
        return BookingCategoryTypes<T>::sName;
    }
    void Eligibility(const Passenger &passenger, const Date &dateOfReservation, const Date &dateOfBooking) const;
    Booking *ReserveInCategory(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const BookingClasses &bookingClass, const Passenger &passenger) const
    {
        bool result = false;
        try
        {
            result = BookingTypes<T>::CheckEligibility(passenger, BookingCategoryTypes<T>::Type(), dateOfReservation, dateOfBooking);
        }
        catch (Bad_Booking &bk)
        {//RETHROW
            throw;
        }
        return new BookingTypes<T>(fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, BookingCategoryTypes<T>::Type(), passenger);
    }
};

#endif //BOOKING_CATEGORY_H