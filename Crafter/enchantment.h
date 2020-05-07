#ifndef ENCHANTMENT_H_INCLUDED
#define ENCHANTMENT_H_INCLUDED

enum enchant {Sharpness, Fire_Aspect, Bane_of_Arthopods, Smite, Unbreaking, Thorns, Protection, Fire_Resistance, Blast_protection, None};

class Enchantment {
protected:
    enchant typeOfEnchant;
    int level;
public:
    Enchantment(){
        typeOfEnchant = None;
        level = 0;
    }
    Enchantment(enchant type, int lvl) {
        typeOfEnchant = type;
        level = lvl;

    }
    Enchantment(const Enchantment &e2) {
        typeOfEnchant = e2.typeOfEnchant;
        level = e2.level;
    }

    enchant getEnchant() const {
        return typeOfEnchant;
    }
    int getLvl () const {
        return level;
    }

    void setEnchant(enchant e){
        typeOfEnchant = e;
        return;
    }
    void setLevel (int l) {
        level = l;
    }
};

#endif // ENCHANTMENT_H_INCLUDED

