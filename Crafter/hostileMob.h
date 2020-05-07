#ifndef HOSTILEMOB_H_INCLUDED
#define HOSTILEMOB_H_INCLUDED

#include "mob.h"
#include "player.h"

class HostileMob : public Mob {
protected:
    int damage;
    bool isDay;
public:
    HostileMob() {
        damage = 1;
        isDay = false;
    }
    HostileMob(int dmg, bool daytime, List<Item> drops, int dropChance, int h, int bh, int sa, int s, int hp) : Mob(drops,dropChance, h, bh,sa,s,hp) {
        damage = dmg;
        isDay = daytime;
    }
    HostileMob(const HostileMob &hm) : Mob((Mob)hm) {
        damage = hm.damage;
        isDay = hm.isDay;
    }

    int getDamage () const {return damage;}
    bool getDay () const {return isDay;}

    void setDamage (int dmg) {damage = dmg;}
    void setDay (bool day) {isDay = day;}

    virtual void dealDamage (Player pl) = 0;
};

#endif // HOSTILEMOB_H_INCLUDED
