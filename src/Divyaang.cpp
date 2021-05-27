
//Rajat Bachhawat
//Roll No: 19CS10073
#include "Divyaang.h"

template <>
const string Divyaang::Blind::sName = "Blind";
template <>
const string Divyaang::CancerPatient::sName = "Cancer Patient";
template <>
const string Divyaang::TBPatient::sName = "TB Patient";
template <>
const string Divyaang::OrthopaedicallyHandicapped::sName = "Orthopaedically Handicapped";

Divyaang::Divyaang()
{
#ifdef _DEBUG
    cout << "Class Divyaang ++CONSTRUCTED++" << endl;
#endif
}

ostream &operator<<(ostream &out, const Divyaang &d)
{
    out << d.GetName();
    return out;
}
Divyaang::~Divyaang()
{
#ifdef _DEBUG
    cout << "Class Divyaang  ++DESTRUCTED++" << endl;
#endif
}

template <typename T>
DisabilityTypes<T>::DisabilityTypes()
{
#ifdef _DEBUG
    cout << "Divyaang (SubType) = " << (*this) << " ++CONSTRUCTED++" << endl;
#endif
}
template <typename T>
string DisabilityTypes<T>::GetName() const
{
    return DisabilityTypes<T>::sName;
}

template <typename T>
double DisabilityTypes<T>::GetDivyaangConcessionFactor(const BookingClasses::ACFirstClass &) const
{
    return DisabilityTypes<T>::sACFirstClassConcession;
}
template <typename T>
DisabilityTypes<T>::~DisabilityTypes()
{
#ifdef _DEBUG
    cout << "Divyaang (SubType) = " << (*this) << " ++DESTRUCTED++" << endl;
#endif
}

template <typename T>
double DisabilityTypes<T>::GetDivyaangConcessionFactor(const BookingClasses::ExecutiveChairCar &) const
{
    return DisabilityTypes<T>::sExecutiveChairCarConcession;
}

template <typename T>
double DisabilityTypes<T>::GetDivyaangConcessionFactor(const BookingClasses::AC2Tier &) const
{
    return DisabilityTypes<T>::sAC2TierConcession;
}

template <typename T>
double DisabilityTypes<T>::GetDivyaangConcessionFactor(const BookingClasses::FirstClass &) const
{
    return DisabilityTypes<T>::sFirstClassConcession;
}
template <typename T>
double DisabilityTypes<T>::GetDivyaangConcessionFactor(const BookingClasses::Sleeper &) const
{
    return DisabilityTypes<T>::sSleeperConcession;
}
template <typename T>
double DisabilityTypes<T>::GetDivyaangConcessionFactor(const BookingClasses::ACChairCar &) const
{
    return DisabilityTypes<T>::sACChairCarConcession;
}
template <typename T>
const DisabilityTypes<T> &DisabilityTypes<T>::Type()
{
    static const DisabilityTypes<T> obj;
    return obj;
}
template <typename T>
double DisabilityTypes<T>::GetDivyaangConcessionFactor(const BookingClasses::AC3Tier &) const
{
    return DisabilityTypes<T>::sAC3TierConcession;
}
template <typename T>
double DisabilityTypes<T>::GetDivyaangConcessionFactor(const BookingClasses::SecondSitting &) const
{
    return DisabilityTypes<T>::sSecondSittingConcession;
}

// -------- TESTING FUNCTION AHEAD -------- 

