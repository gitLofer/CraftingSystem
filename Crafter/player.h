#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "entity.h"
#include "armorSet.h"
#include "expBar.h"
#include "hungerBar.h"
#include "inventory.h"

class Player : public Entity {
private:
    Inventory invent;
    HungerBar hunger;
    ExpBar exp;
    ArmorSet armor;
    bool isPoisoned;
    bool isWithered;
    bool isSprint;
    bool onFire;
public:
    Player() : invent(), hunger(), exp(), armor() {
        isSprint = false;
        isPoisoned = false;
        isWithered = false;
        onFire = false;
    }
    Player(Inventory inv, HungerBar hun, ExpBar experience, ArmorSet a, bool sprint, bool wither, bool poison, bool fire) {
        invent = inv;
        hunger = hun;
        exp = experience;
        armor = a;
        isSprint = sprint;
        isPoisoned = poison;
        isWithered = wither;
        onFire = fire;
    }
    Player(const Player &p) : Entity((Entity)p) {
        invent = p.invent;
        hunger = p.hunger;
        exp = p.exp;
        armor = p.armor;
        isSprint = p.isSprint;
        isPoisoned = p.isPoisoned;
        isWithered = p.isWithered;
        onFire = p.onFire;
    }

    ExpBar getExp() const {return exp;}
    void setExp(ExpBar e) {exp = e;}

    Inventory getInventory() const {return invent;}
    void setInventory(Inventory i) {invent = i;}

    HungerBar getHunger() const {return hunger;}
    void setHunger(HungerBar h) {hunger = h;}

    bool getPoison() const {return isPoisoned;}
    void setPoison(bool b) {isPoisoned = b;}

    bool getWithered() const {return isWithered;}
    void setWithered(bool b) {isWithered = b;}

    bool getFire() const {return onFire;}
    void setFire(bool b) {onFire = b;}

    bool getSprint() const {return isSprint;}
    void setSprint(bool b) {isSprint = b;}

    void beDamaged(int amountOf) {
        armor.takeHit();
        health.loseAmnt(amountOf);
    }

    int damageOutput () {
        Item current = invent.currentlySelected();
        if (current.getType() == SWORD) {
            return (7 - current.getMaterial());
        }else {
            return 1;
        }
    }

    void drinkMilk () {
        isPoisoned = false;
        isWithered = false;
        hunger.setHunger(false);
        return;
    }

    friend ostream &operator<< ( ostream &output, const Player &p) {
        output << "Currently selected item: " << endl << p.getInventory().currentlySelected() << endl << "Health: " << p.getHealth().getAmount() << " - Hunger: " << p.getHunger().getAmount() << " - Exp level: " << p.getExp().getLevel();
        return output;
    }

    friend istream &operator>> (istream &input, Player &p) {
        int hpAmount, expLvl, hungerAmount;
        input >> hpAmount >> expLvl >> hungerAmount;
        p.getHealth().setAmount(hpAmount);
        p.getExp().setLevel(expLvl);
        p.getHunger().setAmount(hungerAmount);
        return input;
    }
};

#endif // PLAYER_H_INCLUDED
