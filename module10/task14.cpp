// vtable_crash.cpp
#include <iostream>
class Base {
public:
    virtual void foo() { std::cout << "Base::foo" << std::endl; }
    virtual ~Base() {}
};
class Derived : public Base {
public:
    void foo() override { std::cout << "Derived::foo" << std::endl; }
};

int main() {
    Base* obj = new Derived();
    delete obj;
    obj->foo(); // CRASH: call virtual on deleted object
    return 0;
}
