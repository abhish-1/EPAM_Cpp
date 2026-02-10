//Defines a class Messenger with two overloaded send() member functions:
//send(const std::string& msg) & send(const std::string& msg, int priority = 1) Calls send()
// with a single argument and with two arguments to observe overload resolution and the role 
// of default values Demonstrates which version of send() is called based on the arguments provided

#include<iostream>
using namespace std;
class Messenger {
public:
	void send(const string& msg) {
		cout << msg << endl;
		cout << "Send with single parameter gets called" << endl;
	}
	/*string send(const string& msg, int priority = 1) {
		cout << priority << endl;

		cout << "Send with double parameter gets called" << endl;
		return msg;
	}*/
	//will give ambiguity error as in case someone calls send("apple) then which of the above 2 will be called?
};
int main() {
	Messenger m;
	//m.send(); gives error
	m.send("hey m boi");
	//cout << m.send("double parameter call with priority ", 6);
}