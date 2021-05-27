
//Rajat Bachhawat
//Roll No: 19CS10073
#include "Concessions.h"
#include "GeneralConcession.h"
#include "Gender.h"
#include "LadiesConcession.h"
#include "SeniorCitizenConcession.h"
#include "DivyaangConcession.h"
#include "Divyaang.h"
#include "BookingClasses.h"

// General Concession 
const double GeneralConcession::sConcessionFactor = 0.00;
// Ladies Concession 
const double LadiesConcession::sConcessionFactor = 0.00;
// Divyaang Concessions 
// Blind Concessions 
template <>
const double Divyaang::Blind::sACFirstClassConcession = 0.50;
template <>
const double Divyaang::Blind::sExecutiveChairCarConcession = 0.75;
template <>
const double Divyaang::Blind::sAC2TierConcession = 0.50;
template <>
const double Divyaang::Blind::sFirstClassConcession = 0.75;
template <>
const double Divyaang::Blind::sAC3TierConcession = 0.75;
template <>
const double Divyaang::Blind::sACChairCarConcession = 0.75;
template <>
const double Divyaang::Blind::sSleeperConcession = 0.75;
template <>
const double Divyaang::Blind::sSecondSittingConcession = 0.75;
// Orthopaedically Handicapped Concessions 
template <>
const double Divyaang::OrthopaedicallyHandicapped::sACFirstClassConcession = 0.50;
template <>
const double Divyaang::OrthopaedicallyHandicapped::sExecutiveChairCarConcession = 0.75;
template <>
const double Divyaang::OrthopaedicallyHandicapped::sAC2TierConcession = 0.50;
template <>
const double Divyaang::OrthopaedicallyHandicapped::sFirstClassConcession = 0.75;
template <>
const double Divyaang::OrthopaedicallyHandicapped::sAC3TierConcession = 0.75;
template <>
const double Divyaang::OrthopaedicallyHandicapped::sACChairCarConcession = 0.75;
template <>
const double Divyaang::OrthopaedicallyHandicapped::sSleeperConcession = 0.75;
template <>
const double Divyaang::OrthopaedicallyHandicapped::sSecondSittingConcession = 0.75;
// Cancer Patient Concessions 
template <>
const double Divyaang::CancerPatient::sACFirstClassConcession = 0.50;
template <>
const double Divyaang::CancerPatient::sExecutiveChairCarConcession = 0.75;
template <>
const double Divyaang::CancerPatient::sAC2TierConcession = 0.50;
template <>
const double Divyaang::CancerPatient::sFirstClassConcession = 0.75;
template <>
const double Divyaang::CancerPatient::sAC3TierConcession = 1.00;
template <>
const double Divyaang::CancerPatient::sACChairCarConcession = 1.00;
template <>
const double Divyaang::CancerPatient::sSleeperConcession = 1.00;
template <>
const double Divyaang::CancerPatient::sSecondSittingConcession = 1.00;
// TB Patient Concessions
template <>
const double Divyaang::TBPatient::sACFirstClassConcession = 0.00;
template <>
const double Divyaang::TBPatient::sExecutiveChairCarConcession = 0.00;
template <>
const double Divyaang::TBPatient::sAC2TierConcession = 0.00;
template <>
const double Divyaang::TBPatient::sFirstClassConcession = 0.75;
template <>
const double Divyaang::TBPatient::sAC3TierConcession = 0.00;
template <>
const double Divyaang::TBPatient::sACChairCarConcession = 0.00;
template <>
const double Divyaang::TBPatient::sSleeperConcession = 0.75;
template <>
const double Divyaang::TBPatient::sSecondSittingConcession = 0.75;
// Senior Citizen Concessions 
// Senior Citizen Concession for Male and Female

const double SeniorCitizenConcession::sMaleConcessionFactor = 0.40;
const double SeniorCitizenConcession::sFemaleConcessionFactor = 0.50;

Concessions::Concessions()
{
#ifdef _DEBUG
    cout << "Class Concessions"
         << " ++CONSTRUCTED++" << endl;
#endif
}

Concessions::~Concessions()
{
#ifdef _DEBUG
    cout << "Class Concessions"
         << " ++DESTRUCTED++" << endl;
#endif
}

const Concessions &Concessions::Type()
{
    static const Concessions obj;
    return obj;
}

