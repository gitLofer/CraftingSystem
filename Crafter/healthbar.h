#ifndef HEALTHBAR_H_INCLUDED
#define HEALTHBAR_H_INCLUDED

#include "bar.h"

class Healthbar : public Bar {
protected:
    bool isPoisoned;
    bool isWithered;
public:
    Healthbar() {
        isPoisoned = false;
        isWithered = false;
    }
    Healthbar(bool poison, bool wither, int start, int maximum) : Bar(maximum , start) {
        isPoisoned = poison;
        isWithered = wither;
    }
    Healthbar(const Healthbar &hb) : Bar((Bar)hb) {
        isPoisoned = hb.isPoisoned;
        isWithered = hb.isWithered;
    }

    bool getIsPoisoned () {return isPoisoned;}
    bool getIsWithered () {return isWithered;}

    void setIsPoisoned (bool a) {isPoisoned = a;}
    void setIsWithered (bool a) {isWithered = a;}

    // Prefix
    Healthbar operator++ () {
        gainAmnt(1);
        return Healthbar(isPoisoned, isWithered ,amount, maxAmount);
    }
};

#endif // HEALTHBAR_H_INCLUDED
