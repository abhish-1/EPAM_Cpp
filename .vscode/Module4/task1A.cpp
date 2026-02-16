//Asks the user for their name, age, and city Uses std::cin to read each value from the console Uses std::cout to
// print a greeting in the format: "Hello <name>, you are <age> and live in <city>."

#include <iostream>
#include <string>
using namespace std;
int main(){
    string name;
    int age;
    string city;
    cout<<"Hey please enter your name"<<endl;
    getline(cin,name);
    cout<<"Please enter your age"<<endl;
    cin>>age;
    cin.ignore();
    cout<<"Hey please enter your city"<<endl;
    getline(cin,city);
    cout<<"Hello "<<name<<", you are "<<age<<" and live in " <<city;
}
