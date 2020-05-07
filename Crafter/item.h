#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include "enchantment.h"
#include "recipe.h"
#include "list.hpp"
#include <iostream>

enum itemType {HELMET, CHESTPLATE, LEGGINGS, BOOTS, PICKAXE, SHOVEL, SWORD, HOE, OTHER, EMPTY};
enum material {DIAMOND, IRON, GOLD, STONE, WOOD, NONE};

class Item {
private:
    itemType type;
    Recipe itemRecipe;
    string name;
    int maxAmount;
    int currAmount;
    int durability;
    material efficiency;
    List<Enchantment> enchantList;
public:
    Item() : itemRecipe() {
        name = "NONE";
        type = EMPTY;
        maxAmount = 1;
        currAmount = 1;
        // -1 Durability = No durability
        durability = -1;
        efficiency = NONE;
    }
    Item(itemType t, bool canCraft, int* craftGrid, int maxAmnt, int currAmnt, int durab, material mat, char* nm, List<Enchantment> enchants) : itemRecipe(canCraft, craftGrid), name(nm) {
        type = t;
        maxAmount = maxAmnt;
        currAmount = currAmnt;
        durability = durab;
        efficiency = mat;
        enchantList = enchants;
    }
    Item(const Item &it) {
        type = it.type;
        itemRecipe = it.itemRecipe;
        name = it.name;
        maxAmount = it.maxAmount;
        currAmount = it.currAmount;
        durability = it.durability;
        efficiency = it.efficiency;
        enchantList = it.enchantList;
    }

    itemType getType () const {return type;}
    Recipe getRecipe() const {return itemRecipe;};
    string getName () const {return name;}
    int getMaxAmount() const {return maxAmount;}
    int getCurrAmount() const {return currAmount;}
    int getDurability() const {return durability;}
    material getMaterial () const {return efficiency;}
    List<Enchantment> getEnchants () const {return enchantList;}

    void setType (itemType t) {type = t;}
    void setRecipe(Recipe r) {itemRecipe = r;};
    void setName (string s) {name = s;}
    void setMaxAmount(int a) {maxAmount = a;}
    void setCurrAmount(int a) {currAmount = a;}
    void setDurability(int a) {durability = a;}
    void setMaterial (material m) {efficiency = m;}
    void setEnchats (List<Enchantment> listEnch) {enchantList = listEnch;}

    bool useItem () {
        if (durability != -1) {
            durability--;
            if (durability == 0) {
                return true;
            }
        }
        return false;
    }

    void removeEnchant (int index) {
        enchantList.remove(index);
        return;
    }

    void addEnchant(Enchantment e) {
        enchantList.add(1, e);
        return;
    }

    Item operator+(const Item& i) {
        Item it;
        it.type = this->type;
        it.itemRecipe = this->itemRecipe;
        it.name = this->name;
        it.maxAmount = this->maxAmount;
        it.currAmount = this->currAmount;
        it.durability = this->durability;
        it.efficiency = this->efficiency;
        it.enchantList = this->enchantList;

        if (this->type == i.type && this->efficiency == i.efficiency) {
            if (this->maxAmount >= this->currAmount + i.currAmount) {
                it.currAmount = this->currAmount + i.currAmount;
            }
            if (this->durability != -1 && i.durability != -1){
                it.durability = this->durability + i.durability;
            }
        }
        return it;
    }

    friend ostream &operator<< ( ostream &output, const Item &i) {
        output << "Item name: " << i.name << endl << "Durability: " << i.durability << " - Amount: " << i.currAmount;
        return output;
    }

    friend istream &operator>> (istream &input, Item &i) {
        int tip, eff;
        input >> tip >> eff >> i.name >> i.maxAmount >> i.currAmount >> i.durability;
        i.type =(itemType) tip;
        i.efficiency =(material) eff;
        return input;
    }
};

#endif
