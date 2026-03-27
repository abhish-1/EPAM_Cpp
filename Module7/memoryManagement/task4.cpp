// Define a Resource Class:
// Create a simple C++ class named LogMessage.
// It should have a std::string member to store the message content (e.g., std::string message_content;).
// Implement a constructor that takes a std::string and initializes message_content. Inside the constructor, print a message indicating the object has been created (e.g., std::cout << "LogMessage '" << message_content << "' created. Address: " << this << std::endl;).
// Implement a destructor that prints a message indicating the object has been destroyed (e.g., std::cout << "LogMessage '" << message_content << "' destroyed. Address: " << this << std::endl;).
// Add a simple public method, e.g., void printContent(), that just prints the message_content.
// Simulate an External System (Legacy API):
// Create a global or static function named void handleLegacyLog(LogMessage* rawMessage).
// This function should take a raw pointer to a LogMessage object.
// Inside this function:
// First, add a check: if (rawMessage == nullptr) { std::cout << "Legacy system received a nullptr log.\n"; return; }.
// Then, print a message indicating that the "Legacy system is now handling log: [Content of message]" using rawMessage->printContent().
// Crucially, within this function, delete rawMessage;. This simulates the external system taking full ownership and being responsible for cleaning up the memory.
// Finally, print a message indicating the legacy system has finished processing and deleting the message.
// Implement main for Ownership Release:
// Inside your main function,
// Create a std::unique_ptr named myLog. Initialize it with a dynamically allocated LogMessage using std::make_unique (e.g., std::make_unique("System Startup Event")).
// Print a message confirming the unique_ptr has been created and its initial state.
// Call myLog->printContent() to show it's initially managed by the unique_ptr.
// Call myLog.release() and store its return value (a raw LogMessage*) in a variable, e.g., LogMessage* handedOverLog = myLog.release();.
// Print a message indicating that myLog has released ownership.
// Pass handedOverLog to your handleLegacyLog function.

// After the call to handleLegacyLog, add a check: if (!myLog) { std::cout << "myLog unique_ptr is now empty (nullptr) after release().\n"; } else { std::cout << "Error: myLog unique_ptr is NOT empty after release()!\n"; }. This explicitly demonstrates that the unique_ptr no longer manages the resource.
// Observe the console output carefully to trace the object's creation and destruction. Pay attention to which component (your main function or handleLegacyLog) triggers the destructor.
// Create a std::unique_ptr to manage this SensorReport object:
// Use std::make_unique() to create a unique_ptr that points to an instance of your SensorReport class.
// Pass the rawSensorValue and sensorIdentifier to std::make_unique. These arguments will be forwarded to your SensorReport's constructor.
// Assign the result to a std::unique_ptr variable. A good name might be criticalReportPtr. std::unique_ptr<SensorReport> criticalReportPtr = std::make_unique<SensorReport>(rawSensorValue, sensorIdentifier);
// Access and use the SensorReport object through the std::unique_ptr:
// To call member functions or access member variables of the SensorReport object that the unique_ptr manages, you use the -> operator (arrow operator), just like with raw pointers to objects.
// Call the displayDetails() method on your criticalReportPtr. std::cout << "\nProcessing critical sensor report:" << std::endl; criticalReportPtr->displayDetails();
// Understand and demonstrate unique ownership (conceptual):

// Try to make a copy of your criticalReportPtr (// std::unique_ptr<SensorReport> anotherReport = criticalReportPtr; // This line should cause a compile-time error!)
// Observe that your compiler will prevent this, reinforcing that std::unique_ptr enforces strict, unique ownership.
// Observe automatic memory deallocation (conceptual and demonstrable):
// Add a final print statement to acknowledge the program's completion.
// When your main function finishes, criticalReportPtr will go out of scope. At this point, the std::unique_ptr will automatically call delete on the SensorReport object it managed.
// Observe the "DESTROYED" message printed by your SensorReport's destructor in the console output. This is proof that the memory was automatically cleaned up.

#include<iostream>
#include<memory>
using namespace std;
class LogMessage{
    std::string message_content;
    public:
    LogMessage(std::string message_content):message_content(message_content) {
        std::cout << "LogMessage '" << message_content << "' created. Address: " << this << std::endl;
    }
    ~LogMessage(){
        std::cout << "LogMessage '" << message_content << "' destroyed. Address: " << this << std::endl;
    }
    void printContent(){
        cout<<message_content;
    }
};
void handleLegacyLog(LogMessage* rawMessage){
    if (rawMessage == nullptr) { 
        std::cout << "Legacy system received a nullptr log.\n"; 
        return; 
    }
    cout<<"Legacy system is now handling log: " <<endl;
     rawMessage->printContent();
    delete rawMessage;

}
int main(){
    unique_ptr<LogMessage> myLog = make_unique<LogMessage> ("System Startup Event");
    if(myLog){
        cout<<"Unique pointer has been created "<<endl;
        myLog->printContent();
    }
    cout<<endl<<endl;
    LogMessage* handedOverLog = myLog.release();
    cout<<"released"<<endl;
    handleLegacyLog(handedOverLog);
    if (!myLog) { std::cout << "myLog unique_ptr is now empty (nullptr) after release().\n"; } else { std::cout << "Error: myLog unique_ptr is NOT empty after release()!\n"; }

}