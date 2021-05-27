// #define _DEBUG

//Rajat Bachhawat
//Roll No: 19CS10073
#include "Concessions.h"

#ifndef DIVYAANG_CONCESSIONS_H
#define DIVYAANG_CONCESSIONS_H

class DivyaangConcession : public Concessions {
private:
    // Constructor
    DivyaangConcession();
    // Destructor 
    ~DivyaangConcession();
protected:

public:
    // Returns static const singleton object of type DivyaangConcession
    static const DivyaangConcession& Type();
    // Returns the concession factor 
    double GetConcessionFactor(const Passenger &passenger, const BookingClasses &bookingClass) const;
};

#endif //DIVYAANG_CONCESSIONS_H