#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include"string.h"
#include"Person.h"
#include"Product.h"
#include"Address.h"
#include"dynamic.h"
using namespace std;

struct Buying{
    Product product;
    int quantity;
};

class Customer : public Person {
    Dynamic_array<Buying> purchasedProducts;
public:
   Customer() : Person() {}

    Customer(String id,String pass,String name, int age, Address addrss)
        : Person(id, pass, name, age, addrss) {}

    Customer(const Customer& obj)
        : Person(obj), purchasedProducts(obj.purchasedProducts) {}

    void addProduct(const Product& product, int quantity) {
        Buying buying = { product, quantity };
        purchasedProducts.push(buying);
        cout << "Product with ID " << product.getId() << " added to purchased products.\n";
    }
    void removeProduct(const String& productId) {
        for(int i=0;i<purchasedProducts.size();i++){
            if(purchasedProducts[i].product.getId() == productId){
                purchasedProducts[i].product = Product(); // Reset the product
                purchasedProducts[i].quantity = 0; // Reset the quantity
                cout << "Product with ID " << productId << " removed from purchased products.\n";
                return;
            }
        }
        cout << "Product with ID " << productId << " not found in purchased products.\n";
    }
    void showPurchasedProducts() const {
        cout << "Purchased Products:\n";
        for(int i=0;i<purchasedProducts.size();i++){
            if(purchasedProducts[i].quantity > 0){
                cout << purchasedProducts[i].product;
                cout << "Quantity: " << purchasedProducts[i].quantity << endl;
            }
        }
    }
    void bill() const {
        double total = 0.0;
        for(int i=0;i<purchasedProducts.size();i++){
            total += purchasedProducts[i].product.getPrice() * purchasedProducts[i].quantity;
        }
        cout << "Total Bill: $" << total << endl;
    }

    String getPassword() const {
        return Person::getPassword();
    }

    friend ostream& operator<<(ostream& os, const Customer& obj) {
        os << static_cast<const Person&>(obj);
        obj.showPurchasedProducts();
        obj.bill();
        return os;
    }
    ~Customer() {
        // Destructor
        purchasedProducts.clear();
    }
    
};

#endif