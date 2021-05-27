
//Rajat Bachhawat
//Roll No: 19CS10073
#include "Concessions.h"

#ifndef GENERAL_CONCESSIONS_H
#define GENERAL_CONCESSIONS_H

class GeneralConcession : public Concessions {
private:
    // concession factor
    static const double sConcessionFactor;
    // Constructor 
    GeneralConcession();
    // Destructor
    ~GeneralConcession();
    GeneralConcession(GeneralConcession& gc);
public:
    // Returns static const singleton object of type GeneralConcession
    static const GeneralConcession& Type();
};

#endif //GENERAL_CONCESSIONS_H