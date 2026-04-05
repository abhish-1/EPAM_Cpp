// In your main function (or globally for simplicity if preferred, but passing by reference is better), declare a std::map named inventory. The key should be an int (for ProductID) and the value should also be an int (for StockQuantity). Populate this map with at least 5 initial products and their stock levels to start (e.g., inventory[101] = 50;). std::map<int, int> productInventory; productInventory[101] = 50; productInventory[102] = 25; productInventory[103] = 100; productInventory[104] = 10; productInventory[105] = 75;
/*
Implement Utility Functions
void clearInputBuffer(): This function is crucial for robust user input. Implement it to clear std::cin's error flags and discard 
remaining characters in the input buffer. You'll use this after any std::cin operation that might fail or leave newline characters.
void clearInputBuffer() { std::cin.clear(); // Clear error flags // Discard all characters in the input buffer up to the newline
character std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
bool getProductStock(int productId, int& currentStock, const std::map<int, int>& inventoryMap): This function should search for productId
in inventoryMap. If found, it should update currentStock (passed by reference) with the product's quantity and return true. If not found,
it should set currentStock to 0 and return false. Hint: Use std::map::find() or std::map::count() for checking existence.
void displayInventory(const std::map<int, int>& inventoryMap, const std::string& title): This function should iterate through the 
inventoryMap using a range-based for loop and print each product's ID and its stock quantity. Provide a descriptive title for the output.
*/

#include<iostream>
#include<string>
#include<map>
#include<limits>
using namespace std;

std::map<int, int> productInventory = {
    {101, 50},
    {102, 25},
    {103, 100},
    {104, 10},
    {105, 75}
};

void clearInputBuffer() { 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

bool getProductStock(int productId, int& currentStock, const std::map<int, int>& inventoryMap){
    auto it = inventoryMap.find(productId);
    if(it==inventoryMap.end()){
        currentStock=0;
        return false;
    }
    currentStock=it->second;
    return true;
}

void displayInventory(const std::map<int, int>& inventoryMap, const std::string& title){
    for(auto it = inventoryMap.begin();it!=inventoryMap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}

void addNewProduct(std::map<int, int>& inventory){
    cout<<"please enter your aproduct id"<<endl;
    int prodId;
    cin>>prodId;
    clearInputBuffer();
    cout<<"please enter your aproduct stock"<<endl;
    int stock;
    cin>>stock;
    clearInputBuffer();
    if(stock<0) {
        cout<<"Stock must be positive"<<endl;
        return;
    }
    if(inventory.count(prodId)){
        cout<<"Please perform restocking nigg"<<endl;
        return;
    }
    inventory.insert({prodId,stock});
}

void performSale(std::map<int, int>& inventory){
    cout<<"please enter product id"<<endl;
    int prodId;
    cin>>prodId;
    clearInputBuffer();
    cout<<"please enter quantity to sell"<<endl;
    int quantity;
    cin>>quantity;
    clearInputBuffer();
    if(quantity<0) {
        cout<<"Quantity must be positive"<<endl;
        return;
    }
    
    auto it = inventory.find(prodId);
    if(it != inventory.end()){
        if(it->second >= quantity){
            it->second -= quantity;
            cout<<"Sale completed! Remaining stock: "<< it->second <<endl;
        } else {
            cout<<"Insufficient stock! Available: "<< it->second <<endl;
        }
    } else {
        cout<<"Product not available in inventory"<<endl;
    }
}

void performRestock(std::map<int, int>& inventory){
    cout<<"please enter your product id"<<endl;
    int prodId;
    cin>>prodId;
    clearInputBuffer();
    cout<<"please enter quantity to add"<<endl;
    int stock;
    cin>>stock;
    clearInputBuffer();
    if(stock<0) {
        cout<<"Stock must be positive"<<endl;
        return;
    }
    auto it = inventory.find(prodId);
    if(it != inventory.end()){
        it->second += stock;
        cout<<"Restocking done! New stock: "<< it->second <<endl;
        return;
    }
    cout<<"Product not available in inventory"<<endl;
    cout<<"Would you like to add as new product? (y/n): ";
    char choice;
    cin >> choice;
    clearInputBuffer();
    if(choice == 'y' || choice == 'Y') {
        inventory[prodId] = stock;
        cout<<"New product added with stock: "<< stock <<endl;
    }
}

void checkProductStatus(const std::map<int, int>& inventory){
    cout<<"please enter your aproduct id"<<endl;
    int prodId;
    cin>>prodId;
    clearInputBuffer();
    int stock;
    if (getProductStock(prodId, stock, inventory)) {
        cout << "Product " << prodId << " has stock: " << stock << endl;
    } else {
        cout << "Product not found" << endl;
    }
}

void discontinueProduct(std::map<int, int>& inventory){
    cout<<"please enter your aproduct id"<<endl;
    int prodId;
    cin>>prodId;
    clearInputBuffer();

    auto it = inventory.find(prodId);
    if(it != inventory.end()){
        inventory.erase(prodId);
        cout<<"removal done"<<endl;
        return;
    }
    cout<<"prod not available in inventpry"<<endl;
    return;
}

void ActionToPerform(std::map<int, int>& inventory) {
    int choice;
    do {
        cout << "1. Add New Product\n";
        cout << "2. Perform Sale\n";
        cout << "3. Perform Restock\n";
        cout << "4. Check Product Status\n";
        cout << "5. Discontinue Product\n";
        cout << "6. Display All Products\n";
        cout << "0. Exit\n";
        cin >> choice;
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                addNewProduct(inventory);
                break;
            case 2:
                performSale(inventory);
                break;
            case 3:
                performRestock(inventory);
                break;
            case 4:
                checkProductStatus(inventory);
                break;
            case 5:
                discontinueProduct(inventory);
                break;
            case 6:
                displayInventory(inventory, "");
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 0);
}

int main() {
    displayInventory(productInventory, "Initial Inventory");
    ActionToPerform(productInventory);
    cout << "Program completed\n";
    return 0;
}