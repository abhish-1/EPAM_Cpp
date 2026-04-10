#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<string>
using namespace std;

struct Student {
    int id;
    std::string name;
    bool active;
    double grade;
    Student() {} 
     
    Student(int i, std::string n, bool a, double g) : id(i), name(n), active(a), grade(g) {}
};
 
 class StudentRoster {
 private:
    std::vector<Student> studentsVector;      // Using vector
    std::list<Student> studentsList;          // Using list
    std::map<int, Student> studentsMap;       // Using map
     
 public:
     void removeFailedStudentsVector() {
         for (auto it = studentsVector.begin();it<studentsVector.end();) {
             if (it->grade < 60.0) {
                it = studentsVector.erase(it);
             }
             else{
                it++;
             }
        }
        
     }
     
     // BUG 2: Manual loop with wrong iterator handling
     void removeInactiveStudentsList() {
         auto it = studentsList.begin();
         while (it != studentsList.end()) {
             if (!it->active) {
                 it = studentsList.erase(it);
                 // BUG: Continues using invalid iterator
             }else{
             ++it;  // BUG: Double increment after erase
             }
         }
     }
     
     // BUG 3: Map erase with potential issues
     void removeLowGradesMap(double threshold) {
         for (auto it = studentsMap.begin(); it != studentsMap.end(); ) {
             if (it->second.grade < threshold) {
                 // BUG: Invalidates current iterator
                it = studentsMap.erase(it);
             }
             else {it++;}
         }
     }
     
     // BUG 4: Trying to erase while iterating incorrectly
     void cleanupVector() {
         for (auto it = studentsVector.begin(); it< studentsVector.end();) {
             if (it->grade < 60.0 || it->active == false) {
                 // BUG: Index invalidation
                 it = studentsVector.erase(it);
                 // BUG: Skips next element
             }
             else{
                 ++it;
             }
         }
     }
     
     // Helper to add students
     void addStudent(int id, std::string name, bool active, double grade) {
         Student s(id, name, active, grade);
         studentsVector.push_back(s);
         studentsList.push_back(s);
         studentsMap[id] = s;
     }
     
     // Print all students
     void printRoster() {
         std::cout << "Vector (" << studentsVector.size() << "): ";
         for (const auto& s : studentsVector) 
             std::cout << s.name << "(" << s.grade << ") ";
         
         std::cout << "\nList (" << studentsList.size() << "): ";
         for (const auto& s : studentsList) 
             std::cout << s.name << "(" << s.grade << ") ";
         
         std::cout << "\nMap (" << studentsMap.size() << "): ";
         for (const auto& [id, s] : studentsMap) 
             std::cout << s.name << "(" << s.grade << ") ";
         
         std::cout << "\n---\n";
     }
 };
 // ========== YOUR REFACTORING TARGETS ==========
 
 int main() {
     StudentRoster roster;
     
     // Test data
     roster.addStudent(1, "Alice", true, 95.5);
     roster.addStudent(2, "Bob", false, 45.0);     // Inactive, failing
     roster.addStudent(3, "Charlie", true, 58.5);   // Failing
     roster.addStudent(4, "Diana", true, 88.0);
     roster.addStudent(5, "Eve", false, 30.0);      // Inactive, failing
     
     std::cout << "Initial roster:\n";
     roster.printRoster();
     
     // These calls have iterator invalidation bugs!
     // Your task: Refactor these methods
     roster.removeFailedStudentsVector();   // Remove grade < 60
     roster.removeInactiveStudentsList();   // Remove inactive
     roster.removeLowGradesMap(50.0);       // Remove grade < 50
     roster.cleanupVector();                // Complex cleanup
     
     std::cout << "\nAfter removals (should be bug-free):\n";
     roster.printRoster();
     
     return 0;
 }
