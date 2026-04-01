// Setup:
// Create a C++ program that includes the necessary headers (, , ).
// Define a global constant for the cache capacity (const int CACHE_CAPACITY = 6;).
// Inside the main, initialize a std::list to represent the cache ( list<int> cache; // The LRU cache)
// Cache Operations:

// Implement a function to access an element(void accessCache(list<int>& cache, int value)):
// If the element is already in the cache, move it to the front (most recently used).
// If the element is not in the cache, Add it to the front. cache.erase(it); // First remove from current position cache.push_front(value); // later, add to front
// If the cache exceeds its capacity, remove the least recently used element from the back.
// User Interaction (Inside Main):

// Prompt the user to enter a sequence of integers to access (simulate cache requests).
// After each access, display the current state of the cache (from most to least recently used).
// while (true) { cout << "Access value: "; cin >> value; if (value == -1) break; // Stop input accessCache(cache, value); printCache(cache); }

#include<iostream>
#include<string>
#include<list>
using namespace std;
const int CACHE_CAPACITY = 6;
void printCache(list<int> cache){
    for(auto ptr= cache.begin();ptr!=cache.end();ptr++){
        cout<<*ptr<<endl;
    }
}
void accessCache(list<int>& cache, int value){
    auto it = cache.end();
    for(auto ptr= cache.begin();ptr!=cache.end();ptr++){
        if(*ptr == value){
            it = ptr;
            break;
        }
    }
    if(it == cache.end()){
        if(cache.size()==CACHE_CAPACITY){
            cache.pop_back();
        }
        cache.push_front(value);
    }
    else{
        cache.erase(it);
        cache.push_front(value);
    }

}
int main(){
    int value;
    list<int> cache;
    while (true) {
        cout << "Access value: "; 
        cin >> value; 
        if (value == -1) break;
        accessCache(cache, value); 
        printCache(cache);
    
    }

}
