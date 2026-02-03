//Creates a BankAccount class with private members: accountNumber (int), balance (double) 
// Implements public functions: deposit(double amount), withdraw(double amount), 
// and getBalance() Ensures that withdraw() validates funds, preventing withdrawal that 
// would overdraw the account Demonstrates that accountNumber and balance cannot be accessed
// directly from outside the class

#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(int accNum, double initialBalance )
        : accountNumber(accNum), balance(initialBalance) {
    }

    // Deposit 
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    // Withdraw 
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
        else {
            cout << "Insufficient funds or invalid amount, absolute poverty. I feel sorry for you";
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount acc(12345, 1000);  
    acc.deposit(500);
    cout << "Balance after deposit: " << acc.getBalance() << endl;

    acc.withdraw(200);
    cout << "Balance after withdrawal: " << acc.getBalance() << endl;

    acc.withdraw(2000);  // Attempt to overdraw
    cout << "Balance after invalid withdrawal: " << acc.getBalance() << endl;

    //acc.balance = 5000;        // Error: balance is private
    // cout << acc.accountNumber; // Error: accountNumber is private

    cout << " ------------------------------------------------- " << endl;

    return 0;
}

//Below is the version where you dnot actually create a constructor and teh default constructor with absolutely garbage balues work.

//#include <iostream>
//using namespace std;
//
//class BankAccount {
//private:
//    int accountNumber;
//    double balance;
//
//public:
//    
//
//    // Deposit 
//    void deposit(double amount) {
//        if (amount > 0)
//            balance += amount;
//    }
//
//    // Withdraw 
//    void withdraw(double amount) {
//        if (amount > 0 && amount <= balance) {
//            balance -= amount;
//        }
//        else {
//            cout << "Insufficient funds or invalid amount, absolute poverty. I feel sorry for you";
//        }
//    }
//
//    double getBalance() const {
//        return balance;
//    }
//};
//
//int main() {
//    BankAccount acc;
//    acc.deposit(500);
//    cout << "Balance after deposit: " << acc.getBalance() << endl;
//
//    acc.withdraw(200);
//    cout << "Balance after withdrawal: " << acc.getBalance() << endl;
//
//    acc.withdraw(2000);  // Attempt to overdraw
//    cout << "Balance after invalid withdrawal: " << acc.getBalance() << endl;
//
//    //acc.balance = 5000;        // Error: balance is private
//    // cout << acc.accountNumber; // Error: accountNumber is private
//
//    cout << " ------------------------------------------------- " << endl;
//
//    return 0;
//}
