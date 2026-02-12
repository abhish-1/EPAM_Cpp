//Defines a base class BaseLogger with a virtual destructor Derives FileLogger and
// ConsoleLogger with resource-management behavior and their own destructors Allocates 
// FileLogger and ConsoleLogger objects dynamically via BaseLogger* pointers Deletes
// these pointers and demonstrates proper destruction of derived objects Explains that 
// without a virtual destructor, only BaseLogger's destructor is invoked�potentially
// leaking resources managed in derived classes

#include<iostream>
using namespace std;
class BaseLogger {
	public:
	virtual ~BaseLogger(){
		cout<<"BaseLogger destructor called."<<endl;
	}
};
class FileLogger : public BaseLogger {
	int* a=new int[100];
	public:
	FileLogger(){
		for(int k = 0; k < 100; k++) {
			a[k] = k * 2;
		}
		cout<<"FileLogger constructor called, allocated resource an array of 100 size."<<endl;
	}
	
	~FileLogger(){
		delete[] a;
		cout<<"FileLogger destructor called, released resource."<<endl;
	}


};
class ConsoleLogger : public BaseLogger {
	public:
	int* a=new int[10];
	ConsoleLogger(){
		
		for(int i=0;i<10;i++){
			a[i]=i*2;
		}
		cout<<"ConsoleLogger constructor called, allocated resource an array of 100 size."<<endl;
	}
	~ConsoleLogger(){
		delete[] a;
		cout<<"ConsoleLogger destructor called, released resource."<<endl;
	}
};

int main() {
	BaseLogger* logger1 = new FileLogger();
	BaseLogger* logger2 = new ConsoleLogger();
	
	delete logger1;  // Should call FileLogger destructor
	delete logger2;  // Should call ConsoleLogger destructor
	
	return 0;

}