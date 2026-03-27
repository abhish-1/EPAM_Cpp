// Set up your basic C++ program structure. include for printing output, for std::unique_ptr, and for using std::string in your custom class.
// Define your custom SensorReport class:
// Create a class named SensorReport.
// Give it at least two member variables: an int for the value and a std::string for the sensorName.
// Implement a constructor that takes initial values for value and sensorName. Inside the constructor, print a message indicating that the object has been created (e.g., "SensorReport for X created.").
// Implement a simple public method, say displayDetails(), that prints the sensor's name and its current value.
// (Crucial for seeing object lifecycle) Implement a destructor ~SensorReport(). Inside the destructor, print a message indicating that the object is being destroyed (e.g., "SensorReport for X destroyed.").
// Simulate receiving a critical sensor report:
// Inside your main function, declare variables to hold the raw data for the report (e.g., int rawSensorValue = 75; and std::string sensorIdentifier = "Pressure_A01";). These will be used to initialize your SensorReport object.
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
#include <iostream>
#include <string>
#include <memory>
class SensorReport {
private:
    int value;
    std::string sensorName;

public:
    // Constructor
    SensorReport(int val, const std::string& name) : value(val), sensorName(name) {
        std::cout << "SensorReport for " << sensorName << " created." << std::endl;
    }
    
    // Display method
    void displayDetails() {
        std::cout << "Sensor: " << sensorName << ", Value: " << value << std::endl;
    }
    
    // Destructor
    ~SensorReport() {
        std::cout << "SensorReport for " << sensorName << " destroyed." << std::endl;
    }
};
int main(){
    int rawSensorValue = 75; 
    std::string sensorIdentifier = "Pressure_A01";
    unique_ptr<SensorReport> criticalReportPtr = make_unique<SensorReport>(rawSensorValue,sensorIdentifier);
    std::cout << "\nProcessing critical sensor report:" << std::endl; 
    criticalReportPtr->displayDetails();
    // std::unique_ptr<SensorReport> anotherReport = criticalReportPtr;
}