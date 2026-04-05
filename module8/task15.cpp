// Create a struct or class named Patient.
// It should have the following three public member variables:
// std::string name: To store the patient's name (e.g., "Alice Smith").
// int severity: An integer representing the patient's medical severity. Use a scale where 1 is the most critical and 5 is the least critical.
// int arrivalTime: An integer representing the time of arrival (e.g., in minutes since the ER opened). A lower number means earlier arrival.
// Implement a Constructor:
// Add a public constructor to your Patient struct/class to easily initialize these members. For example: Patient(std::string n, int s, int t) : name(n), severity(s), arrivalTime(t) {}.
// Designing the Custom Comparator. This is the most critical part of the task. The std::priority_queue by default acts as a max-heap (meaning the "largest" element, as defined by operator< or a custom comparator, comes out first). We need to define "largest" according to our ER triage rules.
//  Create a Custom Comparator Struct:
// Define a struct named ComparePatients (or a similar descriptive name).
// This struct must overload the operator() as a const member function. This operator() will be called by std::priority_queue to determine the relative order of two patients.
// It will take two const Patient& arguments (let's call them p1 and p2).
// It should return true if p1 has a lower priority than p2 (meaning p2 should be considered "greater" or "higher priority" than p1, and thus p2 should come out of the queue first).
// Implement the Priority Rules:
// Primary Rule (Severity): Patients with a lower severity number have higher priority. (e.g., Severity 1 is more urgent than Severity 3).
// If p1's severity is greater than p2's severity, then p2 is more critical, so p1 has lower priority.
// Tie-breaking Rule (Arrival Time): If two patients have the same severity, the patient with the lower arrivalTime (meaning they arrived earlier) has higher priority.
// If p1's arrival time is greater than p2's arrival time, then p2 arrived earlier and is more critical, so p1 has lower priority.
// ` struct ComparePatients { // The operator() takes two Patient objects and returns true if p1 // has a LOWER priority than p2 (meaning p2 should come out first). bool operator()(const Patient& p1, const Patient& p2) const { // Primary Rule: Higher priority for lower severity number // If p1 is less severe (higher number) than p2, then p1 has lower priority. if (p1.severity > p2.severity) { return true; // p1 has lower priority than p2 } // If p1 is more severe (lower number) than p2, then p1 has higher priority. if (p1.severity < p2.severity) { return false; // p1 does NOT have lower priority than p2 (p1 is higher priority) }
//       // Tie-breaking Rule: If severities are equal, higher priority for earlier arrival time (lower number)
//       // If p1 arrived later (higher number) than p2, then p1 has lower priority.
//       if (p1.arrivalTime > p2.arrivalTime) {
//           return true; // p1 has lower priority than p2
//       }
//       // If p1 arrived earlier (lower number) than p2, then p1 has higher priority.
//       if (p1.arrivalTime < p2.arrivalTime) {
//           return false; // p1 does NOT have lower priority than p2 (p1 is higher priority)
//       }
//       // If both severity and arrival time are identical, their order doesn't strictly matter
//       // for priority, but we must return something. We can consider them equal priority.
//       return false; // Or true, it won't change the relative order of identical patients.
//   }
// }; `
//  Implementing the Triage System (in main function)
// Declare priority_queue:
// In your main function, declare an std::priority_queue to hold Patient objects.
// Remember to specify the custom comparator
// std::priority_queue<Patient, std::vector<Patient>, ComparePatients> erQueue;
// Note: std::vector is the default underlying container for std::priority_queue, but it's good practice to explicitly state it when providing a custom comparator.


#include<iostream>
#include<string>    
#include<queue>
using namespace std;

struct Patient{
    string name;
    int severity;
    int arrivalTime;
    Patient(std::string n, int s, int t) : name(n), severity(s), arrivalTime(t) {}
};

struct ComparePatients {
    bool operator()(const Patient& p1, const Patient& p2) const {
        if (p1.severity > p2.severity) {
            return true; 
        }
        
        if (p1.severity < p2.severity) {
            return false;  
        }
        
        if (p1.arrivalTime > p2.arrivalTime) {
            return true; 
        }
        
        return false;  
    }
};

int main(){
    priority_queue<Patient, vector<Patient>, ComparePatients> erQueue;
    
    erQueue.push(Patient("Alice", 3, 10));
    erQueue.push(Patient("Bob", 1, 5));
    erQueue.push(Patient("Charlie", 3, 8));
    erQueue.push(Patient("David", 2, 12));
    erQueue.push(Patient("Eve", 1, 7));
    erQueue.push(Patient("Frank", 5, 2));
    
    while (!erQueue.empty()) {
        Patient p = erQueue.top();
        cout << "Processing patient: " << p.name 
             << " Severity: " << p.severity 
             << " Arrived at: " << p.arrivalTime << endl;
        erQueue.pop();
    }
    
    return 0;
}