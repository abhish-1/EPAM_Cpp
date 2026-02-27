// Write a C++ program with following instructions
// Create the following custom exception classes that inherit from appropriate standard exceptions:
// Stage 1: Custom Exception Classes
// InsufficientFundsException (inherits from std::runtime_error)
// Constructor: InsufficientFundsException(const std::string& account, double balance, double amount) : std::runtime_error("Insufficient funds"), accountNumber(account),currentBalance(balance), requestedAmount(amount)
// Properties: account number, current balance, requested amount
// Override what() method to provide detailed message
// InvalidAmountException (inherits from std::invalid_argument)
// Constructor: InvalidAmountException(double amount, const std::string& operation): std::invalid_argument("Invalid amount"), amount(amount), operation(operation)
// Properties: invalid amount, operation name
// Override what() method
// AccountNotFoundException (inherits from std::out_of_range)
// Constructor: AccountNotFoundException(const std::string& accountNumber) : std::out_of_range("Account not found"), accountNumber(accountNumber)
// Properties: account number that wasn't found
// Override what() method
// TransactionLimitExceededException (inherits from std::logic_error)
// Constructor: TransactionLimitExceededException(double amount, double limit): std::logic_error("Transaction limit exceeded"), amount(amount), limit(limit)
// Properties: attempted amount, daily limit
// Override what() method
// BankSystemException (inherits from std::runtime_error)
// Constructor: BankSystemException(const std::string& component, const std::string& error): std::runtime_error("Bank system error"), component(component), error(error)
// Properties: component name, error description
// Override what() method
// Stage 2: BankAccount Class
// Implement a BankAccount class with:
// Private:
// Properties:
// account number (std::string),
// holder name (std::string),
// balance (std::string),
// daily withdrawal limit (std::string),
// daily withdrawn amount (std::string)
// Methods: Method "void validateAmount(double amount, const std::string& operation) const" validates the amount for each of the Operations like (Deposit, Withdraw, transferTo)
// If amount is less than zero, throw InvalidAmountException.
// If amount is invalid, throw invalid_argument if (std::isnan(amount) || std::isinf(amount))
// Public:
// Constructor: validates initial balance and account details.
// If initial balane is less than zero, throw InvalidAmountException
// If Account Number/Account Name is empty, throw invalid_argument
// Methods:
// deposit(double amount):
// Validates amount by calling validateAmount (validateAmount(amount, "deposit");)
// Handles large deposits. If the deposit amount is more than Rs. 10,000,00, throw BankSystemException
// Update the latest balance with amount.
// withdraw(double amount): checks funds, daily limits, large withdrawals
// Validates amount by calling validateAmount (validateAmount(amount, "withdraw");)
// If the withdraw amount is more than Rs balance, throw InsufficientFundsException
// If dailyWithdrawn + amount > dailyWithdrawalLimit, throw TransactionLimitExceededException
// If amount > 100000, throw BankSystemException with component as "Fraud Detection".
// Update the balnce by deducting the amount.
// Also, increase the dailyWithdrawn by amoun
// transferTo(BankAccount& recipient, double amount): validates transfer
// Validates amount by calling validateAmount validateAmount(amount, "transfer")
// For selfTransfer, throw logic_error
// If amount to transfer is more than balance amount, throw InsufficientFundsException.
// Withdraw the amount.
// Deposit the amount withdran to the recipient account.
// Getters
// std::string getAccountNumber() const { return accountNumber; }
// std::string getHolderName() const { return holderName; }
// double getBalance() const { return balance; }
// double getDailyWithdrawalLimit() const { return dailyWithdrawalLimit; }
// double getDailyWithdrawn() const { return dailyWithdrawn; }
// printAccountInfo: Prints Account number, name, Balnce, Daily withdrawal limit, Already Withdrawn amount AND Available withdrawable amout per the day.
// Business Rules:
// Daily withdrawal limit: Rs. 50000
// Large deposit (>10,00,000) requires verification
// Large withdrawal (>1,00,000) triggers fraud detection
// Amounts must be positive and valid numbers
// Stage 3: Comprehensive Exception Handling
// Write main function that demonstrates ALL exception scenarios in this exact order:
// Successful operations (deposit, withdraw, transfer)
// Duplicate account creation (logic_error)
// Insufficient funds (InsufficientFundsException)
// Invalid amount (InvalidAmountException)
// Account not found (AccountNotFoundException)
// Transaction limit exceeded (TransactionLimitExceededException)
// System errors (BankSystemException for large transactions)
// Generic unknown exception (catch-all scenario)
// Stage 4: Implement catch blocks in PRECISE ORDER:
// catch (const InsufficientFundsException& e)
// catch (const InvalidAmountException& e)
// catch (const AccountNotFoundException& e)
// catch (const TransactionLimitExceededException& e)
// catch (const BankSystemException& e)
// catch (const std::out_of_range& e)
// catch (const std::invalid_argument& e)
// catch (const std::logic_error& e)
// catch (const std::runtime_error& e)
// catch (const std::exception& e)
// catch (...) // Catch-all last

