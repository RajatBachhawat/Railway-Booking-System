
#include "Test.h"
#include <iostream>
//CHANGEABLE FROM APPLICATION SPACE:
template <>
const double BookingClasses::AC3Tier::sLoadFactor = 2.50;
template <>
const double BookingClasses::ACChairCar::sLoadFactor = 2.00;
template <>
const double BookingClasses::Sleeper::sLoadFactor = 1.00;
template <>
const double BookingClasses::ACFirstClass::sLoadFactor = 6.50;
template <>
const double BookingClasses::ExecutiveChairCar::sLoadFactor = 5.00;
template <>
const double BookingClasses::AC2Tier::sLoadFactor = 4.00;
template <>
const double BookingClasses::FirstClass::sLoadFactor = 3.00;
template <>
const double BookingClasses::SecondSitting::sLoadFactor = 0.60;
template <>
const bool BookingClasses::ACFirstClass::sLuxury = true;
template <>
const bool BookingClasses::ExecutiveChairCar::sLuxury = true;
template <>
const bool BookingClasses::AC2Tier::sLuxury = false;
template <>
const bool BookingClasses::SecondSitting::sLuxury = false;
template <>
const bool BookingClasses::FirstClass::sLuxury = true;
template <>
const bool BookingClasses::Sleeper::sLuxury = false;
template <>
const bool BookingClasses::AC3Tier::sLuxury = false;
template <>
const bool BookingClasses::ACChairCar::sLuxury = false;
template <>
const double BookingClasses::AC3Tier::sReservationCharge = 40.0;
template <>
const double BookingClasses::ACChairCar::sReservationCharge = 40.0;
template <>
const double BookingClasses::ACFirstClass::sReservationCharge = 60.0;
template <>
const double BookingClasses::Sleeper::sReservationCharge = 20.0;
template <>
const double BookingClasses::SecondSitting::sReservationCharge = 15.0;
template <>
const double BookingClasses::ExecutiveChairCar::sReservationCharge = 60.0;
template <>
const double BookingClasses::AC2Tier::sReservationCharge = 50.0;
template <>
const double BookingClasses::FirstClass::sReservationCharge = 50.0;

const double Booking::sBaseFarePerKM = 0.50;

