#ifndef PASSIVEMOB_H_INCLUDED
#define PASSIVEMOB_H_INCLUDED

#include "mob.h"
#include "item.h"

enum mobType {COW, PIG, CHICKEN};

class PassiveMob : Mob {
private:
    mobType type;
    Item favouriteFood;
public:
    PassiveMob() : favouriteFood(){
        type = COW;
    }
    PassiveMob(mobType mType, Item food, List<Item> drops, int dropChance, int h, int bh, int sa, int s, int hp) : Mob(drops,dropChance, h, bh,sa,s,hp) {
        favouriteFood = food;
        type = mType;
    }
    PassiveMob(const PassiveMob &pm) : Mob((Mob)pm) {
        type = pm.type;
        favouriteFood = pm.favouriteFood;
    }

    mobType getType () {return type;}
    Item getFavFood () {return favouriteFood;}

    void setType (mobType t) {type = t;}
    void setFavFood (Item ff) {favouriteFood = ff;}
};

#endif // PASSIVEMOB_H_INCLUDED
