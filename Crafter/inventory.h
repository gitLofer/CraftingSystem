#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include "item.h"
#include "list.hpp"

class Inventory {
protected:
    List<Item> inv;
    List<Item> hotbar;
    int invMax;
    int hotbarMax;
    int hotbarSelect;
public:
    Inventory() {
        invMax = 27;
        hotbarMax = 9;
        hotbarSelect = 1;
    }
    Inventory(int inventMax, int hotMax, int sel) {
        invMax = inventMax;
        hotbarMax = hotMax;
        hotbarSelect = sel;
    }
    Inventory(const Inventory &in) {
        inv = in.inv;
        hotbar = in.hotbar;
        invMax = in.invMax;
        hotbarMax = in.hotbarMax;
        hotbarSelect = in.hotbarSelect;
    }

    int getMaxInv() const {return invMax;}
    int getMaxHotbar() const {return hotbarMax;}
    int getCurrSelect() const {return hotbarSelect;}
    List<Item> getInvent() const {return inv;}
    List<Item> getHotbar() const {return hotbar;}

    void setMaxInv(int a) {invMax = a;}
    void setMaxHotbar(int a) {hotbarMax = a;}
    void setCurrSelect(int a) {hotbarSelect = a;}
    void setInvent(List<Item> invent) {inv = invent;}
    void setHotbar(List<Item> hb) {hotbar = hb;}

    void addItemToInventory (Item subject) {
        if (invMax != inv.size()) {
            inv.add(1, subject);
        }
    }

    void addItemToHotbar (Item subject) {
        if (hotbarMax != hotbar.size()) {
            hotbar.add(1, subject);
        }
    }

    Item currentlySelected() {
        Item a;
        hotbar.read(hotbarSelect, a);
        return a;
    }
};

#endif // INVENTORY_H_INCLUDED
