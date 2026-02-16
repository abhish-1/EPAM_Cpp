//Stores a list of item names (e.g., Apple, Banana) and their prices (e.g., 1.50, 0.99) Uses <iomanip>
//manipulators: std::setw for column width, std::fixed and std::setprecision for money representation
// Prints a table to the console in the following format:

// Item         Price
// Apple        1.50
// Banana       0.99

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int main(){
    vector<string> vec;
    vector<double> price;
    vec.push_back("apple");
    price.push_back(1.502);
    vec.push_back("Banana");
    price.push_back(0.992);

    cout<<left<<setw(15)<<"Item";
    cout<<left<<setw(15)<<"Price";
    cout<<endl;
    for(int i=0;i<2;i++){
        cout<<left<<setw(15)<<vec[i];
        cout<<left<<setw(15)<<fixed<<setprecision(2)<<price[i];
        cout<<endl;
    }
    return 0;
}