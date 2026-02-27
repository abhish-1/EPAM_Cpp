// Task: Your task is to implement a BankAccount class and demonstrate its behavior, paying close attention to different exception safety guarantees.
// Part 1: BankAccount Class Implementation
// Create a C++ class named BankAccount with the following specifications:
// Private Member Variables:
// std::string owner: To store the name of the account holder.
// int accountNumber: A unique identifier for the account.
// double balance: The current monetary balance of the account.
// Public Constructor:
// A constructor that takes owner (const std::string&), accountNumber (int), and initialBalance (double) as arguments to initialize the account. BankAccount(const std::string& owner, int accountNumber, double initialBalance) : owner(owner), accountNumber(accountNumber), balance(initialBalance) {}
// Public Member Functions:
// void deposit(double amount):
// Requirement: Strong Exception Safety Guarantee. If an exception is thrown during this operation, the state of the BankAccount object (specifically its balance) must remain entirely unchanged as if the operation never started.
// Error Handling:
// Throw std::invalid_argument if the amount is negative. if (amount < 0) { throw std::invalid_argument("Deposit amount cannot be negative."); }
// void withdraw(double amount):
// Requirement: Basic Exception Safety Guarantee. If an exception is thrown during this operation, the BankAccount object must remain in a valid, usable state, though its exact state (e.g., balance) may have changed. No resources should be leaked.
// Error Handling:
// Throw std::invalid_argument if the amount is negative.
// Throw std::runtime_error if the amount exceeds the current balance (insufficient funds).
// bool transferTo(BankAccount& targetAccount, double amount) noexcept:
// Requirement: No-throw Guarantee. This method must never throw any exceptions. All error conditions must be handled internally, and the method should indicate success or failure through its return value.
// Return Value: Return true if the transfer is successful, false otherwise.
// Error Handling (Internal):

// If amount is negative or if amount exceeds the current balance of the source account, the transfer should fail (return false).
// Assume that the targetAccount is always valid and targetAccount.balance cannot overflow with amount.
// double getBalance() const: A constant member function that returns the current balance
// void print() const: A constant member function that prints the account owner, account number, and balance to std::cout.
// Part 2: main Function Demonstration
// In your main function, demonstrate the functionality and exception safety of your BankAccount class:
// Create at least two BankAccount objects with different owners and initial balances. BankAccount alice("Alice", 1001, 500.0); BankAccount bob("Bob", 1002, 300.0);
// Test deposit:

// Perform a valid deposit operation. Print the account state.
// Attempt an invalid deposit (e.g., negative amount). Wrap this call in a try-catch block to catch the expected exception. Print the account state after the catch block to verify the Strong Guarantee (balance should be unchanged from before the failed deposit attempt).
// try { alice.deposit(200.0); alice.print(); alice.deposit(-50.0); // Should throw } catch (const std::exception& e) { std::cout << "Deposit error: " << e.what() << std::endl; } alice.print();
// Test withdraw:
// Perform a valid withdrawal operation. Print the account state.
// Attempt an invalid withdrawal (e.g., insufficient funds). Wrap this call in a try-catch block. Print the account state after the catch block to observe the state after an exception under Basic Guarantee.
// Test transferTo:
// Perform a valid transfer between your two accounts. Print the state of both accounts and the boolean success indicator.
// Attempt an invalid transfer (e.g., insufficient funds from the source account or negative amount). Print the state of both accounts and the boolean success indicator to confirm the No-throw Guarantee's behavior.


#include<iostream>
using namespace std;
class BankAccount{
    string owner;
    int accountNumber;
    double balance;
    
    public:
    BankAccount(const string& owner,int accountNumber,double initialBalance) : owner(owner), accountNumber(accountNumber), balance(initialBalance) {}

    void deposit(double amount){
        if(amount<0) throw std::invalid_argument("Deposit amount cannot be negative.");
        balance += amount;
    }
    void withdraw(double amount){
        if(amount<0) throw invalid_argument("Amount has to be positive");
        if(amount>balance) throw runtime_error("Insufficient funds");
        balance -= amount;
    }
    bool transferTo(BankAccount& targetAccount, double amount) noexcept{
        if(amount<0 ||amount>balance) return false;
        targetAccount.balance+=amount;
        balance-=amount;
    }
    double getBalance() const{
        return balance;
    }
    void print() const{
        cout<<"here is the data about the user"<<endl;
        cout<<"The owner of account is "<<owner<<endl;
        cout<<"the balance is "<<balance<<endl;

    }
};
int main(){
    BankAccount alice("Alice", 1001, 500.0);
    BankAccount bob("Bob", 1002, 300.0);
    
    alice.print();
    bob.print();

    alice.deposit(200.0);
    alice.print();

    try {
        alice.deposit(-50.0);
    } catch (const std::exception& e) {
        cout << "Deposit error: " << e.what() << endl;
    }
    alice.print(); 
    bob.withdraw(100.0);
    bob.print();
 
    try {
        bob.withdraw(500.0);
    } catch (const std::exception& e) {
        cout << "Withdraw error: " << e.what() << endl;
    }
    bob.print(); 
    bool success = alice.transferTo(bob, 100.0);
    cout << "Transfer " << (success ? "SUCCESS" : "FAILED") << endl;
    alice.print();
    bob.print();
    
    success = bob.transferTo(alice, 1000.0);
    cout << "Transfer " << (success ? "SUCCESS" : "FAILED") << endl;
    alice.print();
    bob.print();
    
    return 0;
}