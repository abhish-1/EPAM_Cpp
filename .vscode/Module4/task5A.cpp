//Defines a Book class with members: title, author (strings), and price (double). Overloads operator<< to print a Book’s details
// using std::ostream Overloads operator>> to read a Book’s details using std::istream Tests these by reading a list of books
// from input and outputting the list via streams

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Book{
    public:
    string title;
    string author;
    double price;
    Book() : title(""), author(""), price(0.0) {}
    Book(string title, string author, double price):title(title),author(author),price(price){};
    friend ostream& operator<<(ostream& COUT, const Book& b);
    friend istream& operator>>(istream& CIN, Book& b);
};
ostream& operator<<(ostream& COUT,Book b){
    COUT<<b.title<<b.author<<b.price;
    return COUT;
}
istream& operator>>(istream& CIN,Book b){
    CIN>>b;
    return CIN;
}

int main(){
    string fileName;
    cout<<"Pleaase enter the filepath"<<endl;
    cin.ignore();
    cin>>fileName;
    ifstream file(fileName);
    if (!file) {
        cerr << "Error: Could not open file '" << fileName << "'" << endl;
        return 1;
    }
    cout<<"Enter book info"<<endl;
    
    Book b;
    while(getline(file>>b)){
        string title;
        string author;
        double price;
        cout<<"Enter title"<<endl;
        cin>>title;
        cout<<"Enter author"<<endl;
        cin>>author;
        cout<<"Enter price"<<endl;
        cin>>price;
        Book book(title,author,price);
        file<<book;
    }
    file.close();
}