void Divyaang::UnitTest()
{
    cout << "\n\nClass - Divyaang\n\n";
    double goldenConcession;
    double concession = 0.0;
    int totalCount = 15;
    //Test GetDivyaangConcessionFactor() for all sub-types of Divyaang
    //Divyang Concession - ACFirstClass - Blind
    goldenConcession = 0.5;
    concession = Divyaang::Blind::Type().GetDivyaangConcessionFactor(BookingClasses::ACFirstClass::Type());
    cout << "Test No. 1 : Divyaang:GetDivyaangConcessionFactor - ACFirstClass - Blind : ";
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
    cout << "Test No. 2 : Divyaang:GetDivyaangConcessionFactor - Executive Chair Car - Blind : ";

    goldenConcession = 0.75;
    concession = Divyaang::Blind::Type().GetDivyaangConcessionFactor(BookingClasses::ExecutiveChairCar::Type());
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
    cout << "Test No. 3 : Divyaang::GetDivyaangConcessionFactor - AC 2 Tier - Blind :  ";
    goldenConcession = 0.50;
    concession = Divyaang::Blind::Type().GetDivyaangConcessionFactor(BookingClasses::AC2Tier::Type());
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
    cout << "Test No. 4 : Divyaang:GetDivyaangConcessionFactor - First Class - Blind :  ";
    goldenConcession = 0.75;
    concession = Divyaang::Blind::Type().GetDivyaangConcessionFactor(BookingClasses::FirstClass::Type());
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
    cout << "Test No. 5 : Divyaang:GetDivyaangConcessionFactor - AC3Tier - Blind :  ";
    goldenConcession = 0.75;
    concession = Divyaang::Blind::Type().GetDivyaangConcessionFactor(BookingClasses::AC3Tier::Type());
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
    cout << "Test No. 6 : Divyaang:GetDivyaangConcessionFactor - AC Chair Car Orthopaedically Handicapped :  ";
    goldenConcession = 0.75;
    concession = Divyaang::OrthopaedicallyHandicapped::Type().GetDivyaangConcessionFactor(BookingClasses::ACChairCar::Type());
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
    cout << "Test No. 7 : Divyaang:GetDivyaangConcessionFactor - Sleeper Cancer Patient :  ";

    goldenConcession = 1.00;
    concession = Divyaang::CancerPatient::Type().GetDivyaangConcessionFactor(BookingClasses::Sleeper::Type());
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
    cout << "Test No. 8 : Divyaang:GetDivyaangConcessionFactor - Second Sitting TB Patient :  ";

    goldenConcession = 0.75;
    concession = Divyaang::TBPatient::Type().GetDivyaangConcessionFactor(BookingClasses::SecondSitting::Type());
    if (concession == goldenConcession)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    //Test GetName for all sub-types of Divyaang
    cout << "Test No. 9 : Divyaang:Blind::GetName()   ";

    if (Divyaang::Blind::Type().GetName() == "Blind")
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    cout << "Test No. 10: Divyaang:OrthopaedicallyHandicapped::GetName()   ";
    if (Divyaang::OrthopaedicallyHandicapped::Type().GetName() == "Orthopaedically Handicapped")
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    cout << "Test No. 11: Divyaang:CancerPatient::GetName()   ";

    if (Divyaang::CancerPatient::Type().GetName() == "Cancer Patient")
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    cout << "Test No. 12: Divyaang:CancerPatient::GetName()   ";

    if (Divyaang::TBPatient::Type().GetName() == "TB Patient")
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }

    // Test Output streaming operator for DivyaangTypes<T>
    cout << "Test No. 13: outputstream  :  ";

    const Divyaang::TBPatient &tTest = Divyaang::TBPatient::Type();
    string outputGolden = "TB Patient";
    stringstream ss;
    ss << tTest;
    if (ss.str() == outputGolden)
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }

    // Test on Divyaang
    // Test working of polymorphic hierarchy by comparing the GetName() function return value
    cout << "Test No. 14: Test working of polymorphic hierarchy by comparing the GetName() function return value : ";

    const Divyaang &obj = Divyaang::Blind::Type();
    if (obj.GetName() == "Blind")
    {
        totalCount--;
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }

    // Test Output streaming operator for Divyaang
    cout << "Test No. 15: Test Output streaming operator for Divyaang : ";

    const Divyaang &dTest = Divyaang::Blind::Type();
    outputGolden = "Blind";
    stringstream ss_;
    ss_ << dTest;
    if (ss_.str() == outputGolden)
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
        cout << totalCount << "/15 Tests have failed -----\n";
    }
}
// int main(){
//     const Divyaang &d = Divyaang::TBPatient::Type();
//     cout<<d.GetDivyaangConcessionFactor(BookingClasses::ACFirstClass::Type());
//     return 0;
// }