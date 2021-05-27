
//Rajat Bachhawat
//Roll No: 19CS10073
// #define _DEBUG
#ifndef __GENDER_H
#define __GENDER_H
#include <string>
#include <iostream>
using namespace std;

// Forward declaration of templatized class
// Generic Gender type to generate specific genders
template <typename T>
class GenderTypes;

// Abstract Base Class
// Generic gender type
class Gender
{
private:
    // Tag types - to instantiate the template
    // Note that these names are placeholders only and are not exposed outside the class
    // Also they are put inside the class for not cluttering the global namespace
    struct MaleType
    {
    };
    struct FemaleType
    {
    };
    Gender(const Gender &g);

protected:
    Gender()
    {
#ifdef _DEBUG
        cout << "Class Gender ++CONSTRUCTED++" << endl;
#endif
    }
    virtual ~Gender()
    {
#ifdef _DEBUG
        cout << "Class Gender ++DESTRUCTED++" << endl;
#endif
    }

public:
    static void UnitTest();
    virtual const string GetName() const = 0;
    virtual const string GetTitle() const = 0; // Salutation specific to gender
    friend ostream &operator<<(ostream &out, const Gender &g);

    // Enumerated types - the target sub-types

    typedef GenderTypes<MaleType> Male;
    typedef GenderTypes<FemaleType> Female;
};

// Specific gender types

template <typename T>
class GenderTypes : public Gender
{
private:
    static const string sName;       // Respective name of the gender
    static const string sSalutation; // Respective salutation for the gender
    GenderTypes(const GenderTypes &g);
    GenderTypes()
    {
#ifdef _DEBUG
        cout << "Gender (SubType) = " << (*this) << " ++CONSTRUCTED++" << endl;
#endif
    }
    ~GenderTypes()
    {
#ifdef _DEBUG
        cout << "Gender (SubType) = " << (*this) << " ++DESTRUCTED++" << endl;
#endif
    }

public:
    // Singleton object - placeholder for the respective type
    static const GenderTypes<T> &Type()
    {
        static const GenderTypes<T> theObject; // May be non-const for changeable behavior
        return theObject;
    }

    const string GetTitle() const // Dynamic dispatch
    {
        return GenderTypes<T>::sSalutation;
    } 
    const string GetName() const // Dynamic dispatch
    {
        return GenderTypes<T>::sName;
    } 

   

    friend ostream &operator<<(ostream &out, const GenderTypes<T> &g)
    {
        out << g.GetName();
        return out;
    }
};

#endif // __GENDER_H