#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED

#include "humanoidMob.h"
#include "item.h"
#include "list.hpp"
#include "player.h"

class Zombie : public HumanoidMob {
private:
    bool isBaby;
public:
    Zombie() {
        isBaby = false;
    }
    Zombie(bool baby, ArmorSet arm, Item wep, bool wet, int dmg, bool daytime, List<Item> drops, int dropChance, int h, int bh, int sa, int s, int hp) : HumanoidMob ( arm, wep, wet, dmg, daytime, drops, dropChance, h, bh, sa, s, hp)
    {isBaby = baby;}
    Zombie(const Zombie &z) {
        isBaby = z.isBaby;
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

    bool getBaby() const {return isBaby;}
    void setBaby(bool b) {isBaby = b;}

    bool burn() {
        if (isDay) {
        health.loseAmnt(1);
        return true;
        }
        return false;
    }

    friend ostream &operator<< ( ostream &output, const Zombie &z) {
        output << "Equipped weapon:" << endl << z.getWeapon() << endl << "Health: " << z.getHealth().getAmount() << " - Damage: " << z.getDamage();
        return output;
    }

    friend istream &operator>> (istream &input, Zombie &z) {
        int hp;
        input >> hp >> z.damage >> z.isBaby;
        z.health.setAmount(hp);
        return input;
    }
};

#endif // ZOMBIE_H_INCLUDED
