#include <vector>
#include <string>
#include <state.h>

#define     MAXEFFECTS      6          //The maximum number of discoverable or known effects an ingredient might have

using namespace std;

// struct ingredient {
//     effect possibleEffects[MAXEFFECTS];
// };

class Product {
    public:                   
        std::vector<string> madeWith;           //the ingredients that went into this product
        string effect;                          //What the product actually does
        Product();
        Product(std::vector<string> ingredients, string effect);
        virtual ~Product();
};

Product::Product() {};

Product::Product(std::vector<string> ingredients, string effect) {

    madeWith = ingredients;
    effect = effect;
}

Product::~Product() {};

class Potion : public Product {
    public:
        int duration;                           //How long the effects persist                          --      belongs to potions instead probably
        int timeToEffect;                       //How long it takes for the effects reach the user      --      belongs to potions instead probably
        Potion(std::vector<string> ingredients, std::vector<string> effects, int duration, int timeToEffect);
};