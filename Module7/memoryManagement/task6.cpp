// Open a File: Use FILE* file = fopen("log.txt", "w"); to open a file for writing.
// Create a Custom Deleter: Write a lambda or a functor that takes a FILE* and calls fclose on it.
// Wrap the File Pointer: Use std::unique_ptr<FILE, /custom deleter/> to manage the file pointer.
// std::unique_ptr<FILE, decltype(fileDeleter)> filePtr(file, fileDeleter);

// Write to the File: Use fprintf to write a simple log message, e.g., "Log started".

// fprintf(filePtr.get(), "Log started\n");

// Demonstrate Automatic Cleanup: Show that the file is closed automatically when the unique pointer goes out of scope (e.g., by printing a message in the custom deleter).

// Error Handling: Handle the case where the file fails to open (i.e., file == nullptr).

// Sample Output:

// If the file opens successfully, "Log started" is written to log.txt, and a message like "File closed" is printed to the console when the deleter runs.
// If the file fails to open, print an error message.

#include<cstdio>
#include<iostream>
#include<memory>
using namespace std;

struct FileCloser {
     void operator()(FILE* filePtr) const {
         if (filePtr) { 
            fclose(filePtr); 
            std::cout << "File closed by custom deleter.\n"; 
        }
    }  
};

auto fileDeleter = [](FILE* f) {
     if (f) {
         fclose(f);
        std::cout << "File closed by custom deleter.\n"; 
    } 
};

int main(){
    FILE* file = fopen("log.txt", "w");
    if(file == nullptr){
        cout << "Error: Failed to open file" << endl;
        return 1;
    }
    
    // Using struct deleter
    unique_ptr<FILE, FileCloser> ptr(file, FileCloser());
    
    // Option 2: Using lambda deleter (COMMENTED - using struct instead)
    // unique_ptr<FILE, decltype(fileDeleter)> ptr(file, fileDeleter);
    
    // Option 3: Using fclose directly (COMMENTED - using struct instead)
    // unique_ptr<FILE, decltype(&fclose)> ptr(file, &fclose);
    
    fprintf(ptr.get(), "Log started\n");
    cout << "Log written to file" << endl;
    
    return 0;
}