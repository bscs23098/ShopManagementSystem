#ifndef SHOPKEEPER_H
#define SHOPKEEPER_H
#include<iostream>
#include"string.h"
#include"Person.h"
#include"Product.h"
#include"Address.h"
#include"dynamic.h"
using namespace std;

class Shopkeeper : public Person {
public:
    Shopkeeper() : Person() {}

    String getPassword() const {
        return Person::getPassword();
    }

    Shopkeeper(String id,String pass,String name, int age, Address address)
        : Person(id, pass, name, age, address) {}

    Shopkeeper(const Shopkeeper& obj)
        : Person(obj) {}

    void addProduct(Dynamic_array<Product>& products, const Product& product) {
        products.push(product);
        cout << "Product added: " << product.getId() << endl;
    }

    void removeProduct(Dynamic_array<Product>& products, const String& productId) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].getId() == productId) {
                products.delete_at(i); 
                cout << "Product removed: " << productId << endl;
                return;
            }
        }
        cout << "Product not found: " << productId << endl;
    }

    void showProducts(const Dynamic_array<Product>& products) const {
        cout << "Available Products:\n";
        for (int i = 0; i < products.size(); i++) {
            if(products[i].available())
            {cout << products[i];}
        }

    }
    void updateProduct(Dynamic_array<Product>& products, const Product& updatedProduct) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].getId() == updatedProduct.getId()) {
                products[i] = updatedProduct;
                cout << "Product updated: " << updatedProduct.getId() << endl;
                return;
            }
        }
        cout << "Product not found: " << updatedProduct.getId() << endl;
    }
    ~Shopkeeper() {
        // Destructor
    }
};

#endif