// #define _DEBUG

//Rajat Bachhawat
//Roll No: 19CS10073
#include "Concessions.h"

#ifndef SENIORCITIZEN_CONCESSIONS_H
#define SENIORCITIZEN_CONCESSIONS_H

class SeniorCitizenConcession : public Concessions
{
private:
    static const double sMaleConcessionFactor;   //concession factor for male
    static const double sFemaleConcessionFactor; //concession factor for female
    // Constructor for the class SeniorCitizenConcession
    SeniorCitizenConcession();
    SeniorCitizenConcession(SeniorCitizenConcession &scc);
    ~SeniorCitizenConcession(); // Destructor for the class SeniorCitizenConcession

protected:
public:
    // Returns static const singleton object
    static const SeniorCitizenConcession &Type();
    // Returns the concession factor for male
    double GetConcessionFactor(const Passenger &passenger, const Gender::Male &gender) const;
    // Returns the concession factor for female
    double GetConcessionFactor(const Passenger &passenger, const Gender::Female &gender) const;
};

#endif //SENIORCITIZEN_CONCESSIONS_H