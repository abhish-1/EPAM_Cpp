//Declares a Person class with members: name (std::string) and age (int) Overloads operator<< and operator>> so you can chain 
//operations like: std::cin >> p >> anotherPerson; std::cout << p << anotherPerson; Demonstrates this chaining in main()

#include<iostream>
#include<string>
using namespace std;
class Person{
    string name;
    int age;
    public:
    Person(): name(""),age(-1) {}
    Person(string name, int age): name(name),age(age) {}
    friend ostream& operator<<(ostream& COUT, const Person& p);
    friend istream& operator>>(istream& CIN, Person& p);

};
ostream& operator<<(ostream&  COUT,const Person& p){
    COUT<<p.name<<" "<<p.age;
    return COUT;
    
}
istream& operator>>(istream&  CIN,Person& p){
    cout<<"enter name";
    getline(CIN,p.name);
    cout<<"enter age";
    CIN>>p.age;
    CIN.ignore(numeric_limits<streamsize>::max(), '\n'); // discard leftover newline
    return CIN;
}
int main(){
    Person p1,p2;
    cin>>p1>>p2;
    cout<<p1<<endl<<p2;
}


