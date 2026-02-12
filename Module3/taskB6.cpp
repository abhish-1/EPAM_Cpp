//Defines an abstract base class Logger with a pure virtual log() function and a virtual 
// destructor Derives FileLogger and ConsoleLogger classes, each overriding log() and
// implementing their own destructors Dynamically allocates derived objects using Logger*
// Deletes these objects via the base pointer, and observes the order in which destructors are called
#include<iostream>
#include <vector>
using namespace std;
class Logger {
public:
	virtual void log() = 0;
	virtual ~Logger() {
		cout << "Destructor at Logger gets called" << endl;
	}
};
class FileLogger : public Logger {
public:
	void log() {
		cout << "Log function at filelogger" << endl;
	}
	~FileLogger() {
		cout << "Destructor at Filelogger gets called" << endl;
	}
};
class ConsoleLogger : public Logger {
public:
	void log() {
		cout << "Log function at ConsoleLogger" << endl;
	}
	~ConsoleLogger() {
		cout << "Destructor at ConsoleLogger gets called" << endl;
	}
};

int main() {
	vector<Logger*> arr;
	arr.push_back(new ConsoleLogger);
	arr.push_back(new FileLogger);
	for (int i = 0; i < 2; i++) {
		arr[i]->log();
	}
	for (int i = 0; i < 2; i++) {
		delete(arr[i]);
	}

}

//Log function at ConsoleLogger
//Log function at filelogger
//Destructor at ConsoleLogger gets called
//Destructor at Logger gets called
//Destructor at Filelogger gets called
//Destructor at Logger gets called