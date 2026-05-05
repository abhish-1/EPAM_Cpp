// Use std::vector<std::unique_ptr<int>> or std::vector<std::shared_ptr<int>>
// No need to manually delete objects
// Run the program under CRT (_CrtDumpMemoryLeaks(), Windows) or Valgrind (Linux/macOS) to confirm no memory leaks

#include <vector>
#include <memory>    
#include <iostream>

int main() {

    std::vector<std::unique_ptr<int>> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(std::make_unique<int>(i * 10));
    }
    return 0;
}
