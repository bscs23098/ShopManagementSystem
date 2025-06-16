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
#include<fstream>
using namespace std;
int main(){



    Dynamic_array<Shopkeeper> shopkeepers;
    Dynamic_array<Customer> customers;
    Dynamic_array<Product> products;
    LoadProduct(products, "productfile.txt");

    // shopkeepers.push(Shopkeeper("S001", "shopkeeperpass", "Shopkeeper1", 30, Address(101, "Lahore", "Punjab", "Pakistan")));
    // shopkeepers.push(Shopkeeper("S002", "shopkeeperpass2", "Shopkeeper2", 35, Address(102, "Karachi", "Sindh", "Pakistan")));
    // SaveShopkeeper(shopkeepers, "shopkeeperfile.txt");

    LoadShopkeeper(shopkeepers, "shopkeeperfile.txt");
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




    Admin* admin = Admin::getInstance("A001", "adminpass", "Admin", 40, Address(104, "Islamabad", "Punjab"));

    while (true) {
    cout <<"1 for Admin Login"<<endl;
    cout <<"2 for Shopkeeper Login"<<endl;
    cout <<"3 for Customer "<<endl;
    cout <<"Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout<<"Enter Admin Password: ";
        cin.ignore();
        String password;
        cin >> password;
        if (password == admin->getPassword()) {
            cout << "Admin Login Successful!" << endl;
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
                    cout << "Enter Product Quantity: ";
                    cin >> quantity;
                    Product newProduct(id, name, price, quantity);
                    admin->addProduct(products, newProduct);
                    SaveProduct(products, "productfile.txt");
                    cout << "Product added successfully!" << endl;
                    break;
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
                    cout << "Enter New Product Quantity: ";
                    cin >> quantity;
                    Product updatedProduct(id, name, price, quantity);
                    admin->updateProduct(products, updatedProduct);
                    SaveProduct(products, "productfile.txt");
                    cout << "Product updated successfully!" << endl;
                    break;
                }
                case 3: {
                    String productId;
                    cout << "Enter Product ID to Remove: ";
                    cin >> productId;
                    admin->removeProduct(products, productId);
                    SaveProduct(products, "productfile.txt");
                    cout << "Product removed successfully!" << endl;
                    break;
                }
                case 4:
                   admin->showProducts(products);
                    break;
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
                    cout << "Enter Shopkeeper House No: ";
                    cin >> houseNo;
                    cout << "Enter Shopkeeper City: ";
                    cin >> city;
                    cout << "Enter Shopkeeper Province: ";
                    cin >> province;
                    Shopkeeper newShopkeeper(id, pass, name, age, Address(houseNo, city, province, country));
                    admin->addShopkeeper(shopkeepers, newShopkeeper);
                    SaveShopkeeper(shopkeepers, "shopkeeperfile.txt");
                    cout << "Shopkeeper added successfully!" << endl;
                    break;
                }
                case 6: {
                    String shopkeeperId;
                    cout << "Enter Shopkeeper ID to Remove: ";
                    cin >> shopkeeperId;
                    admin->removeShopkeeper(shopkeepers, shopkeeperId);
                    SaveShopkeeper(shopkeepers, "shopkeeperfile.txt");
                    cout << "Shopkeeper removed successfully!" << endl;
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
                    cout << "Enter New Shopkeeper House No: ";
                    cin >> houseNo;
                    cout << "Enter New Shopkeeper City: ";
                    cin >> city;
                    cout << "Enter New Shopkeeper Province: ";
                    cin >> province;
                    Shopkeeper updatedShopkeeper(id, pass, name, age, Address(houseNo, city, province, country));
                    admin->updateShopkeeper(shopkeepers, updatedShopkeeper);
                    SaveShopkeeper(shopkeepers, "shopkeeperfile.txt");
                    cout << "Shopkeeper updated successfully!" << endl;
                    break;
                }
                case 8:
                    admin->showShopkeepers(shopkeepers);
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } else {
            cout << "Invalid Admin Password!" << endl;
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
               int shopkeeperChoice;
               cout << "1. Add Product" << endl;
               cout << "2. Update Product" << endl;
               cout << "3. Remove Product" << endl;
               cout << "4. Show Products" << endl;
               cout << "Enter your choice: ";
               cin >> shopkeeperChoice;
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
                       cout << "Enter Product Quantity: ";
                       cin >> quantity;
                       Product newProduct(id, name, price, quantity);
                       shopkeepers[i].addProduct(products,newProduct);
                        SaveProduct(products, "productfile.txt");
                       cout << "Product added successfully!" << endl;
                       break;
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
                       cout << "Enter New Product Quantity: ";
                       cin >> quantity;
                       Product updatedProduct(id, name, price, quantity);
                       shopkeepers[i].updateProduct(products,updatedProduct);
                       SaveProduct(products, "productfile.txt");
                       break;
                   }
                   case 3: {
                       String productId;
                       cout << "Enter Product ID to Remove: ";
                       cin >> productId;
                       shopkeepers[i].removeProduct(products,productId);
                        SaveProduct(products, "productfile.txt");
                       break;
                   }
                   case 4:
                       shopkeepers[i].showProducts(products);
                       break;
                   default:
                       cout << "Invalid choice!" << endl;
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
            String id;
            cout << "Enter Customer ID: ";
            cin >> id;
            String password;
            cout << "Enter Customer Password: ";
            cin >> password;
            for (int i = 0; i < customers.size(); i++) {
                if (customers[i].getPassword() == password && customers[i].getId() == id) {
                    cout << "Customer Login Successful!" << endl;
                    int customerAction;
                    cout << "1. Add Product to Purchased Products" << endl;
                    cout << "2. Remove Product from Purchased Products" << endl;
                    cout << "3. Show Purchased Products" << endl;
                    cout << "Enter your choice: ";
                    cin >> customerAction;
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
                            break;
                        }
                        case 3:
                            customers[i].showPurchasedProducts();
                            customers[i].bill();
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                    break;
            }
        }
    }  
    else if (customerChoice == 2) {
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
                break;
            }
        }
        if (!idExists) {
            customers.push(newCustomer);
            SaveCustomer(customers, "customerfile.txt");
            cout << "Customer Registration Successful!" << endl;
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
