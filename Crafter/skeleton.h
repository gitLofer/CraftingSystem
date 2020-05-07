#ifndef SKELETON_H_INCLUDED
#define SKELETON_H_INCLUDED

#include "humanoidMob.h"
#include "armorSet.h"
#include "item.h"
#include "list.hpp"

class Skeleton : public HumanoidMob {
private:
    bool isWithered;
public:
    Skeleton()
    {isWithered = false;}
    Skeleton(bool wither, ArmorSet arm, Item wep, bool wet, int dmg, bool daytime, List<Item> drops, int dropChance, int h, int bh, int sa, int s, int hp) : HumanoidMob ( arm, wep, wet, dmg, daytime, drops, dropChance, h, bh, sa, s, hp)
    {isWithered = wither;}
    Skeleton(const Skeleton &z) {
        isWithered = z.isWithered;
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
        //HumanoidMob
        armor = z.armor;
        weapon = z.weapon;
        isWet = z.isWet;
    }

    bool getWither() const {return isWithered;}
    void setWither(bool b) {isWithered = b;}

    bool burn() {
        if (isDay) {
        health.loseAmnt(1);
        /// Insert movement script here
        return true;
        }
        return false;
    }

    friend ostream &operator<< ( ostream &output, const Skeleton &z) {
        output << "Equipped weapon:" << endl << z.getWeapon() << endl << "Health: " << z.getHealth().getAmount() << " - Damage: " << z.getDamage();
        return output;
    }

    friend istream &operator>> (istream &input, Skeleton &z) {
        int hp;
        input >> hp >> z.damage >> z.isWithered;
        z.health.setAmount(hp);
        return input;
    }

};

#endif // SKELETON_H_INCLUDED
