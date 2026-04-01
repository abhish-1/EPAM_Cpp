#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int NUM_WORDS = 100000; 
const int NUM_LOOKUP_TESTS = 10000; 
const int NUM_NONEXISTENT_WORDS = 10000;

using WordVector = vector<string>;
using MilliSeconds = std::chrono::duration<double,std::milli>;

template <typename Func> 
double measureTime(const std::string& description, Func func) { 
    auto start = std::chrono::high_resolution_clock::now(); 
    func(); 
    auto end = std::chrono::high_resolution_clock::now(); 
    MilliSeconds duration_ms = end - start; std::cout << std::fixed << std::setprecision(3); 
    std::cout << " " << std::left << std::setw(35) << description + ":" << duration_ms.count() << " ms" << std::endl; 
    return duration_ms.count(); 
}

WordVector generateWords(int count, const std::string& prefix) { 
    WordVector words;
    words.reserve(count); 
    for (int i = 0; i < count; ++i) { 
        words.push_back(prefix + std::to_string(i)); 
    } 
    return words; 
}

template <typename MapType> 
void conditionallyReserve(MapType& map, size_t count) { 
    if constexpr (std::is_same_v<MapType, std::unordered_map<std::string, int>>) { 
        map.reserve(count);
        std::cout << " (Reserved " << count << " buckets for unordered_map)" << std::endl; 
    } 
}
int main(){
    

}