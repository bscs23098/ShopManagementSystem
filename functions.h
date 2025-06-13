// #ifndef FUNCTIONS_H
// #define FUNCTIONS_H
// #include "Person.h"
// #include<sstream>
// #include"string.h"
// #include "Product.h"
// #include "Customer.h"
// #include "Shopkeeper.h"
// #include "Admin.h"
// #include "Address.h"
// #include "dynamic.h"
// #include <iostream>
// #include <fstream>
// using namespace std;

// void SaveProducts(Dynamic_array<Product>& products, const string& filename) {
//     ofstream file(filename);
//     if (!file) {
//         cout << "Error opening file for writing!" << endl;
//         return;
//     }
//     file << products.size() << endl;
//     for (int i = 0; i < products.size(); i++) {
//         file << products[i].getId() << '|'
//              << products[i].getName() << '|'
//              << products[i].getPrice() << '|'
//              << products[i].getQuantity() <<'|'<< endl;
//     }
//     file.close();
// }
// void LoadProducts(Dynamic_array<Product>& products, const string& filename) {
//     ifstream file(filename);
//     if (!file) {
//         cout << "Error opening file for reading!" << endl;
//         return;
//     }

//     int size;
//     file >> size;
//     file.ignore(); // Skip the newline after the number

//     for (int i = 0; i < size; ++i) {
//         String line;
//         getline(file, line);
//         if (line.empty()) continue; 
//         stringstream ss(line);
//         String id, name, priceStr, quantityStr;

//         getline(ss, id, '|');
//         getline(ss, name, '|');
//         getline(ss, priceStr, '|');
//         getline(ss, quantityStr, '|');

//         // Create the Product object using constructor
//         Product p(id, name, stof(priceStr), stoi(quantityStr));

//         products.push(p);
//     }

//     file.close();
// }



// // void SaveCustomers(const Dynamic_array<Customer>& customers, const String& filename) {
// //     ofstream file(filename);
// //     if (!file) {
// //         cout << "Error opening file for writing: " << filename << endl;
// //         return;
// //     }
// //     file << customers.size() << endl; 
// //     for (int i = 0; i < customers.size(); i++) {
// //         file << customers[i];
// //     }

// //     file.close();
// // }
// // void LoadCustomers(Dynamic_array<Customer>& customers, const String& filename) {
// //     ifstream file(filename);
// //     if (!file) {
// //         cerr << "Error opening file for reading: " << filename << endl;
// //         return;
// //     }
// //     int size;
// //     file >> size;
// //     String id, name, password;
// //     int age;
// //     int houseNo;
// //     String city, province, country;
// //     for (int i = 0; i < size; i++) {
// //         file >> id >> name >> password >> age >> houseNo >> city >> province >> country;
// //         Customer c(id, name, password, age, Address(houseNo, city, province, country));
// //         customers.push(c);
// //     }
// //     file.close();
// // }
// // void SaveShopkeepers(const Dynamic_array<Shopkeeper>& shopkeepers, const String& filename) {
// //     ofstream file(filename);
// //     if (!file) {
// //         cout << "Error opening file for writing: " << filename << endl;
// //         return;
// //     }
// //     file << shopkeepers.size() << endl; 
// //     for (int i = 0; i < shopkeepers.size(); i++) {
// //         file << shopkeepers[i];
// //     }

// //     file.close();
// // }
// // void LoadShopkeepers(Dynamic_array<Shopkeeper>& shopkeepers, const String& filename) {
// //     ifstream file(filename);
// //     if (!file) {
// //         cout << "Error opening file for reading: " << filename << endl;
// //         return;
// //     }
// //     int size;
// //     file >> size;
// //     String id, name, password;
// //     int age;
// //     int houseNo;
// //     String city, province, country;

// //     for (int i = 0; i < size; i++) {
// //         file >> id >> name >> password >> age >> houseNo >> city >> province >> country;
// //         Shopkeeper s(id, name, password, age, Address(houseNo, city, province, country));
// //         shopkeepers.push(s);
// //     }
// //     file.close();
// // }


// #endif