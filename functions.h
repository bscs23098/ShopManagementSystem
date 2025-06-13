#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Person.h"
#include"string.h"
#include "Product.h"
#include "Customer.h"
#include "Shopkeeper.h"
#include "Admin.h"
#include "Address.h"
#include "dynamic.h"

void SaveProducts(const Dynamic_array<Product>& products, const String& filename) {
    ofstream file(filename.c_str());
    if (!file) {
        cout << "Error opening file for writing: " << filename << endl;
        return;
    }
    file << products.size() << endl; 
    for (int i = 0; i < products.size(); i++) {
        file << products[i];
    }

    file.close();
}
void LoadProducts(Dynamic_array<Product>& products, const String& filename) {
    ifstream file(filename.c_str());
    if (!file) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    int size;
    file >> size;
    String id, name;
    double price;
    int quantity;

    for (int i = 0; i < size; i++) {
        file >> id >> name >> price >> quantity;
        Product p(id, name, price, quantity);
        products.push(p);
    }

    file.close();
}
void SaveCustomers(const Dynamic_array<Customer>& customers, const String& filename) {
    ofstream file(filename.c_str());
    if (!file) {
        cout << "Error opening file for writing: " << filename << endl;
        return;
    }
    file << customers.size() << endl; 
    for (int i = 0; i < customers.size(); i++) {
        file << customers[i];
    }

    file.close();
}
void LoadCustomers(Dynamic_array<Customer>& customers, const String& filename) {
    ifstream file(filename.c_str());
    if (!file) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    int size;
    file >> size;
    String id, name, password;
    int age;
    Address address;
    for (int i = 0; i < size; i++) {
        file >> id >> name >> password >> age >> address;
        Customer c(id, name, password, age, address);
        customers.push(c);
    }
    file.close();
}
void SaveShopkeepers(const Dynamic_array<Shopkeeper>& shopkeepers, const String& filename) {
    ofstream file(filename.c_str());
    if (!file) {
        cout << "Error opening file for writing: " << filename << endl;
        return;
    }
    file << shopkeepers.size() << endl; 
    for (int i = 0; i < shopkeepers.size(); i++) {
        file << shopkeepers[i];
    }

    file.close();
}
void LoadShopkeepers(Dynamic_array<Shopkeeper>& shopkeepers, const String& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file for reading: " << filename << endl;
        return;
    }
    int size;
    file >> size;
    String id, name, password;
    int age;
    int houseNo;
    String city, province, country;
    Address address;

    for (int i = 0; i < size; i++) {
        file >> id >> name >> password >> age >> houseNo >> city >> province >> country;
        Shopkeeper s(id, name, password, age, Address(houseNo, city, province, country));
        shopkeepers.push(s);
    }
    file.close();
}
#endif