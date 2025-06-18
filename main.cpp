#include<iostream>
#include"string.h"
#include"Person.h"
#include"Address.h"
#include"Product.h"
#include"Customer.h"
#include"dynamic.h"
#include"Admin.h"
#include"Shopkeeper.h"
#include"functions.h"
#include<string>
#include<fstream>
#include "log.h"
using namespace std;
int main(){

    Logger::SetLogFile("mylog.txt");

    Dynamic_array<Shopkeeper> shopkeepers;
    Dynamic_array<Customer> customers;
    Dynamic_array<Product> products;
    LoadProduct(products, "productfile.txt");
    Logger::Log("Products loaded from file.", Logger::INFO);


    // shopkeepers.push(Shopkeeper("S001", "shopkeeperpass", "Shopkeeper1", 30, Address(101, "Lahore", "Punjab", "Pakistan")));
    // shopkeepers.push(Shopkeeper("S002", "shopkeeperpass2", "Shopkeeper2", 35, Address(102, "Karachi", "Sindh", "Pakistan")));
    // SaveShopkeeper(shopkeepers, "shopkeeperfile.txt");

    LoadShopkeeper(shopkeepers, "shopkeeperfile.txt");
    Logger::Log("Shopkeepers loaded from file.", Logger::INFO);
    // for(int i = 0; i < shopkeepers.size(); i++) {
    //     cout << shopkeepers[i].getId() << " | "
    //          << shopkeepers[i].getName() << " | "
    //          << shopkeepers[i].getAge() << " | "
    //          << shopkeepers[i].getPassword() << " | "
    //          << shopkeepers[i].getHouseNo() << " | "
    //          << shopkeepers[i].getCity() << " | "
    //          << shopkeepers[i].getProvince() << " | "
    //          << shopkeepers[i].getCountry() << endl;
    // }


    // for (int i = 0; i < products.size(); i++) {
    //     cout << products[i] << endl;
    // }
    LoadCustomer(customers, "customerfile.txt");
    Logger::Log("Customers loaded from file.", Logger::INFO);
    // for (int i = 0; i < customers.size(); i++) {
    //     cout << customers[i].getId() << " | "
    //          << customers[i].getName() << " | "
    //          << customers[i].getAge() << " | "
    //          << customers[i].getPassword() << " | "
    //          << customers[i].getHouseNo() << " | "
    //          << customers[i].getCity() << " | "
    //          << customers[i].getProvince() << " | "
    //          << customers[i].getCountry() << endl;
    // }


    // String productId;
    // cout << "Enter Product ID to check if it exists: ";
    // cin >> productId;
    // Product product(productId, "Sample Product", 100.0, 50);
    // for (int i = 0; i < products.size(); i++) {
    //     if(products[i].getId() == product.getId()) {
    //         cout<<"Product already exists with ID: " << products[i].getId() << endl;
    //     }
    // }



    Admin* admin = Admin::getInstance("A001", "adminpass", "Admin", 40, Address(104, "Islamabad", "Punjab"));
    Logger::Log("Admin instance created.", Logger::INFO);
    while (true) {
    cout <<"1 for Admin Login"<<endl;
    cout <<"2 for Shopkeeper Login"<<endl;
    cout <<"3 for Customer "<<endl;
    cout <<"Enter your choice: ";
    int choice;
    cin >> choice;
    cin.ignore(); 
    if (choice == 1) {
        cout<<"Enter Admin Password: ";
        String password;
        cin >> password;
        if (password == admin->getPassword()) {
            cout << "Admin Login Successful!" << endl;
            Logger::Log("Admin login successful.", Logger::INFO);
            int adminChoice;
            cout << "1. Add Product" << endl;
            cout << "2. Update Product" << endl;    
            cout << "3. Remove Product" << endl;
            cout << "4. Show Products" << endl;
            cout << "5. Add Shopkeeper" << endl;
            cout << "6. Remove Shopkeeper" << endl;
            cout << "7. Update Shopkeeper" << endl;
            cout << "8. Show Shopkeepers" << endl;
            cout << "Enter your choice: ";
            cin >> adminChoice;
            cin.ignore();
            switch (adminChoice) {
                case 1: {
                    String id, name;
                    double price;
                    int quantity;
                    cout << "Enter Product ID: ";
                    cin >> id;
                    cout << "Enter Product Name: ";
                    cin >> name;
                    cout << "Enter Product Price: ";
                    cin >> price;
                    cin.ignore();
                    cout << "Enter Product Quantity: ";
                    cin >> quantity;
                    cin.ignore();
                    Product newProduct(id, name, price, quantity);
                    admin->addProduct(products, newProduct);
                    Logger::Log("Product added: ", Logger::INFO);
                    SaveProduct(products, "productfile.txt");
                    cout << "Product added successfully!" << endl;
                    break;
                }
                case 2: {
                    admin->showProducts(products);
                    String id;
                    cout << "Enter Product ID to Update: ";
                    cin >> id;
                    bool found = false;
                    for(int i = 0; i < products.size(); i++) {
                        if (products[i].getId() == id) {
                            found = true;
                            cout << "Product found: " << products[i] << endl;
                            String name;
                            double price;
                            int quantity;
                            cout << "Enter New Product Name: ";
                            cin >> name;
                            cout << "Enter New Product Price: ";
                            cin >> price;
                            cin.ignore();
                            cout << "Enter New Product Quantity: ";
                            cin >> quantity;
                            cin.ignore();
                            Product updatedProduct(id, name, price, quantity);
                            products[i] = updatedProduct;
                            cout << "Product updated: " << updatedProduct.getId() << endl;
                            Logger::Log("Product updated: ", Logger::INFO);
                            SaveProduct(products, "productfile.txt");
                            cout << "Product updated successfully!" << endl;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Product with ID " << id << " not found!" << endl;
                        Logger::Log("Product not found during update.", Logger::WARNING);
                    }
                
                }
                case 3: {
                    String productId;
                    cout << "Enter Product ID to Remove: ";
                    cin >> productId;
                    bool found = false;
                    for(int i = 0; i < products.size(); i++) {
                        if (products[i].getId() == productId) {
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        admin->removeProduct(products, productId);
                        Logger::Log("Product removed ", Logger::INFO);
                        SaveProduct(products, "productfile.txt");
                    } else {
                        cout << "Product with ID " << productId << " not found!" << endl;
                        Logger::Log("Product not found during removal.", Logger::WARNING);
                    }
                    break;
                }
                case 4:
                  { admin->showProducts(products);
                    Logger::Log("Products displayed.", Logger::INFO);
                    break;}
                case 5: {
                    String id, pass, name;
                    int age, houseNo;
                    String city, province, country = "Pakistan";
                    cout << "Enter Shopkeeper ID: ";
                    cin >> id;
                    cout << "Enter Shopkeeper Password: ";
                    cin >> pass;
                    cout << "Enter Shopkeeper Name: ";
                    cin >> name;
                    cout << "Enter Shopkeeper Age: ";
                    cin >> age;
                    cin.ignore();
                    cout << "Enter Shopkeeper House No: ";
                    cin >> houseNo;
                    cin.ignore();
                    cout << "Enter Shopkeeper City: ";
                    cin >> city;
                    cout << "Enter Shopkeeper Province: ";
                    cin >> province;
                    cout << "Enter Shopkeeper Country: ";
                    cin >> country;
                    Shopkeeper newShopkeeper(id, pass, name, age, Address(houseNo, city, province, country));
                    admin->addShopkeeper(shopkeepers, newShopkeeper);
                    Logger::Log("Shopkeeper added: ", Logger::INFO);
                    SaveShopkeeper(shopkeepers, "shopkeeperfile.txt");
                    cout << "Shopkeeper added successfully!" << endl;
                    break;
                }
                case 6: {
                    String shopkeeperId;
                    cout << "Enter Shopkeeper ID to Remove: ";
                    cin >> shopkeeperId;
                    bool found = false;
                    for(int i = 0; i < shopkeepers.size(); i++) {
                        if (shopkeepers[i].getId() == shopkeeperId) {
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        admin->removeShopkeeper(shopkeepers, shopkeeperId);
                        SaveShopkeeper(shopkeepers, "shopkeeperfile.txt");
                        cout << "Shopkeeper removed successfully!" << endl;
                    } else {
                        cout << "Shopkeeper with ID " << shopkeeperId << " not found!" << endl;
                        Logger::Log("Shopkeeper not found during removal.", Logger::WARNING);
                    }
                    break;
                }
                case 7: {
                    String id, pass, name;
                    int age, houseNo;
                    String city, province, country = "Pakistan";
                    cout << "Enter Shopkeeper ID to Update: ";
                    cin >> id;
                    cout << "Enter New Shopkeeper Password: ";
                    cin >> pass;
                    cout << "Enter New Shopkeeper Name: ";
                    cin >> name;
                    cout << "Enter New Shopkeeper Age: ";
                    cin >> age;
                    cin.ignore();
                    cout << "Enter New Shopkeeper House No: ";
                    cin >> houseNo;
                    cin.ignore();
                    cout << "Enter New Shopkeeper City: ";
                    cin >> city;
                    cout << "Enter New Shopkeeper Province: ";
                    cin >> province;
                    cout << "Enter New Shopkeeper Country: ";
                    cin >> country;
                    Shopkeeper updatedShopkeeper(id, pass, name, age, Address(houseNo, city, province, country));
                    bool found = false;
                    for(int i = 0; i < shopkeepers.size(); i++) {
                        if (shopkeepers[i].getId() == id) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Shopkeeper with ID " << id << " not found!" << endl;
                        Logger::Log("Shopkeeper  not found during update.", Logger::WARNING);
                        break;
                    }
                    admin->updateShopkeeper(shopkeepers, updatedShopkeeper);
                    SaveShopkeeper(shopkeepers, "shopkeeperfile.txt");
                    Logger::Log("Shopkeeper updated ", Logger::INFO);
                    cout << "Shopkeeper updated successfully!" << endl;
                    break;
                }
                case 8:
                    {admin->showShopkeepers(shopkeepers);
                    Logger::Log("Shopkeepers displayed.", Logger::INFO);
                    break;}
                default:
                   { cout << "Invalid choice!" << endl;
                    Logger::Log("Invalid admin choice ", Logger::WARNING);}
            }
        } else {
            cout << "Invalid Admin Password!" << endl;
            Logger::Log("Invalid admin password entered.", Logger::ERROR);
        }

    } else if (choice == 2) {
        cout << "Enter Shopkeeper ID: ";
        String shopkeeperId;
        cin >> shopkeeperId;
        cout << "Enter Shopkeeper Password: ";
        String password;
        cin >> password;

       for(int i=0;i<shopkeepers.size();i++){
           if(shopkeepers[i].getPassword() == password){
               cout << "Shopkeeper Login Successful!" << endl;
                Logger::Log("Shopkeeper login successful: ", Logger::INFO);
               int shopkeeperChoice;
               cout << "1. Add Product" << endl;
               cout << "2. Update Product" << endl;
               cout << "3. Remove Product" << endl;
               cout << "4. Show Products" << endl;
               cout << "Enter your choice: ";
               cin >> shopkeeperChoice;
               cin.ignore();
               switch (shopkeeperChoice) {
                   case 1: {
                       String id, name;
                       double price;
                       int quantity;
                       cout << "Enter Product ID: ";
                       cin >> id;
                       cout << "Enter Product Name: ";
                       cin >> name;
                       cout << "Enter Product Price: ";
                       cin >> price;
                       cin.ignore();
                       cout << "Enter Product Quantity: ";
                       cin >> quantity;
                       cin.ignore();
                       Product newProduct(id, name, price, quantity);
                          bool idExists = false;
                     for (int j = 0; j < products.size(); j++) {
                        if (products[j].getId() == newProduct.getId()) {
                            cout << "Product with ID  already exists!" << endl;
                            idExists = true;
                            break;
                        }
                    }
                   if (!idExists) {
                        Logger::Log("Adding new product: ", Logger::INFO);
                       shopkeepers[i].addProduct(products,newProduct);
                        SaveProduct(products, "productfile.txt");
                       cout << "Product added successfully!" << endl;
                       break;
                   }
                   else {
                       cout << "Product with ID " << newProduct.getId() << " already exists!" << endl;
                       Logger::Log("Product  already exists during addition.", Logger::WARNING);
                       break;
                   }
                }
                   case 2: {
                       String id, name;
                       double price;
                       int quantity;
                       cout << "Enter Product ID to Update: ";
                       cin >> id;
                       cout << "Enter New Product Name: ";
                       cin >> name;
                       cout << "Enter New Product Price: ";
                       cin >> price;
                       cin.ignore();
                       cout << "Enter New Product Quantity: ";
                       cin >> quantity;
                        cin.ignore();
                     bool found = false;
                     for(int j = 0; j < products.size(); j++) {
                        if (products[j].getId() == id) {
                            found = true;
                            break;
                        }
                    }
                   if (!found) {
                       Product updatedProduct(id, name, price, quantity);
                       shopkeepers[i].updateProduct(products,updatedProduct);
                       Logger::Log("Product updated: ", Logger::INFO);
                       SaveProduct(products, "productfile.txt");
                       break;}
                    else {
                        cout << "Product with ID " << id << " not found!" << endl;
                        Logger::Log("Product not found during update.", Logger::WARNING);
                        break;
                   }
                }
                   case 3: {
                       String productId;
                       cout << "Enter Product ID to Remove: ";
                       cin >> productId;
                     bool found = false;
                        for(int j = 0; j < products.size(); j++) {
                            if (products[j].getId() == productId) {
                                found = true;
                                break;
                            }
                        }
                   if (!found) {
                       cout << "Product with ID " << productId << " not found!" << endl;
                       Logger::Log("Product  not found during removal.", Logger::WARNING);
                       break;
                   } else {
                       shopkeepers[i].removeProduct(products,productId);
                          Logger::Log("Product removed ", Logger::INFO);
                        SaveProduct(products, "productfile.txt");
                       break;
                   }
                   }
                   case 4:
                       {shopkeepers[i].showProducts(products);
                          Logger::Log("Products displayed by shopkeeper: ", Logger::INFO);
                       break;}
                   default:
                       {cout << "Invalid choice!" << endl;
                          Logger::Log("Invalid shopkeeper choice: ", Logger::WARNING);}
               }
               break;
           }
       }
    } else if (choice == 3) {
        cout<<"Enter 1 to login and 2 to register as a customer: ";
        int customerChoice;
        cin >> customerChoice;
        cin.ignore();
        if (customerChoice == 1) {
            Logger::Log("Customer login initiated.", Logger::INFO);
            String id;
            cout << "Enter Customer ID: ";
            cin >> id;
            String password;
            cout << "Enter Customer Password: ";
            cin >> password;
            for (int i = 0; i < customers.size(); i++) {
                if (customers[i].getPassword() == password && customers[i].getId() == id) {
                    Logger::Log("Customer login successful: " , Logger::INFO);
                    cout << "Customer Login Successful!" << endl;
                    int customerAction;
                    cout << "1. Add Product to Purchased Products" << endl;
                    cout << "2. Remove Product from Purchased Products" << endl;
                    cout << "3. Show Purchased Products" << endl;
                    cout << "Enter your choice: ";
                    cin >> customerAction;
                    cin.ignore();
                    switch (customerAction) {
                        case 1: {
                            String productId;
                            cout << "Enter Product ID to Add: ";
                            cin >> productId;
                            for (int j = 0; j < products.size(); j++) {
                                if (products[j].getId() == productId && products[j].available()) {
                                    int quantity;
                                    cout << "Enter Quantity: ";
                                    cin >> quantity;
                                    customers[i].addProduct(products[j], quantity);
                                    Logger::Log("Product added to purchased products: " , Logger::INFO);
                                    cout << "Product added to purchased products!" << endl;
                                    break;
                                }
                            }
                            break;
                        }
                        case 2: {
                            customers[i].showPurchasedProducts();
                            String productId;
                            cout << "Enter Product ID to Remove: ";
                            cin >> productId;
                            customers[i].removeProduct(productId);
                            Logger::Log("Product removed from purchased products: ", Logger::INFO);
                            break;
                        }
                        case 3:
                            {customers[i].showPurchasedProducts();
                            customers[i].bill();
                            Logger::Log("Purchased products displayed for customer: ", Logger::INFO);
                            break;}
                        default:
                            {cout << "Invalid choice!" << endl;
                            Logger::Log("Invalid customer action choice: ", Logger::WARNING);}
                    }
                    break;
            }
        }
    }  
    else if (customerChoice == 2) {
        Logger::Log("Customer registration initiated.", Logger::INFO);
        String id, name, password;
        int age;
        cout << "Enter Customer ID: ";
        cin >> id;
        cout << "Enter Customer Name: ";
        cin >> name;
        cout << "Enter Customer Age: ";
        cin >> age;
        cin.ignore(); 
        cout << "Enter Customer Password: ";
        cin >> password;
        Address address;
        cout << "Enter Customer House No: ";
        int houseNo;
        cin >> houseNo;
        cin.ignore(); 
        cout << "Enter Customer City: ";
        String city;
        cin >> city;
        cout << "Enter Customer Province: ";
        String province;
        cin >> province;
        cout << "Enter Customer Country : ";
        String country;
        cin >> country;
        bool idExists = false;
        Customer newCustomer(id, password, name, age, Address(houseNo, city, province, country));
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i].getId() == id) {
                cout << "Customer ID already exists!" << endl;
                idExists = true;
                Logger::Log("Customer ID already exists: " , Logger::WARNING);
                break;
            }
        }
        if (!idExists) {
            customers.push(newCustomer);
            SaveCustomer(customers, "customerfile.txt");
            cout << "Customer Registration Successful!" << endl;
            Logger::Log("Customer registered: ", Logger::INFO);
        }
    }
    else {
        cout << "Invalid choice!" << endl;
    }
} else {
    cout << "Invalid choice!" << endl;
}
    cout << "Do you want to continue? (y/n): ";
    char cont;
    cin >> cont;
    cin.ignore();
    if (cont != 'y' && cont != 'Y') { 
        break; 
    }    
}
    return 0;
}
