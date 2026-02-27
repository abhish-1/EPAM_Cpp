// Instructions:
// LogSession Class:
// Constructor: Prints "[LogSession ID] started."
// Destructor: Prints "[LogSession ID] ended."
// performDataValidation() function:
// Creates a LogSession object (ID 3).
// Simulates checking data.
// If a specific condition (e.g., data_value < 0) is met, it throw "Invalid Data";.
// Otherwise, prints "[LogSession ID] data validated successfully."
// processTransaction() function:
// Creates a LogSession object (ID 2).
// Calls performDataValidation() with various data values.
// Prints "[LogSession ID] transaction processed."
// startCriticalOperation() function:
// Creates a LogSession object (ID 1).
// Calls processTransaction().
// Prints "[LogSession ID] critical operation completed."

// main() function:
// Print a message "Starting main block."
// Calls startCriticalOperation() inside a try-catch block.
// Catches const char* exceptions and prints a message "Inside the main Catch handler".
// This demonstrates that even if performDataValidation() throws an exception, LogSession objects in processTransaction() and
// startCriticalOperation() will still be destructed in the correct order.

#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class LogSession{
    int ID ;
    public:
    LogSession(int ID){
        this->ID = ID;
        cout << "[LogSession " << this->ID << "] started." << endl;
    }

    ~LogSession(){
        cout << "[LogSession " << this->ID << "] ended." << endl;
    }
};

void performDataValidation(){
    LogSession s(3);
    int data_value=-1;
    if(data_value<0) throw "Invalid Data";
    cout << "[LogSession 3] data validated successfully." << endl;
}

void processTransaction(){
    LogSession s1(2);
    performDataValidation();
    cout << "[LogSession 2] transaction processed." << endl;
}

void startCriticalOperation(){
    LogSession s2(1);
    processTransaction();
    cout << "[LogSession 1] critical operation completed." << endl;
}

int main(){
    cout<<"Starting main block.";
    try{
        startCriticalOperation();
    }
    catch(const char* ex){
        cout<<"Inside the main Catch handler";
    }
    return 0;

}