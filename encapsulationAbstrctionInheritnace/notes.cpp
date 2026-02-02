#include<iostream>
using namespace std;
class Animal {
public:
    virtual void speak() {
        cout << "Animal sound" << endl;
    }
};
class Dog : public Animal {
public:
    void speak() {
        cout << "Bark" << endl;
    }
};
int main() {
    Animal* dog1 = new Dog;
    cout << "Creation of dog via animal pointer successsfull" << endl;
    Dog* dog2 = new Dog;
    cout << "Creation of dog via dog pointer successsfull" << endl;
    Animal* animal = new Animal;
    cout << "Creation of Animal via dog pointer successsfull" << endl;
    animal->speak();  //animal sound
    dog1->speak();    //Bark 
    //Without virtual, function calls are resolved at compile time based on 
    // pointer / reference type(static binding).
    //With virtual, function calls are resolved at runtime based on actual 
    // object type (dynamic binding), enabling polymorphism.
    dog2->speak();   //Bark
}