// Gets concession factor for super class Concessions

LadiesConcession::LadiesConcession()
{
#ifdef _DEBUG
    cout << "Class LadiesConcession"
         << " ++CONSTRUCTED++" << endl;
#endif
}

LadiesConcession::~LadiesConcession()
{
#ifdef _DEBUG
    cout << "LadiesConcession"
         << " ++DESTRUCTED++" << endl;
#endif
}

const LadiesConcession &LadiesConcession::Type()
{
    static const LadiesConcession obj;
    return obj;
}

// Gets concession factor for Ladies
double LadiesConcession::GetConcessionFactor(const Passenger &passenger) const
{
    return LadiesConcession::sConcessionFactor;
}

GeneralConcession::GeneralConcession()
{
#ifdef _DEBUG
    cout << "Class GeneralConcession"
         << " ++CONSTRUCTED++" << endl;
#endif
}
double Concessions::GetConcessionFactor() const
{
    return 0.0;
}

GeneralConcession::~GeneralConcession()
{
#ifdef _DEBUG
    cout << "Class GeneralConcession"
         << " ++DESTRUCTED++" << endl;
#endif
}

const GeneralConcession &GeneralConcession::Type()
{
    static const GeneralConcession obj;
    return obj;
}


// --- Implementations from DivyaangConcession.h ---

DivyaangConcession::DivyaangConcession()
{
#ifdef _DEBUG
    cout << "Class DivyaangConcession"
         << " ++CONSTRUCTED++" << endl;
#endif
}

DivyaangConcession::~DivyaangConcession()
{
#ifdef _DEBUG
    cout << "Class DivyaangConcession"
         << " ++DESTRUCTED++" << endl;
#endif
}

const DivyaangConcession &DivyaangConcession::Type()
{
    static const DivyaangConcession obj;
    return obj;
}

double DivyaangConcession::GetConcessionFactor(const Passenger &passenger, const BookingClasses &bookingClass) const
{
    return bookingClass.GetConcessionForDivyaang(passenger.disabilityType_);
}
SeniorCitizenConcession::SeniorCitizenConcession()
{
#ifdef _DEBUG
    cout << "Class SeniorCitizenConcession"
         << " ++CONSTRUCTED++" << endl;
#endif
}

SeniorCitizenConcession::~SeniorCitizenConcession()
{
#ifdef _DEBUG
    cout << "Class SeniorCitizenConcession"
         << " ++DESTRUCTED++" << endl;
#endif
}

const SeniorCitizenConcession &SeniorCitizenConcession::Type()
{
    static const SeniorCitizenConcession obj;
    return obj;
}

// Gets concession factor for Female Senior Citizen
double SeniorCitizenConcession::GetConcessionFactor(const Passenger &passenger, const Gender::Female &gender) const
{
    return SeniorCitizenConcession::sFemaleConcessionFactor;
}

// Gets concession factor for Male Senior Citizen
double SeniorCitizenConcession::GetConcessionFactor(const Passenger &passenger, const Gender::Male &gender) const
{
    return SeniorCitizenConcession::sMaleConcessionFactor;
}

// -------- TESTING FUNCTION AHEAD -------- 

