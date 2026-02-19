//Defines a Book class with members: title, author (strings), and price (double). Overloads operator<< to print a Book’s details
// using std::ostream Overloads operator>> to read a Book’s details using std::istream Tests these by reading a list of books
// from input and outputting the list via streams

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Book {
public:
    string title;
    string author;
    double price;

    Book() : title(""), author(""), price(0.0) {}
    Book(string t, string a, double p) : title(t), author(a), price(p) {}
    
    friend ostream& operator<<(ostream& COUT, const Book& b);
    friend istream& operator>>(istream& CIN, Book& b);
};

ostream& operator<<(ostream& COUT, const Book& b) {
    COUT << b.title << " by " << b.author << " ($" << b.price << ")";
    return COUT;
}

istream& operator>>(istream& CIN, Book& b) {
    getline(CIN, b.title, ','); 
    getline(CIN, b.author, ',');  
    return CIN;
}

int main() {
    string fileName;
    cout << "Please enter the filepath: ";
    cin >> fileName;
    fstream file(fileName, ios::in | ios::out | ios::app);
    if (!file) {
        cerr << "Error: Could not open file '" << fileName << "'" << endl;
        return 1;
    }
    
    Book b;
    while (file >> b) {
        cout << b << endl;
    }
    
    if (file.eof()) {
        cout << "Finished reading existing books." << endl;
    } else if (file.fail()) {
        cerr << "Error reading file." << endl;
    }
    
    file.clear();
    file.seekp(0, ios::end);
        
    int m;
    cout << "Enter the number of books you want to add: ";
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        string title, author;
        double price;
        
        cout << "Enter book title: ";
        getline(cin,title);
        cout << "Enter author: ";
        getline(cin,author);
        cout << "Enter price: ";
        cin >> price;
        
        Book newBook(title, author, price);
        file << newBook << endl;  
    }
    
    file.clear();
    file.seekg(0, ios::beg);
    
    int count = 0;
    while (file >> b) {
        cout << b << endl;
        count++;
    }
    
    cout << "Total books in file: " << count << endl;
    
    file.close();
    return 0;
}