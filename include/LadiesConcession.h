
//Rajat Bachhawat
//Roll No: 19CS10073
#include "Concessions.h"

#ifndef LADIES_CONCESSIONS_H
#define LADIES_CONCESSIONS_H

class LadiesConcession : public Concessions {
private:
    // Stores the concession factor
    static const double sConcessionFactor;
    // Constructor 
    LadiesConcession();
    // Destructor 
    ~LadiesConcession();
    LadiesConcession(LadiesConcession& lc);
    
public:
    // Returns static const singleton object of type LadiesConcession
    static const LadiesConcession& Type();
    // Returns the concession factor 
    double GetConcessionFactor(const Passenger &passenger) const;
};

#endif //LADIES_CONCESSIONS_H