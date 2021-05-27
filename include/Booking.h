
//Rajat Bachhawat
//Roll No: 19CS10073
#ifndef BOOKING_H
#define BOOKING_H




#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Passenger.h"
#include "BookingCategory.h"
#include "Exceptions.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>


//adding forward declarations

class BookingCategory;
template<typename T> class BookingCategoryTypes;
// Tag-types (forward declaration)
struct SeniorCitizenType;
struct DivyaangType;
struct TatkalType;
struct PremiumTatkalType;
struct GeneralType;
struct LadiesType;
template<typename T>
class BookingTypes;
class Booking {
private:
    Booking(const Booking& book);
protected:
    const Station fromStation_;                 //Stores Departure Station
    const Station toStation_;                   //Stores Arrival Station
    const unsigned int PNR_;                 //Stores the PNR number
    unsigned int fare_;                         //Stores the fare for the trip
    bool bookingStatus_;                    //Booking Status
    string bookingMessage_;                     //Message displayed after booking
    const Date dateOfBooking_;                  //Stores Date of Travel
    const Date dateOfReservation_;          //Stores Date of Reservation
    const BookingClasses &bookingClass_;    //Stores booking class type
    const BookingCategory &bookingCategory_;    //Stores booking category
    const Passenger passenger_;             //Stores the passenger information
    virtual void ComputeFare() = 0;         //Computes the Booking fare and assigns it to Booking::fare_
    Booking(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const BookingClasses &bookingClass, const BookingCategory &bookingCategory, const Passenger &passenger);
    virtual ~Booking();                     //Virtual dtor for polymorphic hierarchy
    //STATIC MEMBERS
    static unsigned int sBookingPNRSerial;  //Stores next free PNR
    static const double sBaseFarePerKM;     //Stores base fare per KM
public:
    static vector<Booking *> sBookings;
    // static function for reserving (uses virtual construction idion)
    static Booking *Reserve(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const BookingClasses &bookingClass, const BookingCategory &bookingCategory, const Passenger &passenger);
    friend ostream &operator<<(ostream &out, const Booking &bk);    //Output streaming operator for this class
    static void UnitTest();
    // Enumerated sub-types
    typedef BookingTypes<SeniorCitizenType> SeniorCitizenBooking;
    typedef BookingTypes<DivyaangType> DivyaangBooking;
    typedef BookingTypes<TatkalType> TatkalBooking;
    typedef BookingTypes<PremiumTatkalType> PremiumTatkalBooking;;
    typedef BookingTypes<GeneralType> GeneralBooking;
    typedef BookingTypes<LadiesType> LadiesBooking;
};

//----------TEMPLATISED SUB CLASSES --------------

template<typename T>
class BookingTypes : public Booking
{
private:
    BookingTypes(const BookingTypes& book);
protected:
    // Calculates the fare for the Booking
    void ComputeFare();
    BookingTypes(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const BookingClasses &bookingClass, const BookingCategory &bookingCategory, const Passenger &passenger);
public:
    // Destructor
    ~BookingTypes();
    static bool CheckEligibility(const Passenger &passenger, const BookingCategory &bookingCategory, const Date &dateOfReservation, const Date &dateOfBooking);
    friend BookingCategoryTypes<T>;
    // Output streaming operator


    friend ostream &operator<<(ostream &out, const BookingTypes<T> &bk){    //Output streaming operator for this class
        out<<"Called from: "<<bk.bookingCategory_.GetName()<<"Booking\n";
        out << bk.bookingMessage_;
        if (true == bk.bookingStatus_)
        {
            out << ":\n";
            out << bk.passenger_ << "\n";
            out << "-- Booking Details -- \n";
            out << "PNR Number = " << bk.PNR_ << "\n";
            out << "From Station = " << bk.fromStation_ << "\n";
            out << "To Station = " << bk.toStation_ << "\n";
            out << "Travel Date = " << bk.dateOfBooking_ << "\n";
            out << "Reservation Date = " << bk.dateOfReservation_ << "\n";
            out << bk.bookingCategory_ << "\n";
            out << bk.bookingClass_;
            out << "Fare = " << bk.fare_ << "\n";
            out << "\n";
            return out;
        }
        out << "\n";
        return out;
    }
};

#endif