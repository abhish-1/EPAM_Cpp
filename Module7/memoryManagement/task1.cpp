// Imagine you are building a simple library management system. Each Book object is dynamically allocated and 
// managed by a Library class. Sometimes, books are removed from the library, and you need to ensure that no part
// of your program tries to access a book that has already been deleted. This scenario is a common source of 
// dangling pointers in C++.
#include<iostream>
#include<memory>
#include<vector>
using namespace std;
class Book {
public:
    std::string title;
    std::string author;

    Book(const std::string& t, const std::string& a) : title(t), author(a) {}
    void print() const {
        std::cout << "Book: " << title << " by " << author << std::endl;
    }
};

class Library {
    std::vector<unique_ptr<Book>> books;
public:
    void addBook(const std::string& title, const std::string& author) {
        Book* b = new Book(title, author);
        unique_ptr<Book> ptr (b);
        books.push_back(move(ptr));
    }

    Book* findBook(const std::string& title) {
        for (auto& book : books) {
            if (book->title == title) return book.get() ;
        }
        return nullptr;
    }

    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->title == title) {
                books.erase(it);
            } 
        }
    }
};

int main() {
    Library lib;
    lib.addBook("1984", "George Orwell");
    lib.addBook("Brave New World", "Aldous Huxley");

    Book* bookPtr = lib.findBook("1984");
    if (bookPtr) {
        bookPtr->print();
    }

    lib.removeBook("1984");

    std::cout << "Trying to access deleted book:" << std::endl;
    // if (bookPtr) {
    //     bookPtr->print(); 
    // will get a segment fault
    // }

    return 0;
}
