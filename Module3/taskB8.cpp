//Defines two interfaces : Playable(pure virtual play() and pause()) and 
// Recordable(pure virtual record() and stop()) Implements a class MediaPlayer
// that inherits from both interfaces, providing concrete functionality Creates 
// a MediaPlayer object and uses pointers of type Playable* and Recordable* to 
// call appropriate methods, demonstrating interface polymorphism

#include<iostream>
using namespace std;

class Playable {
public:
	virtual void play() = 0;
	virtual void pause() = 0;
};
class Recordable {
public:
	virtual void record() = 0;
	virtual void stop() = 0;
};

class MediaPlayer : public Playable, public Recordable {
	void play() {
		cout << "I play by mediaplayer" << endl;
	}
	void record() {
		cout << "I record by mediaplayer" << endl;
	}
	void stop() {
		cout << "I stop by mediaplayer" << endl;
	}
	void pause() {
		cout << "I pause by mediaplayer" << endl;
	}
};
int main() {
	MediaPlayer mp;
	Playable* ptr1 = dynamic_cast<Playable*>(&mp);
	Recordable* ptr2 = dynamic_cast<Recordable*>(&mp);
	ptr1->play();
	ptr1->pause();
	ptr2->record();
	ptr2->stop();
	return 0;

}