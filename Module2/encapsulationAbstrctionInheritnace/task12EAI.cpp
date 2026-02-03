#include<iostream>
#include<vector>
using namespace std;

class Item {
	int id;
	string title;

public:
	Item(int id, string title) : id(id), title(title) {}
	void setId(int id) {
		if (id > 0 && id < 100000)this->id = id;
		else cout << " Invalid ID! has to be 1to99999" << endl;
	}
	void setTitle(string title) {
		if (title.length() > 0) this->title = title;
		else {
			cout << "Title cant be empty!" << endl;
		}
	}
	int getId() {
		return id;
	};
	string getTitle() {
		return title;
	}
	virtual void display() = 0;
};

class  Book : public Item {
	string author;
public:
	Book(int id, string title, string author) :Item(id, title), author(author) {}
	void display() {
		cout << "ID " << getId() << endl;
		cout << "Title " << getTitle() << endl;
		cout << "Author " << author << endl;
		cout << endl;
	}
};

class Magazine : public Item {
	int page;
public:
	Magazine(int id, string title, int page) :Item(id, title), page(page) {}
	void display() {
		cout << "ID " << getId() << endl;
		cout << "Title " << getTitle() << endl;
		cout << "Pages " << page << endl;
		cout << endl;
	}

};

class DVD : public Item {
	int duration;
public:
	DVD(int id, string title, int duration) :Item(id, title), duration(duration) {}
	void display() {
		cout << "ID: " << getId() << endl;
		cout << "Title " << getTitle() << endl;
		cout << "Duration " << duration << " minutes" << endl;
		cout << endl;
	}
};

int main() {

	Book invalidBook(0, "", "");  // Invalid casee h (0)
	cout << endl;

	vector<Item*> arr;
	arr.push_back(new Magazine(101, "Time 101", 87));
	arr.push_back(new DVD(201, "Inception1984", 148));
	arr.push_back(new Book(301, "1984", " Michael jaiKishan"));

	for (int i = 0; i < arr.size(); i++) {
		arr[i]->display();
		delete arr[i];
	}

	return 0;
}