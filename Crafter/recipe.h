#ifndef RECIPE_H_INCLUDED
#define RECIPE_H_INCLUDED

class Recipe {
private:
    bool isCraftable;
    int* recipeGrid;
public:
    Recipe() {
        isCraftable = false;
        recipeGrid =(int*) calloc(9, sizeof(int));
    }
    Recipe(bool craftable, int* grid) {
        isCraftable = craftable;
        recipeGrid =(int*) calloc(9, sizeof(int));
        if (isCraftable == true) {
            for (int i = 0; i < 9; ++i) {
            recipeGrid[i] = grid[i];
            }
        }
    }
    Recipe(const Recipe &rec) {
        isCraftable = rec.isCraftable;
        recipeGrid =(int*) calloc(9, sizeof(int));
        for (int i = 0; i < 9; ++i) {
            recipeGrid[i] = rec.recipeGrid[i];
        }
    }
    void setCraftable (bool ic) {isCraftable = ic;};
    bool getCraftable () {return isCraftable;}

    void setRecipe(int* grid) {
        for (int i = 0; i < 9; ++i) {
            recipeGrid[i] = grid[i];
        }
    }
    int* getRecipe() {return (int*)recipeGrid;}
};

#endif // RECIPE_H_INCLUDED
