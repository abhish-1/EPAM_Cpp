// Create a class called FileHandler that simulates opening and closing a file.
// The constructor should print "File opened."
// The destructor should print "File closed."
// Add a method void write(const string& message) that prints "Writing: ".
// Write a function unique_ptr createFileHandler() that creates and returns a std::unique_ptr.
// Write a function void processFileHandler(std::unique_ptr handler) that takes ownership of the FileHandler pointer, writes a message using the write method, and then lets the pointer go out of scope (so the destructor is called).
// In your main() function:
// Call createFileHandler() to get a std::unique_ptr.
// Use std::move to transfer ownership of the pointer to processFileHandler.
// After the transfer, try to use the original pointer (e.g., call write again) and observe what happens (this should result in a runtime error or no operation, depending on your implementation).
// Add comments explaining each step, especially where ownership is transferred.
#include<iostream>
#include <string>  
#include<fstream>
#include<memory>
using namespace std;
class FileHandler{
    fstream file;
    public:
    FileHandler(){
        file.open("filename.txt");
        cout<<"File opened "<<endl;
    }
    ~FileHandler(){
        file.close();
        cout<<"File closed. "<<endl;
    }
    void write(const std::string& message){
    if (!file.is_open()) {
        std::cout << "Error opening file.\n";
        return;
    }
    cout << "Writing: " << message << endl;  // Print the message!
    }   
};
unique_ptr<FileHandler> createFileHandler(){
    unique_ptr<FileHandler> ptr = make_unique<FileHandler>();
    return ptr;
}
void processFileHandler(unique_ptr<FileHandler> handler) {
    handler->write("hello");
}
int main(){
    unique_ptr<FileHandler> ptr = createFileHandler();
    // Transfer ownership to processFileHandler using std::move
processFileHandler(move(ptr));

// After move, ptr is now nullptr and should not be used
if (ptr == nullptr) {
    cout << "ptr is now nullptr after move" << endl;
}

}