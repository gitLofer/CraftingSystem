#include <windows.h>
#include <iostream>
#include <cmath>

#include "list.hpp"
#include "dinstring.hpp"

#include "recipe.h"
#include "enchantment.h"
#include "item.h"
#include "armorSet.h"
#include "inventory.h"

#include "player.h"
#include "entity.h"

#include "mob.h"
#include "passiveMob.h"
#include "hostileMob.h" // Abstract
#include "humanoidMob.h" // Abstract
#include "zombie.h"
#include "skeleton.h"
#include "spider.h"

#include "bar.h"
#include "expBar.h"
#include "healthbar.h"
#include "hungerBar.h"


int main() {
    /// Empty consutrctors
    Item it;
    Recipe r;
    Enchantment e;
    ArmorSet as;
    Inventory i;
    Player p;
    Entity ent;
    Mob m;
    PassiveMob passM;
    Zombie z;
    Skeleton sk;
    Spider sp;
    Bar b;
    ExpBar exp;
    Healthbar hp;
    HungerBar hunger;
    ///Prep
    int* grid =(int*) calloc(9, sizeof(int));
    List<Enchantment> ench;
    List<Item> drops;
    drops.add(1,it);
    ench.add(1, e);
    /// Constructs with params
    Item it1(HELMET, false, grid, 1, 1, 120, GOLD, "Shiny", ench);
    drops.add(1, it1);
    Recipe r1(false, grid);
    Enchantment e1(Sharpness, 2);
    ArmorSet as1 (it1, it, it ,it);
    Inventory i1(20, 9, 1);
    Player p1(i, hunger, exp, as, true, false, false, false);
    Entity ent1(10, 2, 0, 4, 10);
    Mob m1(drops, 25, 10, 2, 0, 10, 10);
    PassiveMob passM1(CHICKEN, it, drops, 5, 1, 2, 0, 10, 5);
    Skeleton sk1(true, as, it, true, 4, false, drops, 12, 15, 2, 1, 7, 15);
    Spider sp1(false, true, 2, true, drops, 50, 10, 2, 1, 7, 10);
    Bar b1(20, 20);
    ExpBar exp1(3, 100, 100);
    Healthbar hp1(false, true, 15, 20);
    HungerBar hunger1(false, 20, 20);
    Zombie z1(false, as, it, true, 4, false, drops, 80, 15, 2, 1, 7, 15);
    /// Copy constructs;
    it1 = it;
    r = r1;
    e1 = e;
    as = as1;
    i1 = i;
    p1 = p1;
    ent = ent1;
    m1 = m;
    passM = passM1;
    z = z1;
    sk1 = sk;
    sp = sp1;
    b1 = b;
    exp = exp1;
    hp = hp1;
    hunger1 = hunger;
    cout << it1 << endl << sk1 << endl << z << endl << p;
    cout << endl << exp.getLevel() << endl;
    ++exp;
    cout << exp.getLevel();
    return 0;
}
