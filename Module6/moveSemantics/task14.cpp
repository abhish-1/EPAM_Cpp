#include <iostream>
#include <cstring>
#include <utility>

class Base {
protected:
    int* baseData;
public:
    Base() : baseData(new int(99)) {
        std::cout << "Base constructed: " << baseData << " (" << *baseData << ")\n";
    }
    // Rule of 5 nig
    Base(const Base& other) : baseData(new int(*other.baseData)) {
        std::cout << "Base copy ctor: " << baseData << " (" << *baseData << ")\n";
    }
    Base& operator=(const Base& other) {
        if (this != &other) {
            *baseData = *other.baseData;
            std::cout << "Base copy assign: (" << *baseData << ")\n";
        }
        return *this;
    }
    Base(Base&& other) noexcept : baseData(other.baseData) {
        other.baseData = nullptr;
        std::cout << "Base move ctor: " << baseData << '\n';
    }
    Base& operator=(Base&& other) noexcept {
        if (this != &other) {
            delete baseData;
            baseData = other.baseData;
            other.baseData = nullptr;
            std::cout << "Base move assign: " << baseData << '\n';
        }
        return *this;
    }
    virtual ~Base() {
        std::cout << "Base dtor: " << baseData << "\n";
        delete baseData;
    }
    virtual void print(const char* lbl) const {
        std::cout << lbl << " Base data: " << baseData << " (" << (baseData ? *baseData : 0) << ")\n";
    }
};
class Derived : public Base {
    char* derivedData;
public:
    Derived() : Base(), derivedData(new char[8]) {
        strcpy(derivedData, "abc123");
        std::cout << "Derived constructed: " << static_cast<void*>(derivedData) << '\n';
    }
    Derived(const Derived& other) : Base(other), derivedData(new char[strlen(other.derivedData)+1]) {
        strcpy(derivedData, other.derivedData);
        std::cout << "Derived copy ctor: " << static_cast<void*>(derivedData) << " (" << derivedData << ")\n";
    }
    Derived& operator=(const Derived& other) {
        if (this != &other) {
            Base::operator=(other);
            delete[] derivedData;
            derivedData = new char[strlen(other.derivedData)+1];
            strcpy(derivedData, other.derivedData);
            std::cout << "Derived copy assign: " << static_cast<void*>(derivedData) << '\n';
        }
        return *this;
    }
    Derived(Derived&& other) noexcept : Base(std::move(other)), derivedData(other.derivedData) {
        other.derivedData = nullptr;
        std::cout << "Derived move ctor: " << static_cast<void*>(derivedData) << '\n';
    }
    Derived& operator=(Derived&& other) noexcept {
        if (this != &other) {
            Base::operator=(std::move(other));
            delete[] derivedData;
            derivedData = other.derivedData;
            other.derivedData = nullptr;
            std::cout << "Derived move assign: " << static_cast<void*>(derivedData) << '\n';
        }
        return *this;
    }
    ~Derived() override {
        std::cout << "Derived dtor: " << static_cast<void*>(derivedData) << "\n";
        delete[] derivedData;
    }
    void print(const char* lbl) const override {
        Base::print(lbl);
        std::cout << lbl << " Derived data: " << static_cast<const void*>(derivedData)
                  << " (" << (derivedData ? derivedData : "null") << ")\n";
    }
};
int main() {
    std::cout << " Base test \n";
    Base b1;

    std::cout << " Derived test \n";
    Derived d1;
    d2 = std::move(d1); 

    std::cout << " Slicing demo \n";
    Base sliced = d2;   
    sliced.print("sliced: ");
    d2.print("d2: ");

    std::cout << " Polymorphic deletion \n";
    Base* poly = new Derived();
    delete poly;       
    return 0;
}
