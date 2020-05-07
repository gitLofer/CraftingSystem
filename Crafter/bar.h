#ifndef BAR_H_INCLUDED
#define BAR_H_INCLUDED

class Bar {
protected:
    int amount;
    int maxAmount;
public:
    Bar() {
    amount = 20;
    maxAmount = 20;
    }
    Bar(int a, int b) {amount = a; maxAmount = b;}
    Bar (const Bar &b) {amount = b.amount; maxAmount = b.maxAmount;}

    int getAmount() const {return amount;}
    int getMaxAmount() const {return maxAmount;}

    void setAmount(int a) {
        if (a > maxAmount) {
            maxAmount = a;
        }
        amount = a;
    }
    void setMaxAmount(int a) {
        if (a < amount) {
            amount = a;
        }
        maxAmount = a;
    }

    void loseAmnt(int a) {
        if (amount >= a) {
            amount = 0;
        } else{
            amount -= a;
        }
    }

    void gainAmnt(int a) {
        if (amount+a >= maxAmount) {
            amount = maxAmount;
        }else{
            amount += a;
        }
    }
    // Prefix
    Bar operator++ () {
        gainAmnt(1);
        return Bar(amount, maxAmount);
    }
};

#endif // BAR_H_INCLUDED
