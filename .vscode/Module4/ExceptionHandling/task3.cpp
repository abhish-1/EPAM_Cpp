// //Task:
// Write a C++ program with following instructions
// Set Up the Foundation.
// Include all necessary C++ standard library headers for input/output, exceptions, strings, limits, vectors, formatting, and mathematical operations
// Create Custom Exception Class.
// Define a class named InvalidPriceException that publicly inherits from std::runtime_error
// Implement two constructors: one that takes a const char* parameter and another that takes a const std::string& parameter
// Both constructors should pass the received message to the base class constructor.
// Design the Product Class
// Create a Product class with private member variables for name (string), price (double), and stock (int)
// Implement a constructor that initializes all three member variables
// Create public getter methods for name, price, and stock
// Create a setter method for price
// Implement a display() method that shows product details with proper formatting
// Implement Price Input Validation Function.
// Create a function getNewPrice() that returns a double
// Prompt the user to enter a price and read the input
// Check for stream failure and throw InvalidPriceException with appropriate message if non-numeric input is detected Hint: Use cin.fail() to detect non-numeric input, throw InvalidPriceException("Error: Invalid product selection.")
// Validate that the price is positive and throw exception if not
// Check if price exceeds maximum allowed value (Rs. 10,000) and throw exception if it does
// Verify that price has no more than 2 decimal places and throw exception if invalid
// Clear the input buffer after successful reading
// Create Business Logic Validation Function.
// Implement a function updateProductPrice() that takes a Product reference parameter
// Display current product details
// Use a loop to repeatedly attempt price updates until successful
// Inside the loop, call getNewPrice() and catch any InvalidPriceException
// Calculate the percentage change from current price
// Throw exception if price change exceeds 50% (business rule)
// *Hint: * throw InvalidPriceException("Error: Price change cannot exceed 50% in single update.")
// If all validations pass, update the product price and display success message
// Build Inventory Management Functions.
// Create a function named "displayInventory" to display all products in inventory
// The function should take a Array of Products as parameter
// Display each product with numbering and formatted output
// Implement Main Application Logic.
// Initialize an array with sample products (minimum 3 Products).
// Display welcome message and program title
// Use a loop to allow multiple product updates
// Display inventory and prompt user to select a product
// Validate product selection and throw exception if invalid
// Call the price update function for selected product
// Handle all custom exceptions with appropriate error messages
// Provide option to continue or exit the program
// Display final inventory before program exit `
// -         do {
// -             try {
// -                 displayInventory();
// -                 // Code
// -             } catch (const InvalidPriceException& e) {
// -                 // Exception handling specific code
// -             }
// -         } while (continueUpdate == 'y' || continueUpdate == 'Y');
// 

#include<iostream>
#include<string>
#include<stdexcept>
#include<cmath>
#include<vector>
#include<limits>
#include<iomanip>
using namespace std;
class InvalidPriceException: public std::runtime_error{
    // const char* parameter;
    // const std::string& parameter1;
    // no need to keep these two runtime me pele se exist krta hai dono thus of no use here.
    public:
    InvalidPriceException(const char* parameter):runtime_error(parameter){
    }
    InvalidPriceException(const std::string& parameter1):runtime_error(parameter1){
    }
};

class Product{
    string name;
    double price;
    int stock;
    public:
    Product(string name,double price,int stock): name(name),price(price), stock(stock){}
    string getName(){
        return name;
    }
    double getPrice(){
        return price;
    }
    int getStock(){
        return stock;
    }
    void setPrice(double price){
        if(price<=0) throw InvalidPriceException("please put in a valid price");
        this->price=price;
    }
    void display() {
    cout << fixed << setprecision(2)
         << "Product: " << name 
         << " | Price: Rs." << price 
         << " | Stock: " << stock << endl;
}
};
void updateProductPrice(Product& prod){
    prod.display();
    double newPrice;
    while(true){
        try{
            newPrice=getNewPrice();
            break;
        }
        catch(InvalidPriceException e) {
            cout<<e.what();
        }
    }
    
    double currentPrice = prod.getPrice();  
    double percentChange = abs((newPrice - currentPrice) / currentPrice * 100);
    
    if (percentChange > 50) {
        throw InvalidPriceException("Error: Price change cannot exceed 50% in single update.");
    }
    prod.setPrice(newPrice);
    cout << "Price updated successfully!" << endl;
    
}
void displayInventory(Product arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << i + 1 << ". "; 
        arr[i].display();       
    }
}
double getNewPrice(){
    double price;
    cout<<"Enter the price";
    cin>>price;

    if(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        throw InvalidPriceException("Error: Invalid product selection.");
    }
    if(price < 0) {
        throw InvalidPriceException("Error: Price must be between 0 and 10,000 with exactly 2 decimal places.");
    }
    
    if(price > 10000) {
        throw InvalidPriceException("Error: Price must be between 0 and 10,000 with exactly 2 decimal places.");
    }
    
    
    if(floor(price * 100) != price * 100) {
        throw InvalidPriceException("Error: Price must be between 0 and 10,000 with exactly 2 decimal places.");    
    }
    cin.ignore(10000, '\n');
    return price;
} 
int main(){
    Product p1("laptop",100.50,1);
    Product p2("mobile",10.50,5);
    Product p3("speaker",50.20,10);
    Product arr[] = {p1, p2, p3};
    int size = 3;
    displayInventory(arr, size);
    cout << "\n=== Product Inventory Management System ===\n\n";
    char continueUpdate = 'Y';
    do 
    {
        try {
            displayInventory(arr);
            int i;
            cout<<"choose product, return the index value";
            cin>>i;
            if(cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                throw InvalidPriceException("Error: Invalid input - please enter a number.");
            }

            if(i < 0 || i >= size) {  
                throw InvalidPriceException("Error: Please enter a valid product number (1-" + to_string(size) + ").");
            }
            updateProductPrice(arr[i]);
            cout<<"would you like to continue say 'Y'/'y' to continue";
            cin>>continueUpdate;
            

        } 
        catch (const InvalidPriceException& e) {
            cout<<e.what();
        }
    } while (continueUpdate == 'y' || continueUpdate == 'Y');

}