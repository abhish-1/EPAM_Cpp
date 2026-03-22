// Defines a class (e.g., Widget) with a message in its constructor and destructor.
// Implements a function that creates a std::unique_ptr<Widget> to a heap-allocated object, returning this pointer.
// In main, calls the function and observes that when the unique_ptr goes out of scope, the object is deleted automatically (no manual delete needed).
// Optionally, shows manual new/delete for comparison, highlighting advantages of smart pointers.

#include<iostream>
#include<memory>
class Widget{
    public:
    Widget(){
        std::cout<<"constructor"<<std::endl;
    }
    ~Widget(){
        std::cout<<"destructor"<<std::endl;
    }
};
std::unique_ptr<Widget> func(){
    return std::unique_ptr<Widget>(new Widget());
}
int main(){
    std::unique_ptr<Widget> pointer(func());
    std::cout<<"main function completion"<<std::endl;
    std::cout<<std::endl<<"Using new/delete"<<std::endl;
    Widget* p = new Widget();
    delete(p);
    p = nullptr;
    std::cout<<"end of progg"<<std::endl;
    return 0;
}