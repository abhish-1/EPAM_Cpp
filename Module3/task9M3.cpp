//Defines a base class BaseLogger with a virtual destructor Derives FileLogger and
// ConsoleLogger with resource-management behavior and their own destructors Allocates 
// FileLogger and ConsoleLogger objects dynamically via BaseLogger* pointers Deletes
// these pointers and demonstrates proper destruction of derived objects Explains that 
// without a virtual destructor, only BaseLogger's destructor is invoked—potentially
// leaking resources managed in derived classes

#include<iostream>
using namespace std;
class BaseLogger {
	~ virtual BaseLogger()
};
class FileLogger : public BaseLogger {

};
class ConsoleLogger : public BaseLogger {

};
int main() {

}