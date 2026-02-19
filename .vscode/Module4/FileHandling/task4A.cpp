//Opens an existing text file for reading using std::ifstream Creates a new file for writing 
//using std::ofstream Reads lines from the input file and writes them to the output file, copying content line by line

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    string fileName;
    cout<<"Please enter your file for reading"<<endl;
    cin.ignore();
    cin>>fileName;
    ifstream file(fileName);
    if(!file){
        cerr<<"Error in opening read file";
        return 1;
    }
    int lineNo=0;
    string line;
    string fileName2;
    cout<<"Please enter your file for writing"<<endl;
    cin.ignore();
    cin>>fileName2;
    ofstream file1(fileName2);
    if(!file1){
        cerr<<"Error in opening write file";
        return 1;
    }
    while(getline(file,line)){
        if(file.fail()){
            cerr<<"cant read file"<<endl;
        }
        if(!line){
            cerr<<"cant read line"<<endl;
            return 1;
        }
        file1<<line<<endl;
    }
    if(file.eof()){
        clog<<"reading completed"<<endl;
    }
    else{
        cerr<<"error"<<endl;
    }
    return 0;
}