//Defines a class Item with a constructor and destructor that print identifying messages (class Item) Allocates a single
//Item using new (Item* single = new Item) Allocates an array of Items using new[] (Item* arr = new Item[3]) Frees the
//single Item using delete (delete single) Frees the array of Items using both delete and delete[] (try both to show
//correct and incorrect usage) Observes output: Note which destructors are called, and if any unexpected behavior
//occurs on mismatch

#include<iostream>
using namespace std;
class Item {
public:
    Item() {
        cout<<"The object is created"<<endl;
    }
    ~Item() {
        cout<<"The object is deleted"<<endl;
    }
};
int main() {
    Item* single = new Item;
    cout<<"A single object gets created"<<endl;
    Item* arr = new Item[5];
    cout<<"An array of objects is created"<<endl;
    delete(single);
    cout<<"Deletion of single object is complete"<<endl;
    delete[](arr);
    cout<<"Deletion of arr is done"<<endl;
}