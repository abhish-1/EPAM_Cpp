// Task:
// Stage 1: Memory Tracking System
// 1.1 Create a MedicalMemoryTracker class:
// Implement static int members totalMemAllocated and totalMemDeallocated
// Create recordAllocation(static void recordAllocation(const char* medicalResource, int size)) method that:
// Adds to total allocations using totalMemAllocated
// Prints allocation message with memory allocated.
// Create recordDeallocation() method that:
// static void recordDeallocation(const char* medicalResource, int size)
// Adds to total deallocations using totalMemDeallocated
// Prints deallocation message
// Implement reportLeaks() that shows memory status and detects leaks
// If the difference between toal allocations and total deallocation is 0, then no memory leak.
// Add reset() method to clear tracking data
// reset both members to 0.
// 1.2 Initialize static members:
// Set totalAllocations and totalDeallocations to 0
// Stage 2: Medical Exception Classes (20 minutes)
// 2.1 Create custom medical exceptions:
// MedicalDeviceException inheriting from std::runtime_error
// PatientDataException inheriting from std::runtime_error
// Both should take string messages in constructors and pass the same string message to base class using constructor initialization list.
// Stage 3: PatientVitalMonitor Class (60 minutes)
// 3.1 Declare private members:
// heartRateData (int pointer) - for heart rate monitoring
// bloodPressureData (float pointer) - for BP monitoring
// deviceConnected (bool) - device status
// patientId (char array) - patient identifier
// 3.2 Implement private helper methods:
// connectToMedicalDevice() - simulates 50% failure rate throwing MedicalDeviceException
// calibrateSensors() - simulates 50% failure rate throwing MedicalDeviceException
// validatePatientData() - simulates 50% failure rate throwing PatientDataException
// analyzeCriticalTrend() - simulates 50% failure rate throwing PatientDataException
// Hint: To simu late 50% failure, inside the method simply write below code.
// if (rand() % 2 == 0) {
//         throw PatientDataException("E303: Corrupted vital signs detected!");
// }
// 
// 3.3 Implement Constructor (SCENARIO 1 - Partial Construction Leak):
// Initialize all pointers to nullptr and deviceConnected to false and Copy patient ID to patientId using initialization list.
// Allocate heartRateData buffer (36000 integers) - track with MedicalMemoryTracker
// Hint: MedicalMemoryTracker::recordAllocation("Heart Rate Buffer", 36000 * sizeof(int));
// Allocate bloodPressureData buffer (18000 floats) - track with MedicalMemoryTracker
// Hint: MedicalMemoryTracker::recordAllocation("Blood Pressure Buffer", 18000 * sizeof(float));
// Call connectToMedicalDevice() - THIS MIGHT THROW!
// Call calibrateSensors() - THIS MIGHT THROW!
// If exceptions thrown above, allocated buffers LEAK (destructor not called)
// 3.4 Implement Destructor:
// Print shutdown message
// Delete heartRateData if not null - track deallocation
// Hint: MedicalMemoryTracker::recordDeallocation("Heart Rate Buffer", 36000 * sizeof(int));
// Delete bloodPressureData if not null - track deallocation - Hint: MedicalMemoryTracker::recordDeallocation("Blood Pressure Buffer", 18000 * sizeof(float));
// NOTE: Destructor won't be called if constructor throws!
// 3.5 Implement monitorPatientVitals() (SCENARIO 2 - Mid-Processing Leak):
// Hint: void monitorPatientVitals(int durationMinutes)
// Validate duration is positive.
// `
// - if (durationMinutes <= 0) {
// -             throw std::invalid_argument("E001: Monitoring duration must be positive!")
// - }
// `
// Allocate ecgAnalysisBuffer (5000 floats) - track allocation
// Call validatePatientData() - THIS MIGHT THROW! (causes leak)
// Allocate criticalTrendBuffer (1000 integers) - track allocation
// Call analyzeCriticalTrend() - THIS MIGHT THROW! (causes multiple leaks)
// Simulate monitoring with loop
// Cleanup buffers at end - MIGHT NOT BE REACHED!
// ` delete[] ecgAnalysisBuffer;
// MedicalMemoryTracker::recordDeallocation("ECG Analysis Buffer", 5000 * sizeof(float));
// std::cout << " ECG analysis completed - buffer freed" << std::endl;`
// Similar clean-up for criticalTrendBuffer
// Stage 4: Main Function
// Print program description
// Seed random number generator (srand(static_cast<unsigned>(time(nullptr)));)
// Capture user input for the number attempts (typically 5 to 10)
// Reset memory tracker (MedicalMemoryTracker::reset();)
// Create a local variables emergencyMonitor (pointer of type PatientVitalMonitor) with default value as null ptr.
// Create another local bool variable setupSuccessful with default value false.
// Add try catch blocks inside a while loop with number of attempts given by the use above..
// First try-catch block:
// Create a dynamic object for PatientVitalMonitor (emergencyMonitor = new PatientVitalMonitor("EMERGENCY-001");)
// If creatio is setupSuccessful, update the setupSuccessful to true. and write a cout message.
// If any exception is thrown with in PatientVitalMonitor catch it inside the catch handelr which will accept the exception of type MedicalDeviceException.
// Hint:- catch (const MedicalDeviceException& e)
// Write a cout statement prinintg the type of exception using e.waht()
// If setup successful, attempt critical monitoring ( if (setupSuccessful && emergencyMonitor))
// Second try-catch block:
// Inside the second try block, monitor the patient vitals (emergencyMonitor->monitorPatientVitals(10))
// Inside the second catch handler catch any exception of type PatientDataException (catch (const PatientDataException& e))
// Finally clean-up (delete emergencyMonitor;)
// Report the memory leaks during all these attempts ( MedicalMemoryTracker::reportLeaks();)
// Related topics to explore:



