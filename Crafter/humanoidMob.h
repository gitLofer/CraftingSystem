#ifndef HUMANOIDMOB_H_INCLUDED
#define HUMANOIDMOB_H_INCLUDED

#include "hostileMob.h"
#include "armorSet.h"

class HumanoidMob : public HostileMob {
protected:
    ArmorSet armor;
    Item weapon;
    bool isWet;
public:
    HumanoidMob() : armor(), weapon()
    {isWet = false;}
    HumanoidMob(ArmorSet arm, Item wep, bool wet, int dmg, bool daytime, List<Item> drops, int dropChance, int h, int bh, int sa, int s, int hp) : HostileMob(dmg, daytime, drops, dropChance, h, bh, sa, s, hp) {
        armor = arm;
        weapon = wep;
        isWet = wet;
    }
    HumanoidMob(const HumanoidMob &hm) {
        armor = hm.armor;
        weapon = hm.weapon;
        isWet = hm.isWet;
        // Entity
        health = hm.health;
        blockHeight = hm.blockHeight;
        startingArmour = hm.startingArmour;
        speed = hm.speed;
        //Mob
        dropCollection = hm.dropCollection;
        chanceOfDrop = hm.chanceOfDrop;
        //HostileMob
        damage = hm.damage;
        isDay = hm.isDay;
    }

    ArmorSet getArmor() const {return armor;}
    Item getWeapon() const {return weapon;}
    bool getWet() const {return isWet;}

    void setAmor(ArmorSet as) {armor = as;}
    void setWeapon(Item w) {weapon = w;}
    void setWet(bool wet) {isWet = wet;}

    void dealDamage(int amount) {
        // target.Entity::takeDamage(amount);
        weapon.useItem();
    }

    void beDamaged(int amountOf) {
        armor.takeHit();
        health.loseAmnt(amountOf);
    }

    void dealDamage (Player pl) {
        pl.beDamaged(damage);
        pl.setFire(isDay);
        return;
    }


    virtual bool burn() = 0;
};

#endif // HUMANOIDMOB_H_INCLUDED
