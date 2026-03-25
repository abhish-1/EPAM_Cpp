// Defines a polymorphic hierarchy (e.g., Animal base class with virtual destructor, Dog and Cat derived classes, each with a specific method)
// Stores pointers to objects as base class pointers
// Uses typeid(*ptr) to print the actual type name
// Uses dynamic_cast to check and call derived-class-specific methods from base pointers
// Briefly compares when to use typeid and when to use dynamic_cast
// Comments about what happens if RTTI is disabled (e.g., with compiler options)

#include<iostream>
using namespace std;
class Animal{
    public:
    virtual ~Animal(){
        cout<<"destructor"<<endl;
    }
};
class Cat : public Animal{
    public:
    void meow(){
        cout<<"meow"<<endl;
    }
};
class Dog : public Animal{
    public:
    void bark(){
        cout<<"Bark"<<endl;
    }
};

int main(){
    Animal* ptr = new Cat();
    Animal* ptr1 = new Dog();
    cout<<typeid(ptr).name()<<endl;
    cout<<typeid(*ptr).name()<<endl;

    cout<<typeid(ptr1).name()<<endl;
    cout<<typeid(*ptr1).name()<<endl;

    Cat* cptr = dynamic_cast<Cat*> (ptr);
    cptr-> meow();
    Dog* dptr = dynamic_cast<Dog*> (ptr1);
    dptr-> bark();

    delete(ptr);
    delete(ptr1);
    

}