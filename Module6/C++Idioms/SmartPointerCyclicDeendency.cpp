#include<iostream>
#include<memory>
using namespace std;
class B;
class A{
    weak_ptr<B> sp1;
    public:
    void pointerPoint(shared_ptr<B>& ptr){
        sp1=ptr;
        // sp1 ab usi object ko point karega jise ptr point kar raha hai
    }
    ~A(){
        cout<<"destructor A"<<endl;
    }
};
class B{
    weak_ptr<A> sp2;
    public:
    void pointerPoint(shared_ptr<A>& ptr){
        sp2=ptr;
    }
    ~B(){
        cout<<"destructor B"<<endl;
    }
};
int main(){
    shared_ptr<A> ptrA = make_shared<A>();
    shared_ptr<B> ptrB = make_shared<B>();
    ptrA->pointerPoint(ptrB);
    ptrB->pointerPoint(ptrA);
    cout<<ptrA.use_count();
    cout<<ptrB.use_count();
}