void BookingApplication()
{
    //Checking Constructors, Copy Constructors and Singleton Nature
    //1. Gender Types 
    cout << "=====GENDER=====\n";
    const Gender &male = Gender::Male::Type();
    cout << "\n";
    const Gender &male2 = Gender::Male::Type(); //Singleton Nature of Gender Types
    const Gender &female = Gender::Female::Type();
    cout << "\n";
    //2. Divyaaang Types 
    cout << "=====DIVYAANG=====\n";
    const Divyaang &blind = Divyaang::Blind::Type();
    cout << "\n";
    const Divyaang &blind2 = Divyaang::Blind::Type(); //Singleton Nature of Divyaang Types
    const Divyaang &cancer = Divyaang::CancerPatient::Type();
    cout << "\n";
    const Divyaang &oh = Divyaang::OrthopaedicallyHandicapped::Type();
    cout << "\n";
    const Divyaang &tb = Divyaang::TBPatient::Type();
    cout << "\n";
    //3. Passenger - Not Singleton
    cout << "=====PASSENGERS=====\n";
    Passenger p1 = Passenger::GetPassenger(Name("Phoebe", "Therapy", "Buffau"), Date::GetDate(10, 2, 1905), Gender::Female::Type(), "121456719123", "0123456719", &Divyaang::Blind::Type(), "abc");
    cout << "\n";
    Passenger p1Copy = Passenger(p1); //Copy Constructor
    cout << "\n";
    Passenger p2 = Passenger::GetPassenger(Name("Phoebe", "Therapy", "Buffau"), Date::GetDate(10, 2, 1905), Gender::Male::Type(), "123416189123", "0123456719", &Divyaang::CancerPatient::Type(), "f");
    cout << "\n";
    //4. Date - Not Singleton
    cout << "=====DATES=====\n";
    Date reser2 = Date::GetDate("03/06/2021");
    cout << "\n";
    Date reser = Date::Today();
    cout << "\n";
    Date book = Date::Today(); // Date Today
    cout << "\n";
    //5.Station 
    cout << "=====STATION=====\n";
    Station to = Station::GetStation("Kolkata");
    cout << "\n";
    Station toCopy = Station(to); //Copy Constructor
    cout << "\n";
    Station from = Station::GetStation("Delhi");
    cout << "\n";
    //6. Railways 
    cout << "=====RAILWAYS=====\n";
    const Railways &rlwy = Railways::Type();
    cout << "\n";
    const Railways &rlwy_again = Railways::Type(); //Singleton Nature
    //6. Name - Not Singleton
    cout << "=====NAME=====\n";
    Name name1 = Name("Phoebe", "Buffau", "");
    cout << "\n";
    //8. Divyaang Concession 
    cout << "=====DIVYAANG CONCESSION=====\n";
    const DivyaangConcession &dc = DivyaangConcession::Type();
    cout << "\n";
    const DivyaangConcession &dc2 = DivyaangConcession::Type(); //Checking Singleton Nature
    //9. Ladies Concession
    cout << "=====LADIES CONCESSION=====\n";
    const LadiesConcession &dcl = LadiesConcession::Type();
    cout << "\n";
    const LadiesConcession &dc2l = LadiesConcession::Type(); //Checking Singleton Nature
    //10. SeniorCitizen Concession 
    cout << "=====SENIOR CITIZEN CONCESSION=====\n";
    const SeniorCitizenConcession &dcsc = SeniorCitizenConcession::Type();
    cout << "\n";
    const SeniorCitizenConcession &dc2sc = SeniorCitizenConcession::Type(); //Checking Singleton Nature
    //11. General Concession 
    cout << "=====GENERAL CONCESSION=====\n";
    const GeneralConcession &dcgc = GeneralConcession::Type();
    cout << "\n";
    const GeneralConcession &dc2gc = GeneralConcession::Type(); //Checking Singleton Nature
    //12. Date - Not Singleton
    cout << "=====DATE=====\n";
    Date date1 = Date::GetDate(1, 1, 2001);
    cout << "\n";
    Date date2 = Date::GetDate("01/01/2001");
    cout << "\n";
    Date todays = Date::Today(); //Checking if today's date is correct
    cout << "\n";
    //13. Concessions 
    cout << "=====CONCESSIONS=====\n";
    const Concessions &c = Concessions::Type();
    cout << "\n";
    const Concessions &cagain = Concessions::Type(); //Singleton Check
    //14. Booking Classes Types 
    cout << "=====BOOKING CLASSES===== \n";
    const BookingClasses &b1x = BookingClasses::AC2Tier::Type();
    cout << "\n";
    const BookingClasses &b1xagain = BookingClasses::AC2Tier::Type(); //Singleton Nature
    const BookingClasses &b2x = BookingClasses::AC3Tier::Type();
    cout << "\n";
    const BookingClasses &b5x = BookingClasses::ACChairCar::Type();
    cout << "\n";
    const BookingClasses &b4x = BookingClasses::ACFirstClass::Type();
    cout << "\n";
    const BookingClasses &b6x = BookingClasses::Sleeper::Type();
    cout << "\n";
    const BookingClasses &b8x = BookingClasses::ExecutiveChairCar::Type();
    cout << "\n";
    const BookingClasses &b9x = BookingClasses::FirstClass::Type();
    cout << "\n";
    const BookingClasses &b7x = BookingClasses::SecondSitting::Type();
    cout << "\n";
    //15. Booking Category Types 
    cout << "=====BOOKING CATEGORY=====\n";
    const BookingCategory &bc1 = BookingCategory::SeniorCitizen::Type();
    cout << "\n";
    const BookingCategory &bc1copy = BookingCategory::SeniorCitizen::Type(); //Singleton Check
    const BookingCategory &bc2 = BookingCategory::Ladies::Type();
    cout << "\n";
    const BookingCategory &bc3 = BookingCategory::General::Type();
    cout << "\n";
    const BookingCategory &bc4 = BookingCategory::DivyaangCat::Type();
    cout << "\n";
    const BookingCategory &bc5 = BookingCategory::Tatkal::Type();
    cout << "\n";
    const BookingCategory &bc6 = BookingCategory::PremiumTatkal::Type();
    cout << "\n";
    //16. Booking - Has to be called through Reserve, otherwise can throw errors. Not singleton
    cout << "=====BOOKING=====\n";
    //Check if all bookings execute correctly - Checking with Goldens has been already done in testing of ComputeFare()
    const Booking *b1 = Booking::Reserve(to, from, book, reser, BookingClasses::AC2Tier::Type(), BookingCategory::Ladies::Type(), p1); //Ladies Booking
    cout << "\n";
    //Symmetric ordering
    const Booking *b1_ = Booking::Reserve(from, to, book, reser, BookingClasses::AC2Tier::Type(), BookingCategory::Ladies::Type(), p1); //Ladies Booking Symmetric
    cout << "\n";
    const Booking *b2 = Booking::Reserve(Station::GetStation("Mumbai"), Station::GetStation("Delhi"), book, reser, BookingClasses::AC3Tier::Type(), BookingCategory::General::Type(), p1); //General Booking
    cout << "\n";
    const Booking *b3 = Booking::Reserve(Station::GetStation("Mumbai"), Station::GetStation("Delhi"), book, reser, BookingClasses::ACFirstClass::Type(), BookingCategory::General::Type(), p1); //General Booking
    cout << "\n";
    const Booking *b4 = Booking::Reserve(Station::GetStation("Mumbai"), Station::GetStation("Delhi"), book, reser, BookingClasses::AC3Tier::Type(), BookingCategory::SeniorCitizen::Type(), p2); //Senior Citizen Booking
    cout << "\n";
    const Booking *b5 = Booking::Reserve(Station::GetStation("Mumbai"), Station::GetStation("Delhi"), book, reser, BookingClasses::ACFirstClass::Type(), BookingCategory::SeniorCitizen::Type(), p1); //Senior Citizen Booking
    cout << "\n";
    const Booking *b6 = Booking::Reserve(Station::GetStation("Mumbai"), Station::GetStation("Delhi"), book, reser, BookingClasses::AC3Tier::Type(), BookingCategory::DivyaangCat::Type(), p1); //Divyaang Booking
    cout << "\n";
    const Booking *b7 = Booking::Reserve(Station::GetStation("Mumbai"), Station::GetStation("Delhi"), book, reser, BookingClasses::ACFirstClass::Type(), BookingCategory::DivyaangCat::Type(), p2); //Divyaang Booking
    cout << "\n";
    const Booking *b8 = Booking::Reserve(Station::GetStation("Delhi"), Station::GetStation("Mumbai"), book, reser, BookingClasses::AC3Tier::Type(), BookingCategory::Tatkal::Type(), p1); //Tatkal Booking
    cout << "\n";
    const Booking *b9 = Booking::Reserve(Station::GetStation("Chennai"), Station::GetStation("Bangalore"), book, reser, BookingClasses::ACFirstClass::Type(), BookingCategory::Tatkal::Type(), p1); //Tatkal Booking
    cout << "\n";
    const Booking *b10 = Booking::Reserve(Station::GetStation("Chennai"), Station::GetStation("Bangalore"), book, reser, BookingClasses::ACFirstClass::Type(), BookingCategory::PremiumTatkal::Type(), p1); //Premium Tatkal Booking
    cout << "\n";
    const Booking *b11 = Booking::Reserve(Station::GetStation("Delhi"), Station::GetStation("Mumbai"), book, reser, BookingClasses::AC3Tier::Type(), BookingCategory::PremiumTatkal::Type(), p1); //Premium Tatkal Booking
    //Checking if Booking List is printed Correctly
    cout << "\n";
    cout << "=====LIST OF BOOKINGS=====\n";
    vector<Booking *>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it)
    {
        cout << (*(*it));
    }
    cout << "=====DESTRUCTORS=====\n";
    //Destructors
}

int main()
{

    freopen("../outputs/ApplicationOut.txt", "w", stdout);
    BookingApplication();
    //fclose(stdout);
    return 0;
}