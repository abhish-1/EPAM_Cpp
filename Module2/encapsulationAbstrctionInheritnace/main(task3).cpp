#include"Student.h"
using namespace std;
int main() {
	Student s;
	s.setName("abhishek");
	s.setMarks(-69);
	s.setMarks(69);
	s.setRoll(69);

	cout << s.getName() << endl; 
	cout << s.getRoll() << endl; 
	cout << s.getMarks() << endl;
	// cout << s.name;    please get lost

}