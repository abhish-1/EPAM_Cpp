//Defines an abstract base class Character with private members health (int) a
// nd mana (int) Provides setters/getters for health and mana, with validation 
// to ensure values are non-negative and within max limits Declares a pure virtual
// function attack() in Character Derives Warrior and Mage classes, each with
// their own implementation of attack() Demonstrates polymorphic attacking by 
// invoking attack() via base pointer for various derived objects

#include<iostream>
#include <vector>
using namespace std;
class Character {
	int health;
	int mana;
public:
	virtual void attack() = 0;
	Character(int health, int mana) {
		this->health = health;
		this->mana = mana;
	}
	void sethealth(int health) {
		if (health < 0 || health > 1000000) cout << "Please put a valid health" << endl;
		else this->health = health;
	}
	void setmana(int mana) {
		if (mana < 0 || mana>1000000) cout << "Please put a valid mana" << endl;
		else {
			this->mana = mana;}}
	int gethealth() {
		return health;}
	int getmana() {
		return mana;}
};
class Warrior : public Character {
public:
	Warrior(int health = 0, int mana = 0) : Character(health, mana) {
		cout << "Object creation of Warrior type" << endl;}
	void attack() {
		if (gethealth() > 0) {
			cout << "OMFL he is dead now, death seems is inevitable" << endl;}
		else {
			cout << "u dead nick!" << endl;}}
};
class Mage : public Character {
public:
	Mage(int health = 0, int mana = 0) : Character(health, mana) {
		cout << "Object creation of mage type" << endl;}
	void attack() {
		if (getmana() > 0) {
			cout << "OMFL he is dead now, mana is in abundance" << endl;}
		else {
			cout << "u got no powers, nick!" << endl;}}
};
int main() {
	vector<Character*> arr;
	arr.push_back(new Mage(9, 6));
	arr.push_back(new Warrior(63, 79));
	for (int i = 0; i < 2; i++) {
		(*arr[i]).attack();
	}
	for (int i = 0; i < 2; i++) {
		delete(arr[i]);
	}


}