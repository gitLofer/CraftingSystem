#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "healthbar.h"

class Entity {
protected:
    Healthbar health;
    int blockHeight;
    int startingArmour;
    int speed;
public:
    Entity() : health(){
        blockHeight = 2;
        startingArmour = 0;
        speed = 5;
    }

    Entity(int h, int bh, int sa, int s, int hp) : health(false, false, h, hp) {
        blockHeight = bh;
        startingArmour = sa;
        speed = s;
    }
    Entity(const Entity &et) {
        health = et.health;
        blockHeight = et.blockHeight;
        startingArmour = et.startingArmour;
        speed = et.speed;
    }

    Healthbar getHealth() const {return health;}
    int getHeight() const {return blockHeight;}
    int getArmour() const {return startingArmour;}
    int getSpeed() const {return speed;}

    void setHealth(Healthbar hp) {health = hp;}
    void setHeight(int param) {blockHeight = param;}
    void setArmour(int param) {startingArmour = param;}
    void setSpeed(int param) {speed = param;}

};

#endif // ENTITY_H_INCLUDED
