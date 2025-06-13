#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include"string.h"
#include"Person.h"
#include"Product.h"
#include"Address.h"
#include"dynamic.h"
#include"Shopkeeper.h"
using namespace std;

class Admin : public Person {
     Admin(String id,String pass,String name, int age, Address address)
        : Person(id, pass, name, age, address) {}
    static Admin* instance;
public:
    static Admin* getInstance(String id,String pass,String name, int age, Address address);
    void addProduct(Dynamic_array<Product>& products, const Product& product);
    void updateProduct(Dynamic_array<Product>& products, const Product& updatedProduct);
    void removeProduct(Dynamic_array<Product>& products, const String& productId);
    void showProducts(Dynamic_array<Product>& products);
    void addShopkeeper(Dynamic_array<Shopkeeper>& shopkeeper, const Shopkeeper& newshopkeeper);
    void removeShopkeeper(Dynamic_array<Shopkeeper>& shopkeeper, const String& shopkeeperId);
    void updateShopkeeper(Dynamic_array<Shopkeeper>& shopkeeper, const Shopkeeper& updatedShopkeeper);
    void showShopkeepers(const Dynamic_array<Shopkeeper>& shopkeeper) const;
    String getPassword();
    friend ostream& operator<<(ostream& os, const Admin& obj) {
        os << static_cast<const Person&>(obj);
        return os;
    }
    ~Admin() {
        // Destructor
    }
};
#endif