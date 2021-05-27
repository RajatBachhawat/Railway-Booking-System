
//Rajat Bachhawat
//Roll No: 19CS10073
#include "Name.h"
#include <sstream>

Name::Name(const string &firstName, const string &lastName, const string &middleName) : firstName_(firstName), middleName_(middleName), lastName_(lastName)
{
#ifdef _DEBUG
    cout << "Class Name = " << (*this) << " ++CONSTRUCTED++" << endl;
#endif
}
ostream &operator<<(ostream &out, const Name &n)
{
    out << n.firstName_;
    if (n.firstName_ != "")
    {
        out << " ";
    }
    out << n.middleName_;
    if (n.middleName_ != "")
    {
        out << " ";
    }
    out << n.lastName_;
    return out;
}

// -------- TESTING FUNCTION AHEAD -------- 

void Name::UnitTest()
{
    cout << "\n\nClass - Name\n\n";
    int totalCount = 1;
    // Test Output streaming operator
    cout << "Test No. 1: Test Output streaming operator : ";
    Name n = Name("Bob", "Dylan");
    string outputGolden = "Bob Dylan";
    stringstream ss;
    ss << n;
    if (ss.str() == outputGolden)
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
        cout << totalCount << "/1 Tests have failed -----\n";
    }
}

Name::~Name()
{
#ifdef _DEBUG
    cout << "Class Name = " << (*this) << " ++DESTRUCTED++" << endl;
#endif
}