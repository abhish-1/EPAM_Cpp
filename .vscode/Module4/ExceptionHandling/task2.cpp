// Write a C++ program with following instructions
// Define Multiple Custom Exception Classes:
// Create two distinct C++ Classes: SystemError and NetworkError.
// Each should contain a const char* message member.
// Define a function named complexOperation().

// This function will simulate different error conditions based on a simple control mechanism.
// Hint: Use a static counter
// first time: Throw a SystemError object.
// The second time: Throw a NetworkError object.
// The third time: Throw an int literal (e.g., throw -1; for a generic computation error).
// The fourth time: Throw a const char* literal (e.g., throw "Very unexpected error!";).
// On subsequent calls (or as a default): Simply print "Operation completed successfully." and return.
// Implement main with Ordered catch Blocks:

// In your main function, call complexOperation() several times (at least four or five times).
// Wrap each call to complexOperation() inside its own try block.
// Immediately following each try block, implement the following sequence of catch handlers:
// A catch(NetworkError error) block. Print a message like "Network error caught: " followed by its message.
// A catch(SystemError error) block. Print a message like "System error caught: " followed by its message.
// A catch(int errorCode) block. Print a message like "Generic integer error caught: " followed by the error code.
// Finally, a catch(...) block. Print a generic "Unknown exception caught!" message.
// After each try-catch block, print "--- End of processing ---" to mark completion.
#include<iostream>
#include<stdexcept>
using namespace std;
class SystemError {
    const char* message;
public: 
    SystemError(const char* msg) : message(msg) {}  
    const char* what() const { return message; }  
};

class NetworkError {
    const char* message;
public:
    NetworkError(const char* msg) : message(msg) {}  
    const char* what() const { return message; }
};

void complexOperation(){
    
    static int counter=0;
    counter++;
    
    if(counter==1){
        throw SystemError ("se");
    }
    else if(counter==2){
        throw NetworkError ("ne");
    }
    else if(counter==3){
        throw (int) -1;
    }
    else if(counter==4){
        throw "Very unexpected error!";
    }
    else cout<<"Operation completed successfully.";
    return ;
}

int main(){
    try{
        complexOperation();
    }
    catch(const NetworkError& error){
        cout<<"Network error caught: "<<error.what();
    }
    catch(const SystemError& error){
        cout<<"SystemError error caught: "<<error.what();
    }
    catch(int errorCode){
        cout<<"Generic error caught: "<<errorCode;
    }
    catch(...){
        cout<<"generic error seen";
    }
    cout<<"--- End of processing ---"<<endl;
    
    try{
        complexOperation();
    }
    catch(const NetworkError& error){
        cout<<"Network error caught: "<<error.what();
    }
    catch(const SystemError& error){
        cout<<"SystemError error caught: "<<error.what();
    }
    catch(int errorCode){
        cout<<"Generic error caught: "<<errorCode;
    }
    catch(...){
        cout<<"generic error seen";
    }
    cout<<"--- End of processing ---"<<endl;

    try{
        complexOperation ();
    }
    catch(const NetworkError& error){
        cout<<"Network error caught: "<<error.what();
    }
    catch(const SystemError& error){
        cout<<"SystemError error caught: "<<error.what();
    }
    catch(int errorCode){
        cout<<"Generic error caught: "<<errorCode;
    }
    catch(...){
        cout<<"generic error seen";
    }
    cout<<"--- End of processing ---"<<endl;


    try{
        complexOperation ();
    }
    catch(const NetworkError& error){
        cout<<"Network error caught: "<<error.what();
    }
    catch(const SystemError& error){
        cout<<"SystemError error caught: "<<error.what();
    }
    catch(int errorCode){
        cout<<"Generic error caught: "<<errorCode;
    }
    catch(...){
        cout<<"generic error seen";
    }
    cout<<"--- End of processing ---"<<endl;


    try{
        complexOperation ();
    }
    catch(const NetworkError& error){
        cout<<"Network error caught: "<<error.what();
    }
    catch(const SystemError& error){
        cout<<"SystemError error caught: "<<error.what();
    }
    catch(int errorCode){
        cout<<"Generic error caught: "<<errorCode;
    }
    catch(...){
        cout<<"generic error seen";
    }
    cout<<"--- End of processing ---"<<endl;

    
}