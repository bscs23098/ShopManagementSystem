#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Person.h"
#include<sstream>
#include<string>
#include"string.h"
#include "Product.h"
#include "Customer.h"
#include "Shopkeeper.h"
#include "Admin.h"
#include "Address.h"
#include "dynamic.h"
#include <iostream>
#include<limits>
#include <fstream>
using namespace std;

void SaveProduct(Dynamic_array<Product>& products, const String& filename) {
    ofstream file(filename.c_str());
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    file << products.size() << endl;
    for (int i = 0; i < products.size(); i++) {
        file << products[i].getId() << '|'
             << products[i].getName() << '|'
             << products[i].getPrice() << '|'
             << products[i].getQuantity() <<'|';
        file << endl; 
    }
    file.close();
}

void LoadProduct(Dynamic_array<Product>& products, const String& filename) {
    ifstream file(filename.c_str());
    if (!file) {
        cout << "Error opening file for loading!" << endl;
        return;
    }
    int size = 0;
    if (!(file >> size)) {
        cout << "Error reading product count!" << endl;
        file.close();
        return;
    }
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Move to next line
    products.clear();
    for (int i = 0; i < size; ) {
        string line;
        if (!getline(file, line)) {
            cout << "Error reading product line " << i + 1 << endl;
            break;
        }
        if (line.empty()) continue; // Skip empty lines

        stringstream ss(line);
        string id, name, priceStr, quantityStr;

        if (!getline(ss, id, '|') ||
            !getline(ss, name, '|') ||
            !getline(ss, priceStr, '|') ||
            !getline(ss, quantityStr, '|')) {
            cout << "Malformed line: " << line << endl;
            continue;
        }

        try {
            double price = stod(priceStr);
            int quantity = stoi(quantityStr);
            Product p(String(id.c_str()), String(name.c_str()), price, quantity);
            products.push(p); // or products.push(p)
            ++i; // Only increment if a product was successfully read
        } catch (const std::exception& e) {
            cout << "Error parsing product data: " << e.what() << endl;
            continue;
        }
    }
    file.close();
}


void SaveCustomer(Dynamic_array<Customer>& customers, const String& filename) {
    ofstream file(filename.c_str());
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    file << customers.size() << endl;
    for (int i = 0; i < customers.size(); i++) {
        file << customers[i].getId() << '|'
             << customers[i].getName() << '|'
             << customers[i].getAge() << '|'
             << customers[i].getPassword() << '|'
             << customers[i].getHouseNo() << '|'
             << customers[i].getCity() << '|'
             << customers[i].getProvince() <<'|'
             << customers[i].getCountry() << '|' << endl;
    }
    file.close();
}
void LoadCustomer(Dynamic_array<Customer>& customers, const String& filename) {
    ifstream file(filename.c_str());
    if (!file) {
        cout << "Error opening file for loading!" << endl;
        return;
    }
    int size;
    file >> size;
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Move to next line
    customers.clear();
    for (int i = 0; i < size; i++) {
        string line;
        getline(file, line);
        if (line.empty()) continue;

        stringstream ss(line);
        string id, name, password, city, province, country;
        int age, houseNo;

        getline(ss, id, '|');
        getline(ss, name, '|');
        ss >> age;
        ss.ignore(1);
        getline(ss, password, '|');
        ss >> houseNo;
        ss.ignore(1);
        getline(ss, city, '|');
        getline(ss, province, '|');
        getline(ss, country, '|');

        Address address(houseNo, city.c_str(), province.c_str(), country.c_str());
        Customer c(id.c_str(), password.c_str(), name.c_str(), age, address);
        customers.push(c);
    }
    file.close();
}

void SaveShopkeeper(Dynamic_array<Shopkeeper>& shopkeepers, const String& filename) {
    ofstream file(filename.c_str());
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    file << shopkeepers.size() << endl;
    for (int i = 0; i < shopkeepers.size(); i++) {
        file << shopkeepers[i].getId() << '|'
             << shopkeepers[i].getName() << '|'
             << shopkeepers[i].getAge() << '|'
             << shopkeepers[i].getPassword() << '|'
             << shopkeepers[i].getHouseNo() << '|'
             << shopkeepers[i].getCity() << '|'
             << shopkeepers[i].getProvince() << '|'
             << shopkeepers[i].getCountry() << '|' << endl;
    }
    file.close();
}

void LoadShopkeeper(Dynamic_array<Shopkeeper>& shopkeepers, const String& filename) {
    ifstream file(filename.c_str());
    if (!file) {
        cout << "Error opening file for loading!" << endl;
        return;
    }
    int size;
    file >> size;
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Move to next line
    shopkeepers.clear();
    for (int i = 0; i < size; i++) {
        string line;
        getline(file, line);
        if (line.empty()) continue;

        stringstream ss(line);
        string id, name, password, city, province, country;
        int age, houseNo;

        getline(ss, id, '|');
        getline(ss, name, '|');
        ss >> age;
        ss.ignore(1);
        getline(ss, password, '|');
        ss >> houseNo;
        ss.ignore(1);
        getline(ss, city, '|');
        getline(ss, province, '|');
        getline(ss, country);

        Address address(houseNo, city.c_str(), province.c_str(), country.c_str());
        Shopkeeper sk(id.c_str(), password.c_str(), name.c_str(), age, address);
        shopkeepers.push(sk);
    }
    file.close();
}


#endif