#include<iostream>
#include<string>
#include<stdexcept>
#include<sstream>
#include<set>
#include<cmath>
using namespace std;

class InsufficientFundsException: public std::runtime_error{
    string accountNumber;      
    double currentBalance; 
    double requestedAmount;
    
public:
    InsufficientFundsException(const std::string& account, double balance, double amount) 
        : std::runtime_error("Insufficient funds"), 
          accountNumber(account), currentBalance(balance), requestedAmount(amount) {}
    
    const char* what() const noexcept override {
        std::stringstream ss;
        ss << "Insufficient funds for account number " << accountNumber 
           << " with balance " << currentBalance 
           << " requesting amount of " << requestedAmount;
        static std::string msg;
        msg = ss.str();
        return msg.c_str();
    }
};

class InvalidAmountException : public invalid_argument{
    double amount;
    const std::string operation;
    
public:
    InvalidAmountException(double amount, const std::string& operation)
        : std::invalid_argument("Invalid amount"), 
          amount(amount), operation(operation) {}
    
    const char* what() const noexcept override {
        std::stringstream ss;
        ss << "Invalid amount of " << amount << " under the operation of " << operation;
        static std::string msg;
        msg = ss.str();
        return msg.c_str();
    }
};

class AccountNotFoundException : public std::out_of_range{
    const std::string accountNumber;
    
public:
    AccountNotFoundException(const std::string& accountNumber) 
        : std::out_of_range("Account not found"), 
          accountNumber(accountNumber) {}
    
    const char* what() const noexcept override {
        std::stringstream ss;
        ss << "The account number " << accountNumber << " is not registered";
        static std::string msg;
        msg = ss.str();
        return msg.c_str();
    }
};

class TransactionLimitExceededException : public std::logic_error{
    double amount; 
    double limit;
    
public:
    TransactionLimitExceededException(double amount, double limit)
        : std::logic_error("Transaction limit exceeded"), 
          amount(amount), limit(limit) {}
    
    const char* what() const noexcept override {
        std::stringstream ss;
        ss << "Transaction of Rs. " << amount << " exceeds daily limit of Rs. " << limit;
        static std::string msg;
        msg = ss.str();
        return msg.c_str();
    }
};

class BankSystemException : public std::runtime_error{
    const std::string component; 
    const std::string error;
    
public:
    BankSystemException(const std::string& component, const std::string& error)
        : std::runtime_error("Bank system error"), 
          component(component), error(error) {}
    
    const char* what() const noexcept override {
        std::stringstream ss;
        ss << "Request under " << component << " cannot be processed due to " << error;
        static std::string msg;
        msg = ss.str();
        return msg.c_str();
    }
};

set<string> s;

class BankAccount{
    std::string accountNumber; 
    std::string holderName;
    double balance;
    double dailyWithdrawalLimit;
    double dailyWithdrawnAmount;
    
    void validateAmount(double amount, const std::string& operation) const {
        if(amount < 0){
            throw InvalidAmountException(amount, operation);
        }
        if (std::isnan(amount) || std::isinf(amount)){
            throw invalid_argument("the amount must be in numbers");
        }
    }
    
public:
    BankAccount(std::string accountNumber, std::string holderName, double balance, 
                double dailyWithdrawalLimit, double dailyWithdrawnAmount){
        if(s.find(accountNumber) != s.end()) 
            throw BankSystemException("account creation", "duplicate account");
        s.insert(accountNumber);
        
        this->accountNumber = accountNumber;
        this->holderName = holderName;
        this->balance = balance;
        this->dailyWithdrawalLimit = dailyWithdrawalLimit;
        this->dailyWithdrawnAmount = dailyWithdrawnAmount;
        
        validateAmount(balance, "Account creation");
        
        if(accountNumber == "" || holderName == "" ){
            throw invalid_argument("please enter a valid accountNumber and holderName");
        }
    }
    
