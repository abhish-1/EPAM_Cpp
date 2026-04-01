#include <iostream>
#include <list>
#include <iterator>
#include <stdexcept>

int main() {
    std::list<int> grades;
    
    if (grades.empty()) {
        std::cout << "List is empty\n";
    }
    
    grades.push_back(85);
    grades.push_back(90);
    grades.push_back(78);
    grades.push_back(92);
    grades.push_back(88);
    grades.push_back(76);
    
    std::cout << "All grades: ";
    for (int g : grades) {
        std::cout << g << " ";
    }
    std::cout << "\n";
    
    std::cout << "Size: " << grades.size() << "\n";
    
    std::cout << "First grade: " << grades.front() << "\n";
    std::cout << "Last grade: " << grades.back() << "\n";
    
    auto it = grades.begin();
    std::advance(it, 2);
    std::cout << "Grade at position 3: " << *it << "\n";
    
    *it = 99;
    std::cout << "Updated grade at position 3: " << *it << "\n";
    
    try {
        auto badIt = grades.begin();
        std::advance(badIt, 100);
        std::cout << *badIt << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    
    grades.push_front(95);
    
    auto lastIt = grades.end();
    std::advance(lastIt, -1);
    grades.insert(lastIt, 82);
    
    std::cout << "After insertions: ";
    for (int g : grades) {
        std::cout << g << " ";
    }
    std::cout << "\n";
    std::cout << "Size: " << grades.size() << "\n";
    
    grades.pop_back();
    
    auto secondIt = grades.begin();
    std::advance(secondIt, 1);
    grades.erase(secondIt);
    
    std::cout << "After removals: ";
    for (int g : grades) {
        std::cout << g << " ";
    }
    std::cout << "\n";
    std::cout << "Size: " << grades.size() << "\n";
    
    grades.clear();
    std::cout << "After clear - Size: " << grades.size() << "\n";
    
    if (grades.empty()) {
        std::cout << "List is empty\n";
    }
    
    return 0;
}