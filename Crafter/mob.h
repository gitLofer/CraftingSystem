#ifndef MOB_H_INCLUDED
#define MOB_H_INCLUDED

#include "entity.h"
#include "item.h"
#include "list.hpp"

class Mob : public Entity {
protected:
    List<Item> dropCollection;
    int chanceOfDrop;
public:
    Mob(){
        chanceOfDrop = 0;
        blockHeight = 2;
        startingArmour = 0;
        speed = 5;
    }

    Mob(List<Item> drops, int dropChance, int h, int bh, int sa, int s, int hp) : Entity(h,bh, sa, s, hp) {
        dropCollection = drops;
        chanceOfDrop = dropChance;
    }
    Mob(const Mob &m) : Entity((Entity)m) {
        dropCollection = m.dropCollection;
        chanceOfDrop = m.chanceOfDrop;
    }

    int getDropChance () {return chanceOfDrop;}
    List<Item> getDrops () {return dropCollection;}

    void setDropChance (int dc) {chanceOfDrop = dc;}
    void setDrops (List<Item> drops) {dropCollection = drops;}

};

#endif
