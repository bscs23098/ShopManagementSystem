#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
using namespace std;
class Product {
    String id;
    String name;
    double price;
    int quantity;
public:
    Product() : id(""), name(""), price(0.0), quantity(0) {}

    Product(String id, String name, double price, int quantity)
        : id(id), name(name), price(price), quantity(quantity) {}

    Product(const Product& obj)
        : id(obj.id), name(obj.name), price(obj.price), quantity(obj.quantity) {}
    bool available() const {
        return quantity > 0;
    }
    friend ostream& operator<<(ostream& os, const Product& obj) {
        os << "Product ID: " << obj.id <<" --- "
          << "Name: " << obj.name << " --- "
          << "Price: $" << obj.price << " --- "
          << "Quantity: " << obj.quantity << " --- ";
          os<<endl;
        return os;
    }
    double getPrice() const {
        return price;
    }
    String getId() const {
        return id;
    }
    bool operator==(const Product& other) const {
        return id == other.id && name == other.name && price == other.price && quantity == other.quantity;
    }

    String getName() {
        return name.c_str();
    }
    String getId() {
        return id.c_str();
    }
    int getQuantity()  {
        return quantity;
    }
    double getPrice()  {
        return price;
    }

};

#endif // PRODUCT_H