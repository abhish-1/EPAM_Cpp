//Defines a Logger class with an std::ofstream member Implements a constructor that opens a file
// for appending logs Includes a log(const std::string&) method that prepends each message with a
// timestamp and writes it to the file Demonstrates usage by logging multiple messages and verifying
// output in the log file

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class Logger {
    string fileName;
public:
    Logger(const string& file) : fileName(file) {}

    void log(const string& message) {
        ofstream file(fileName, ios::app); 
        if (!file) {
            cerr << "Error opening file\n";
            return;
        }

        time_t now = time(0);
        char* dt = ctime(&now); // converts to string
        dt[strlen(dt)-1] = '\0'; // remove trailing newline

        file << "[" << dt << "] " << message << endl;
    }
};

int main() {
    Logger l("data.txt");
    l.log("hey mikasingh");
    l.log("hey honeySins");

    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    if (file.eof()) {
        cout << "Successfully read all lines\n";
    } else {
        cerr << "Couldn't read all lines\n";
    }

    return 0;
}
