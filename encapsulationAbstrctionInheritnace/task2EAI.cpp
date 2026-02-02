//Defines a Temperature class with a private data member: double celsius Implements setCelsius(double) 
// to assign values only if they are not below -273.15 (absolute zero); otherwise, rejects the input 
// Implements getCelsius() accessor to retrieve the current celsius value Implements getFahrenheit() 
// accessor to convert and return temperature in Fahrenheit Demonstrates that direct access to celsius
// is impossible from outside the class

#include <iostream>
using namespace std;
class Temperature {
private:
    double celsius;
public:
    //temperature only if above absolute zero
    void setCelsius(double value) {
        if (value >= -273.15) {
            celsius = value;
        }
        else {
            cout << "Invalid temperature";
        }
    }

    // Accessor for Celsius
    double getCelsius() const {
        return celsius;
    }

    // Convert Celsius to Fahrenheit
    double getFahrenheit() const {
        return (celsius * 9.0/ 5.0) + 32;
    }
};

int main() {
    Temperature temp;

    temp.setCelsius(25);
    cout << "Celsius: " << temp.getCelsius() << endl;
    cout << "Fahrenheit: " << temp.getFahrenheit() << endl;

    temp.setCelsius(-300);  

    return 0;
}