void Concessions::UnitTest()
{
    //Since it is templatised, we do not need to check for every pair, we make sure all BookingClasses and Disability Types are covered
    cout << "\n\nClass - Concessions : Sub Types - LadiesConcession, GeneralConcession, SeniorCitizenConcession, DivyaangConcession\n\n";
    int goldenConcession;
    //General Concession
    goldenConcession = 0.0;
    int totalCount = 12;
    Passenger p2 = Passenger::GetPassenger(Name("Priyanka", "Chopra"), Date::GetDate(5, 1, 1950), Gender::Female::Type(), "123456789123", "0123456789");
    int concession = GeneralConcession::Type().GetConcessionFactor();
    cout << "Test No. 1 : Concessions:GeneralConcession:GetConcessionFactor: ";
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }

    //Ladies Concession
    cout << "Test No. 2 : Concessions:LadiedConcession:GetConcessionFactor: ";
    goldenConcession = 0.0;
    concession = LadiesConcession::Type().GetConcessionFactor(p2);
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }

    //Senior Citizen Female Concession
    goldenConcession = 0.5;
    cout << "Test No. 3 : Concessions:SeniorCitizenConcession:GetConcessionFactor for Female: ";
    concession = SeniorCitizenConcession::Type().GetConcessionFactor(p2, Gender::Female::Type());
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }

    //Senior Citizen Male Concession
    goldenConcession = 0.4;
    concession = SeniorCitizenConcession::Type().GetConcessionFactor(p2, Gender::Male::Type());
    cout << "Test No. 4 : Concessions:SeniorCitizenConcession:GetConcessionFactor for Male: ";
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }

    //Divyang Concession - ACFirstClass - Blind
    cout << "Test No. 5 : Concessions:DivyaangConcession:GetConcessionFactor - ACFirstClass - Blind : ";
    goldenConcession = 0.5;
    Passenger blind = Passenger::GetPassenger(Name("Priyanka", "Chopra"), Date::GetDate(5, 1, 1950), Gender::Female::Type(), "123456789123", "0123456789", &Divyaang::Blind::Type(), "12345");
    concession = DivyaangConcession::Type().GetConcessionFactor(blind, BookingClasses::ACFirstClass::Type());
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    //Executive Chair Car - Blind
    cout << "Test No. 6 : Concessions:DivyaangConcession:GetConcessionFactor - Executive Chair Car - Blind : ";
    goldenConcession = 0.75;
    concession = DivyaangConcession::Type().GetConcessionFactor(blind, BookingClasses::ExecutiveChairCar::Type());
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    //AC 2 Tier - Blind
    goldenConcession = 0.50;
    concession = DivyaangConcession::Type().GetConcessionFactor(blind, BookingClasses::AC2Tier::Type());
    cout << "Test No. 7 : Concessions:DivyaangConcession:GetConcessionFactor - AC 2 Tier - Blind : ";
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    //First Class - Blind
    goldenConcession = 0.75;
    concession = DivyaangConcession::Type().GetConcessionFactor(blind, BookingClasses::FirstClass::Type());
    cout << "Test No. 8 : Concessions:DivyaangConcession:GetConcessionFactor -First Class - Blind : ";
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    //AC3Tier - Blind
    goldenConcession = 0.75;
    concession = DivyaangConcession::Type().GetConcessionFactor(blind, BookingClasses::AC3Tier::Type());
    cout << "Test No. 9 : Concessions:DivyaangConcession:GetConcessionFactor -  AC3Tier - Blind : ";
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    //AC Chair Car Orthopaedically Handicapped
    Passenger oh = Passenger::GetPassenger(Name("Priyanka", "Chopra"), Date::GetDate(5, 1, 1950), Gender::Female::Type(), "123456789123", "0123456789", &Divyaang::OrthopaedicallyHandicapped::Type(), "12345");
    goldenConcession = 0.75;
    cout << "Test No. 10 : Concessions:DivyaangConcession:GetConcessionFactor -  AC Chair - OC : ";
    concession = DivyaangConcession::Type().GetConcessionFactor(oh, BookingClasses::ACChairCar::Type());
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    //Sleeper Cancer Patient
    cout << "Test No. 11 : Concessions:DivyaangConcession:GetConcessionFactor -  Sleeper - Cancer Patient : ";
    Passenger cp = Passenger::GetPassenger(Name("Priyanka", "Chopra"), Date::GetDate(5, 1, 1950), Gender::Female::Type(), "123456789123", "0123456789", &Divyaang::CancerPatient::Type(), "12345");
    goldenConcession = 1.00;
    concession = DivyaangConcession::Type().GetConcessionFactor(cp, BookingClasses::Sleeper::Type());
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    //Second Sitting TB Patient
    Passenger tb = Passenger::GetPassenger(Name("Priyanka", "Chopra"), Date::GetDate(5, 1, 1950), Gender::Female::Type(), "123456789123", "0123456789", &Divyaang::TBPatient::Type(), "12345");
    goldenConcession = 0.75;
    cout << "Test No. 12 : Concessions:DivyaangConcession:GetConcessionFactor -  Second Sitting - TB Patient : ";
    concession = DivyaangConcession::Type().GetConcessionFactor(tb, BookingClasses::SecondSitting::Type());
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    cout << "\n----- VERDICT : ";
    if (totalCount == 0)
    {
        cout << "PASS -----\n";
    }
    else
    {
        cout << totalCount << "/12 Tests have failed -----\n";
    }
}
