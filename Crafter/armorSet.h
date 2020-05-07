#ifndef ARMORSET_H_INCLUDED
#define ARMORSET_H_INCLUDED

#include "item.h"

class ArmorSet {
private:
    Item helmet;
    Item chestplate;
    Item leggings;
    Item boots;
public:
    ArmorSet() : helmet(), chestplate(), leggings(), boots() {};
    ArmorSet(Item helm, Item chest, Item legs, Item boot) {
        helmet = helm;
        chestplate = chest;
        leggings = legs;
        boots = boot;
    }
    ArmorSet(const ArmorSet &as) {
        helmet = as.helmet;
        chestplate = as.chestplate;
        leggings = as.leggings;
        boots = as.boots;
    }

    Item getHelmet () const {return helmet;}
    Item getChestplate () const {return chestplate;}
    Item getLeggings () const {return leggings;}
    Item getBoots () const {return boots;}

    void setHelmet (Item h) {helmet = h;}
    void setChestplate (Item c) {chestplate = c;}
    void setLeggings (Item l) {leggings = l;}
    void setBoots (Item b) {boots = b;}

    void takeHit() {
        helmet.useItem();
        chestplate.useItem();
        leggings.useItem();
        boots.useItem();
    }
};

#endif // ARMORSET_H_INCLUDED
