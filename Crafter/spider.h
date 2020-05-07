#ifndef SPIDER_H_INCLUDED
#define SPIDER_H_INCLUDED

#include "hostileMob.h"
#include "armorSet.h"
#include "item.h"
#include "list.hpp"
#include "player.h"

class Spider : public HostileMob {
private:
    bool isAggressive;
    bool isPoisonous;
public:
    Spider()
    {
        isAggressive = false;
        isPoisonous = false;
        blockHeight = 1;
    }
    Spider(bool aggro, bool poison, int dmg, bool daytime, List<Item> drops, int dropChance, int h, int bh, int sa, int s, int hp) : HostileMob ( dmg, daytime, drops, dropChance, h, bh, sa, s, hp)
    {
        isAggressive = aggro;
        isPoisonous = poison;
    }
    Spider(const Spider &z) {
        isAggressive = z.isAggressive;
        isPoisonous = z.isPoisonous;
        // Entity
        health = z.health;
        blockHeight = z.blockHeight;
        startingArmour = z.startingArmour;
        speed = z.speed;
        //Mob
        dropCollection = z.dropCollection;
        chanceOfDrop = z.chanceOfDrop;
        //HostileMob
        damage = z.damage;
        isDay = z.isDay;
    }

    bool getAggro() {return isAggressive;}
    bool getPoison() {return isPoisonous;}
    void setAggro(bool b) {isAggressive = b;}
    void setPoison(bool b) {isPoisonous = b;}

    void dealDamage (Player pl) {
        pl.beDamaged(damage);
        return;
    }
};

#endif // SPIDER_H_INCLUDED
