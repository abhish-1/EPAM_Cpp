//Write a C++ program that: Defines a Counter class with a static
// data member to track active objects (static int count)
// Implements a constructor that increments count when a new object is created
#include<iostream>
using namespace std;
class Counter {
public:
    static int count;
    //You cant really define a static member inside the class, take an example 2 different files have included this class
    //in their header, now compilaiton k time to header mtlb ki class poori ki poori paste ho jaegi dono files m, dono files m static int count define ho jaegi
    //ab dono files alag alag compilation k time pe count ko define karengi to error aayega ki count multiple defined hai.
    //I was confused ki next time  value 0 ho jaegi pr nhi wo assign nhi ho rhi h its initialization, 2 different files m multiple definition ho rhi h
    //isliye static members ko class k bahar define karna padta h.
    Counter() {
        count++;
    }
    void showCounter(){
        cout<<Counter::count<<endl;
    }
};
  int Counter::count =0;
    void Counter :: showCounter(){
        cout<<Counter::count<<endl;
    }
  int main(){
    Counter c1;
    Counter c2;
    Counter c3;
    Counter::showCounter();
    return 0;

}