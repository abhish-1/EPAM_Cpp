//Defines a base class LivingBeing(e.g., with a member id or name and a show() method)
// Defines Animal and Plant, both virtually inheriting from LivingBeing Defines Hybrid,
// inheriting from both Animal and Plant In main(), instantiates Hybrid and accesses
// LivingBeing's member via both Animal and Plant paths Prints addresses via each path
// to show only one LivingBeing instance exists in Hybrid

#include <iostream>
using namespace std;

class LivingBeing {
public:
    int id;
    void show() {
        cout << "LivingBeing id: " << id << endl;
    }
    ~LivingBeing() {
        cout << "livingBeing destructor" << endl;
    }
};

class Animal : virtual public LivingBeing {
public:
    ~Animal() {
        cout << "animal destructor" << endl;
    }
};

class Plant : virtual public LivingBeing {
public:
    ~Plant() {
        cout << "plant destructor" << endl;
    }
};

class Hybrid : public Animal, public Plant {
public:
    ~Hybrid() {
        cout << "hybrid destructor" << endl;
    }
};

int main() {
    Hybrid h;

    h.id = 10;

    h.show();                 // works fine, no ambiguity

    LivingBeing* p1 = static_cast<Animal*>(&h);
    LivingBeing* p2 = static_cast<Plant*>(&h);

    cout << "LivingBeing via Animal: " << p1 << endl;
    cout << "LivingBeing via Plant:  " << p2 << endl;

    return 0;
}
