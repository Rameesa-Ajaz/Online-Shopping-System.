#include <iostream>
#include <string>
#include<stdexcept>

using namespace std;

// Product class
class Product {
private:
    string name;
    float price;
public:
    Product(){

    }

    Product(string n, float p){
        name = n;
        price = p;
    }
    string getName(){
        return name;
    }

    double getPrice(){
        return price;
    }
};

// User class
class User {
private:
    string name;
    string address;
public:

    User(){

    }

    User(string n, string add){
        name = n;
        address = add;
    }
    string getName(){
        return name;
    }

    string getAddress(){
        return address;
    }
};

// ShoppingCart class
class ShoppingCart {
private:
    Product cart[10];
    int ind = 0;
public:

    ShoppingCart(){

    }

    void addProduct(){
        string name; 
        float pri;
        cin.ignore();  // Ignore any leftover newline character in the input buffer
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Product Price: ";
        cin >> pri;

        Product p(name, pri);

        cart[ind] = p;
        cout << endl << p.getName() << " added to cart." << endl;
        ind++;
    }

    void showCart() {
        cout << endl << "Products in your cart:" << endl;
        for(int i=0; i<ind; i++){
            cout << cart[i].getName() << ":-  $" << cart[i].getPrice() << endl;
        }
    }

    int getTotal(){
        int total = 0;  // Reset total to 0 before recalculating
        for(int i=0; i<ind; i++){
            total = total + cart[i].getPrice();
        }
        return total;
    }

};

// Order class
class Order {
private:
    User user;
    ShoppingCart cart;
public:
    Order(){
        
    }

    void placeOrder(User user, ShoppingCart cart) {
        int total;
        cout << endl << "----------------------------------------------------------" << endl;
        cout << "Congratulation " << user.getName() << ", Your order is Successfully Placed" << endl;
        cout << "Your Address: " << user.getAddress() << endl;
        cout << "----------------------------------------------------------" << endl;

        cart.showCart(); 

        cout << "================" << endl;
        cout << "Total: $" << cart.getTotal() << endl;
        cout << "================" << endl;
    }
};

int main(){

    cout << endl << "===================================" << endl;
    cout << "       Online Shopping System      ";
    cout << endl << "===================================" << endl;

    cout << endl << "Available Products" << endl;
    cout << "==================" << endl;

    Product availableProducts[] = { {"shoes", 1200},
                                   {"shirt", 2200},
                                   {"Bag", 220},
                                   {"Iron", 5200},
                                   {"Chair", 1500},
                                   {"Charger", 200},
                                   {"T-shirt", 2200},
                                   {"toys", 300} };

    for(int i=0; i<8; i++){
        cout << availableProducts[i].getName() << " :- " << availableProducts[i].getPrice() << endl;
    }

    string userName, add;
    cout << endl << "Enter your name: ";
    getline(cin, userName);
    cout << "Enter your Address: ";
    getline(cin, add);

    User user(userName, add);

    ShoppingCart cart;

    int choice;
    do{
        cout << endl << "1. Add a Product to cart" << endl;
        cout << "2. Show Cart" << endl;
        cout << "3. Place Order" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cart.addProduct();
                    break;

                case 2:
                    cart.showCart();
                    break;

                case 3:
                    break;

                default:
                    cout << "Enter correct Choice" << endl;
            }
        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }while(choice != 3);

    Order order;
    order.placeOrder(user, cart);
    

    return 0;
}