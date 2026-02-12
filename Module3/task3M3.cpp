//Defines a class Fraction with private members: numerator (int) and denominator (int) Overloads operator== 
//to check if two Fraction objects are equal in value (e.g., 1/2 == 2/4) Overloads operator< to compare two 
//Fraction objects (e.g., 1/3 < 1/2) Creates several Fraction objects in main() and compares them using == and <, displaying the results

#include<iostream>
using namespace std;
class Fraction{
    int numerator;
    int denominator;
    public: Fraction(int num, int denom){ 
        numerator = num; denominator = denom; 
    }
    bool operator==(Fraction&f1){
        return this->numerator * f1.denominator == this->denominator * f1.numerator; 
    } 
    
    bool operator<(Fraction& f1){
        return this->numerator * f1.denominator < this->denominator * f1.numerator;
    }
};
int main(){
    Fraction f1(4,5);
    Fraction f2(8,10); 
    Fraction f3(1,2); 
    cout<<(f1==f2)<<endl; 
    cout<<(f1<f3)<<endl;
    cout<<(f3<f1)<<endl;
    cout<<(f3==f2)<<endl; 
    return 0; 

    }