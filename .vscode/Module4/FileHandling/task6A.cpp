#include <iostream>
#include <string>
#include <fstream>  // You need this for file streams
using namespace std;

class Book {
    string title;
    string author;
    float price;
    
public:
    // Fixed constructor syntax - removed semicolon
    Book() : title(""), author(""), price(0.0) {}  // Fixed: removed semicolon
    
    Book(string title, string author, float price) : title(title), author(author), price(price) {}
    
    // Friend function declarations
    friend Book loadFromFile(ifstream& file);
    friend void saveToFile(const Book& book, ofstream& outfile);
    
};

Book loadFromFile(ifstream& file) {
    Book b;  // Fixed: Book not book
    
    // Fixed: Correct way to read from file
    if (getline(file, b.title)) {
        getline(file, b.author);
        file >> b.price;
        file.ignore(); 
    }
    
    return b;
}

// saveToFile implementation is correct
void saveToFile(const Book& book, ofstream& outfile) {
    outfile << book.title << endl;
    outfile << book.author << endl;
    outfile << book.price << endl;
}

int main() {
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 12.99);
    Book book2("1984", "George Orwell", 10.50);
    Book book3("To Kill a Mockingbird", "Harper Lee", 14.25);
    
    ofstream outFile("books.txt");
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }
    
    cout << "Saving books to file..." << endl;
    saveToFile(book1, outFile);
    saveToFile(book2, outFile);
    saveToFile(book3, outFile);
    outFile.close();
    
    ifstream inFile("books.txt");
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }
    
    cout << "\nLoading books from file..." << endl;
    Book loadedBook1 = loadFromFile(inFile);
    Book loadedBook2 = loadFromFile(inFile);
    Book loadedBook3 = loadFromFile(inFile);
    inFile.close();
    
    
    return 0;
}