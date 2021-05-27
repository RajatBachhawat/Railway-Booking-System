//Rajat Bachhawat
//19CS10073
#include "Test.h"

//CHANGEABLE FROM APPLICATION SPACE:
template<> const double BookingClasses::ACFirstClass::sLoadFactor =        6.50;
template<> const double BookingClasses::ACChairCar::sLoadFactor =          2.00;
template<> const double BookingClasses::SecondSitting::sLoadFactor =       0.60;
template<> const double BookingClasses::ExecutiveChairCar::sLoadFactor =   5.00;
template<> const double BookingClasses::FirstClass::sLoadFactor =          3.00;
template<> const double BookingClasses::AC3Tier::sLoadFactor =             2.50;
template<> const double BookingClasses::Sleeper::sLoadFactor =             1.00;
template<> const double BookingClasses::AC2Tier::sLoadFactor =             4.00;
template<> const bool BookingClasses::ACFirstClass::sLuxury =              true;
template<> const bool BookingClasses::ExecutiveChairCar::sLuxury =         true;
template<> const bool BookingClasses::AC3Tier::sLuxury =                   false;
template<> const bool BookingClasses::Sleeper::sLuxury =                   false;
template<> const bool BookingClasses::ACChairCar::sLuxury =                false;
template<> const bool BookingClasses::AC2Tier::sLuxury =                   false;
template<> const bool BookingClasses::FirstClass::sLuxury =                true;
template<> const bool BookingClasses::SecondSitting::sLuxury =             false;

// Reservation Charge defined as static constants
template<> const double BookingClasses::AC3Tier::sReservationCharge =              40.0;
template<> const double BookingClasses::ACFirstClass::sReservationCharge =         60.0;
template<> const double BookingClasses::ACChairCar::sReservationCharge =           40.0;
template<> const double BookingClasses::FirstClass::sReservationCharge =           50.0;
template<> const double BookingClasses::Sleeper::sReservationCharge =              20.0;
template<> const double BookingClasses::SecondSitting::sReservationCharge =        15.0;
template<> const double BookingClasses::ExecutiveChairCar::sReservationCharge =    60.0;
template<> const double BookingClasses::AC2Tier::sReservationCharge =              50.0;



const double Booking::sBaseFarePerKM        = 0.50;
//----------------------------------

void UnitTest(){
    freopen("../outputs/UnitTestOut.txt","w",stdout);
    BookingClasses::UnitTest();
    BookingCategory::UnitTest();
    Booking::UnitTest();
    Divyaang::UnitTest();
    Gender::UnitTest();
    Name::UnitTest();
    Date::UnitTest();
    Station::UnitTest();
    Railways::UnitTest();
    Passenger::UnitTest();
    Concessions::UnitTest();
    fclose(stdout);
    return;
}

int main(){
    UnitTest();
    return 0;
}