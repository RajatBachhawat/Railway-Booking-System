
//Rajat Bachhawat
//Roll No: 19CS10073
#include "Passenger.h"

#ifndef CONCESSIONS_H
#define CONCESSIONS_H

class Concessions
{
private:
    // Copy Constructor
    Concessions(const Concessions &c); // blocked
protected:
    // Constructor
    Concessions();

public:
    // Destructor
    ~Concessions();
    // Returns static const singleton object of  Concessions
    static const Concessions &Type();
    static void UnitTest();
    double GetConcessionFactor() const;
    // Unit Testing method
};

#endif //CONCESSIONS_H