#include<iostream>
#include<cstring>
#include<stdexcept>
#include<cstdlib> 
#include<ctime>
using namespace std;
class MedicalMemoryTracker{
    public:
    static int totalMemAllocated;
    static int totalMemDeallocated;
    static void recordAllocation(const char* medicalResource, int size){
        totalMemAllocated += size;
        cout << medicalResource << ": allocated " << size << " bytes" << endl; 
    }

    static void recordDeallocation(const char* medicalResource, int size){
        totalMemDeallocated += size;
        cout << medicalResource << ": deallocated " << size << " bytes" << endl; 
    }
    static void reportLeaks(){
        if(totalMemAllocated==totalMemDeallocated){
            cout << "No memory leaks detected!" << endl;
        }
        else{
            cout<<"There is a leak in memory of "<<abs(totalMemAllocated-totalMemDeallocated);
        } 
    }
    static void reset(){
        totalMemAllocated=0;
        totalMemDeallocated=0;
    }
};

int MedicalMemoryTracker::totalMemAllocated = 0;
int MedicalMemoryTracker::totalMemDeallocated = 0;

class MedicalDeviceException : public runtime_error{
    public:
    MedicalDeviceException(string msg):runtime_error(msg){}
};

class PatientDataException : public runtime_error{
    public:
    PatientDataException(string msg):runtime_error(msg){}
};

class PatientVitalMonitor{
    public:
    int* heartRateData;
    float* bloodPressureData;
    bool deviceConnected;
    char patientId[20];

    void connectToMedicalDevice(){
        if (rand() % 2 == 0) {
            throw MedicalDeviceException("E303: Corrupted vital signs detected!");
        }
    }
    void calibrateSensors(){
        if (rand() % 2 == 0) {
            throw MedicalDeviceException("E303: Corrupted vital signs detected!");
        }

    }
    void validatePatientData(){
        if (rand() % 2 == 0) {
            throw PatientDataException("E303: Corrupted vital signs detected!");
        }
    }
    void analyzeCriticalTrend(){
        if (rand() % 2 == 0) {
            throw PatientDataException("E303: Corrupted vital signs detected!");
        }
        
    }

    PatientVitalMonitor(const char* id) : heartRateData(nullptr), bloodPressureData(nullptr), deviceConnected(false) {
        strcpy(patientId, id);   //strcpy(destination, source)

        heartRateData= new int[36000];
        // The medical monitoring system needed large memory blocks (144KB for heart rate data) that exceed typical
        // stack limits, require runtime sizing, and must persist beyond function calls. Heap-allocated buffers give
        // explicit control over memory lifetime—crucial for demonstrating exception safety scenarios where 
        //constructors throw after partial allocation, causing memory leaks that wouldn't be possible with stack arrays.
        // The term "buffer" specifically indicates temporary storage for streaming data, which matches the continuous
        // patient monitoring use case.
        MedicalMemoryTracker::recordAllocation("Heart Rate Buffer", 36000 * sizeof(int));
        
        bloodPressureData = new float[18000];
        MedicalMemoryTracker::recordAllocation("Blood Pressure Buffer", 18000 * sizeof(float));

        connectToMedicalDevice();
        calibrateSensors();
    }

    ~PatientVitalMonitor() {
        cout << "Shutting down monitor for " << patientId << endl;
        if(heartRateData){
            delete[] heartRateData;
            MedicalMemoryTracker::recordDeallocation("Heart Rate Buffer", 36000 * sizeof(int));
        }
        if(bloodPressureData){
            delete[] bloodPressureData;
            MedicalMemoryTracker::recordDeallocation("Blood Pressure Buffer", 18000 * sizeof(float));
        }
    }
    void monitorPatientVitals(int durationMinutes){
        if (durationMinutes <= 0) {
            throw std::invalid_argument("E001: Monitoring duration must be positive!");
        }
        float* ecgAnalysisBuffer= new float[5000];
        MedicalMemoryTracker::recordAllocation("ECG analysis  Buffer", 5000 * sizeof(float));
        validatePatientData();

        int* criticalTrendBuffer = new int[1000];
        MedicalMemoryTracker::recordAllocation("critical Trend Buffer", 1000 * sizeof(int));
        analyzeCriticalTrend();

        delete[] ecgAnalysisBuffer;
        MedicalMemoryTracker::recordDeallocation("ECG Analysis Buffer", 5000 * sizeof(float));
        std::cout << " ECG analysis completed - buffer freed" << std::endl;

        delete[] criticalTrendBuffer;
        MedicalMemoryTracker::recordDeallocation("critical Trend Buffer", 1000 * sizeof(int));
        std::cout << " Critical Trend Buffer freed" << std::endl;
    }
};

int main(){
    cout<<"Welcome to all new main function"<<endl;
    srand(static_cast<unsigned>(time(nullptr)));

    int attempts;
    cout << "Enter number of monitoring attempts (5-10): ";
    cin >> attempts;

    MedicalMemoryTracker::reset();

    for(int attempt = 1; attempt <= attempts; attempt++) {
        PatientVitalMonitor* emergencyMonitor= nullptr;
        bool setupSuccessful = false;
        try{
            emergencyMonitor = new PatientVitalMonitor("EMERGENCY-001");
            setupSuccessful = true;
            cout<<"Creation is successful"<<endl;
        }
        catch(const MedicalDeviceException& e){
            cout<<e.what();
        }

        if (setupSuccessful && emergencyMonitor){
            try{
                emergencyMonitor->monitorPatientVitals(10);
            }
            catch (const PatientDataException& e){
                cout<<e.what()<<endl;
            }
        }
        delete emergencyMonitor;
    }
    
    MedicalMemoryTracker::reportLeaks();
}
