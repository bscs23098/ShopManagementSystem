#include"admin.h"

Admin* Admin::instance = nullptr;
Admin* Admin::getInstance(String id,String pass,String name, int age, Address address) {
    if (!instance) {
        instance = new Admin(id, pass, name, age, address);
    }
    return instance;
}

void Admin::addProduct(Dynamic_array<Product>& products, const Product& product) {
        products.push(product);
        cout << "Product added: " << product.getId() << endl;
}

void Admin::updateProduct(Dynamic_array<Product>& products, const Product& updatedProduct) {
    for (int i = 0; i < products.size(); i++) {
        if (products[i].getId() == updatedProduct.getId()) {
            products[i] = updatedProduct;
            cout << "Product updated: " << updatedProduct.getId() << endl;
            return;
        }
    }
    cout << "Product not found: " << updatedProduct.getId() << endl;
}
void Admin::removeProduct(Dynamic_array<Product>& products, const String& productId) {
    for (int i = 0; i < products.size(); i++) {
        if (products[i].getId() == productId) {
            products.delete_at(i);
            cout << "Product removed: " << productId << endl;
            return;
        }
    }
    cout << "Product not found: " << productId << endl;
}

void Admin::showProducts(Dynamic_array<Product>& products){
    cout << "Available Products:\n";
    for (int i = 0; i < products.size(); i++) {
        cout << products[i];
    }
}




void Admin::updateShopkeeper(Dynamic_array<Shopkeeper>& shopkeeper, const Shopkeeper& updatedShopkeeper) {
    for (int i = 0; i < shopkeeper.size(); i++) {
        if (shopkeeper[i].getId() == updatedShopkeeper.getId()) {
            shopkeeper[i] = updatedShopkeeper;
            cout << "Shopkeeper updated: " << updatedShopkeeper.getId() << endl;
            return;
        }
    }
    cout << "Shopkeeper not found: " << updatedShopkeeper.getId() << endl;
}


void Admin::removeShopkeeper(Dynamic_array<Shopkeeper>& shopkeeper, const String& shopkeeperId) {
        for (int i = 0; i < shopkeeper.size(); i++) {
            if (shopkeeper[i].getId() == shopkeeperId) {
                shopkeeper.delete_at(i);
                cout << "Shopkeeper removed: " << shopkeeperId << endl;
                return;
            }
        }
        cout << "Shopkeeper not found: " << shopkeeperId << endl;
}
void Admin::addShopkeeper(Dynamic_array<Shopkeeper>& shopkeeper, const Shopkeeper& newshopkeeper) {
    shopkeeper.push(newshopkeeper);
    cout << "Shopkeeper added: " << newshopkeeper.getId() << endl;
}

void Admin::showShopkeepers(const Dynamic_array<Shopkeeper>& shopkeeper) const {
        cout << "Available Shopkeepers:\n";
        for (int i = 0; i < shopkeeper.size(); i++) {
            cout << shopkeeper[i];
        }
}
String Admin::getPassword() const {
        return Person::getPassword();
}