#ifndef HUNGERBAR_H_INCLUDED
#define HUNGERBAR_H_INCLUDED

#include "bar.h"

class HungerBar : public Bar {
private:
    bool hasHunger;
public:
    HungerBar() {
    hasHunger = false;
    amount = 20;
    maxAmount = 20;
    }
    HungerBar(bool hunger, int a, int b) : Bar(a, b) {
    hasHunger = hunger;
    }
    HungerBar(const HungerBar &hb) : Bar((Bar)hb) {
    hasHunger = hb.hasHunger;
    }

    bool getHunger() const {return hasHunger;}
    void setHunger(bool h) {hasHunger = h;}

    // Prefix
    HungerBar operator++ () {
        gainAmnt(1);
        return HungerBar(hasHunger, amount, maxAmount);
    }
};

#endif // HUNGERBAR_H_INCLUDED
