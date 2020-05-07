#ifndef EXPBAR_H_INCLUDED
#define EXPBAR_H_INCLUDED

#include "bar.h"
#include "item.h"
#include "enchantment.h"

class ExpBar : public Bar {
protected:
    int level;
public:
    ExpBar() {
        level = 0;
    }
    ExpBar(int l, int a, int b) : Bar(a, b) {
        level = l;
    }
    ExpBar(const ExpBar &eb) : Bar((Bar)eb) {
        level = eb.level;
    }


    int getLevel() {return level;}
    void setLevel(int lvl) {level = lvl;}

    void levelUp() {
        maxAmount *= 1.25;
        amount = 0;
        level++;
    }

    void loseLvl() {
        maxAmount *= 0.8;
        level--;
    }

    void enchantItem (Enchantment enchant, Item target, int cost) {
        for (int i = 0; i < cost; ++i) {
            loseLvl();
        }
        target.addEnchant(enchant);
    }

    // Prefix
    ExpBar operator++ () {
        levelUp();
        return ExpBar(level,amount, maxAmount);
    }
};

#endif // EXPBAR_H_INCLUDED
