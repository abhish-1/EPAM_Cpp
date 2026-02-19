//Write a C++ program that: Asks the user for a filename and a text string to save Uses std::ofstream to
// write the text to the specified file Uses std::ifstream to reopen the same file and display its contents to the user

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    string fileName;
    cin>>fileName;
    // ios::out for writing, ios::in for reading, ios::trunc to create/overwrite
    fstream file(fileName, ios::out | ios::in | ios::trunc);
    if(!file){
        cerr<<"file cant be opened"<<endl;
        return 1;
    }
    string input;
    cout<<"enter the line"<<endl;
    //Need cin.ignore() before getline because cin>>fileName left '\n' in buffer
    cin.ignore();  // Add this line!
    getline(cin, input);
    // check if input is empty or just proceed (getline succeeded)
    if(input.empty()) {
        cerr<<"Empty input provided"<<endl;
    }
    file << input;
    //After writing, file pointer is at END.
    // Need to reset to BEGINNING before reading!
    file.seekg(0, ios::beg);  
    string sentence;
    int sentenceNo = 0;
    
    while(getline(file, sentence)){
       //file.fail() (check the stream, not a variable)
        if(file.fail()){
            cerr<<"error reading";
            return 1;
        }
        Add space between number and sentence for readability
        cout << sentenceNo << " " << sentence << endl;
        sentenceNo++;
    }
    
    if(file.eof()){
        clog<<"successfully reached end of file";
    }
    else{
        clog<<"error, unable to reach end";
    }
    file.close();
    return 0;
} 