#include <vector>
#include <iostream>


int main() {

    std::vector<int*> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(new int(i * 10));
    }

    return 0;
}