    void deposit(double amount){
        validateAmount(amount, "deposit");
        if(amount > 1000000) 
            throw BankSystemException("deposit", "Large deposit requires verification");
        this->balance += amount;
    }
    
    void withdraw(double amount){ 
        validateAmount(amount, "withdraw");
        if(amount > this->balance) 
            throw InsufficientFundsException(accountNumber, this->balance, amount);
        if(dailyWithdrawalLimit == 0) 
            throw TransactionLimitExceededException(amount, dailyWithdrawalLimit);  
        if (dailyWithdrawnAmount + amount > dailyWithdrawalLimit) 
            throw TransactionLimitExceededException(amount, dailyWithdrawalLimit);  
        if (amount > 100000) 
            throw BankSystemException("withdraw", "Fraud Detection");
        
        this->balance -= amount;
        this->dailyWithdrawnAmount += amount;
    }
    
    void transferTo(BankAccount& recipient, double amount){
        validateAmount(amount, "transfer");
        if(recipient.accountNumber == accountNumber) 
            throw std::logic_error("enter recipient's account number");
        if (amount > this->balance) 
            throw InsufficientFundsException(recipient.accountNumber, this->balance, amount);
        
        this->balance -= amount;
        recipient.deposit(amount);
    }

    std::string getAccountNumber() const { return accountNumber; }
    std::string getHolderName() const { return holderName; }
    double getBalance() const { return balance; }
    double getDailyWithdrawalLimit() const { return dailyWithdrawalLimit; }
    double getDailyWithdrawn() const { return dailyWithdrawnAmount; } 
    
    void printAccountInfo(){
        std::cout << "here is your account information" << std::endl;
        std::cout << "Account Number : " << accountNumber << std::endl;
        std::cout << "Account holder name " << holderName << std::endl;
        std::cout << "The daily Withdrawal Limit is " << dailyWithdrawalLimit << std::endl;
        std::cout << "todays's withdrawn amount is " << dailyWithdrawnAmount << std::endl;
        std::cout << "amount you can debit today " << dailyWithdrawalLimit - dailyWithdrawnAmount << std::endl;
    } 
};

BankAccount* findAccount(const string& accNum) {
    throw AccountNotFoundException(accNum);
    return nullptr;
}

int main(){
    BankAccount acc1("ACC1001","Abhishek",10000,50000,0);
    BankAccount acc2("ACC1002","Abhi",10000,50000,0);
    
    // Successful operations
    try {
        acc1.deposit(2500);           
        acc1.withdraw(1500);           
        acc1.transferTo(acc2,2000);
        cout << "✓ Success" << endl;
    } catch (const exception& e) {
        cout << "Unexpected: " << e.what() << endl;
    }
    
    // Duplicate account creation
    try {
        BankAccount acc3("ACC1001","Duplicate",5000,50000,0);
    } catch (const BankSystemException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    
    // Negative-initial balance
    try {
        BankAccount accNegative("ACC999","Negative",-5000,50000,0);
    } catch (const InvalidAmountException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    
    // Insufficient funds
    try {
        acc1.withdraw(50000);
    } catch (const InsufficientFundsException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    
    // Invalid amount (negative)
    try {
        acc1.deposit(-500);
    } catch (const InvalidAmountException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    
    // Invalid amount (NaN)
    try {
        acc1.withdraw(NAN);
    } catch (const invalid_argument& e) {
        cout << "Caught: " << e.what() << endl;
    }
    
    // Account not found
    try {
        BankAccount* notFound = findAccount("NONEXISTENT");
    } catch (const AccountNotFoundException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    
    // Transaction limit exceeded
    try {
        BankAccount accLimit("ACC100","Limit",50000,5000,0);
        accLimit.withdraw(3000);
        accLimit.withdraw(2500);
    } catch (const TransactionLimitExceededException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    
    // Large deposit
    try {
        acc1.deposit(2000000);
    } catch (const BankSystemException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    
    // Large withdrawal
    try {
        acc1.withdraw(150000);
    } catch (const BankSystemException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    
    // Generic unknown
    try {
        throw 42;
    } catch (...) {
        cout << "Caught unknown exception" << endl;
    }
    
    return 0;
}