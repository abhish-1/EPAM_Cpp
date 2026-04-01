// Declare an empty std::vector to store integer grades.
// Check and print if the vector is empty.
// Adding Grades:

// Add at least 6 initial grades (e.g., 80, 90, 75, 98, 89) to the vector using push_back().
// Print all grades using a range-based for loop.
// Print the current size of the vector.
// Accessing & Modifying Grades:

// Print the first grade using front().
// Print the last grade using back().
// Access and print the grade at index 2 using both operator[] and at().
// Modify the grade at index 2 to a new value (e.g., 80). Print the modified grade.
// Demonstrate at()'s bounds checking by attempting to access an invalid index within a try-catch block.
// Inserting Grades:

// Insert a new grade (e.g., 100) at the beginning of the vector.
// Insert another new grade (e.g., 75) at a specific position (e.g., before the last element).
// Print all grades and the new size.
// Removing Grades:

// Remove the last grade using pop_back().
// Remove the grade at a specific index (e.g., the second element) using erase().
// Print all grades and the new size.
// Clearing:

// Clear all grades from the vector using clear().
// Print the size and check if the vector is empty again.

#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    cout<<v.size()<<endl; //0
    v.push_back(80);
    v.push_back(90);
    v.push_back(85);  
    v.push_back(75);
    v.push_back(98);
    v.push_back(89);
    for(auto it:v){
        cout<<it<<endl;
    }
    cout<<v.size()<<endl;

    cout<<v.front()<<endl;

    cout<<v.back()<<endl;
    cout<<v[2]<<endl;
    cout<<v.at(2)<<endl;

    v[2]=80;
    cout<<v[2];
    try {
    cout << v.at(1000) << endl;
} catch (const std::out_of_range& e) {
    cout << "Error: " << e.what() << endl;
}
    v.insert(v.begin(), 100);        // Instead of emplace
v.insert(v.end() - 1, 75);
    for(auto it:v){
        cout<<it<<endl;
    }
    cout<<v.size()<<endl;
    v.pop_back();
    v.erase(v.begin()+2);
    for(auto it:v){
        cout<<it<<endl;
    }

    v.clear();
    cout << "Vector is empty: " << (v.empty() ? "true" : "false") << endl;

}
