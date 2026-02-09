//Defines a Printable interface with a pure virtual print() function Defines a
// Savable interface with a pure virtual save() function Implements a Document
// class publicly inheriting both interfaces, providing definitions for print()
// and save() Demonstrates using a Document via pointers to Printable and Savable,
// and calling respective functions
#include <iostream>
using namespace std;
class Printable {
public:
    virtual void print() = 0;
};
class Savable {
public:
    virtual void save() = 0;
};
class Document : public Savable, public Printable {
public:
    Document() {
        cout << "Document() constructor" << endl;
    }
    void save() override { cout << "Document::save()" << endl; }
    void print() override { cout << "Document::print()" << endl; }
};

int main() {
    cout << "Creating Doc type object:" << endl;
    Document* doc = new Document;
    Printable* ptr = static_cast<Printable*>(doc);
    cout << "Lets call and see the result of  printable* pointer which is of type Document calling print()" << endl;
    ptr->print();
    Savable* ptr2 = static_cast<Savable*>(doc);
    cout << "Lets call and see the result of  savable* pointer which is of type Document calling save()" << endl;
    ptr2->save();

    cout << "Lets free up the pointers and put them to null" << endl;
    delete(doc);
    doc = nullptr;
    ptr = nullptr;
    ptr2 = nullptr;
    cout << "deletion successful" << endl;
    return 0;
}
