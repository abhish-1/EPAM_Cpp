// Opens an input file containing a mixture of integers and possibly invalid tokens Reads values one by one, 
//checking stream states: eof(), fail(), bad() If an invalid token is encountered (fail state), skip it and continue 
//reading Stops only on EOF or unrecoverable error
#include<iostream>
#include <fstream>
#include<string>
using namespace std;
int main(){
    string fileName;
    cout<<"Please enter the input file name: ";
    cin>>fileName;
    ifstream file(fileName);
    if(!file){
        cerr<<"error opening file";
        return 1;
    }
    else{
        cout<<"opened the file smoothly"<<endl;
    }
    while(true){
        int num;
        
        file>>num;
        
        if(file.bad()){
            cerr<<"Serious stream error!\n";
            break;
        }
        else if(file.eof()){
            cout<<"end of file";
            file.close();
            return 0;
        }
        if(file.fail()){
            cerr<<"Skipping invalid token\n";
            file.clear();
            string dummy;
            file >> dummy;  
            continue;
        }
        
        cout<<"fineLine :"
        cout<<num<<endl;

        
        
    }
    file.close();
    return 0;

}