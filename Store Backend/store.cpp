//
//  store.cpp
//  StoreBackend
//
//  Created by Susan Wang on 3/31/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include "store.h"
#include <stdexcept>

Store::Store() {}
Store::Store(string name): name(name) {}
string Store::getName() const{
    return this->name;
}
void Store::setName(string name) {
    this->name = name;
}
void Store::addProduct(int productID, string productName) {
    Product newProduct(productID, productName);
    if (this->products.size() == 0)
        this->products.push_back(newProduct);
    else {
        for (int i  = 0; i < this->products.size(); ++i) {
            if (productID == this->products.at(i).getID())
                throw runtime_error("Product already exists.");
            
        }
        this->products.push_back(newProduct);
    }
}

void Store::addCustomer(int customerID, string customerName, bool credit) {
    Customer newCustomer(customerName, customerID, credit);
    if (this->customers.size() == 0) {
        this->customers.push_back(newCustomer);
    }
    else {
        for (int i  = 0; i < this->customers.size(); ++i) {
            if (customerID == this->customers.at(i).getID()) {
                throw runtime_error("Customer already exists.");
            }
        }
        this->customers.push_back(newCustomer);
    }
}

Product& Store::getProduct(int productID) {
    for (int i = 0; i < this->products.size(); ++i) {
        if (this->products.at(i).getID() == productID) {
            return this->products.at(i);
        }
    }
    throw runtime_error("Product does not exist.");
}

Customer& Store::getCustomer(int customerID) {
    for (int i = 0; i < this->customers.size(); ++i) {
        if (this->customers.at(i).getID() == customerID) {
            return this->customers.at(i);
        }
    }
    throw runtime_error("Customer does not exist.");
}

void Store::takeShipment(int productID, int quantity, double cost) {
    for (int i = 0; i < this->products.size(); ++i) {
        if (this->products.at(i).getID() == productID) {
            this->products.at(i).addShipment(quantity, cost);
            return;
        }
    }
    throw runtime_error("Product does not exist.");
}

void Store::makePurchase(int customerID, int productID, int quantity) {
    for (int j = 0; j < this->customers.size(); ++j) {
        if (this->customers.at(j).getID() == customerID) {
            for (int i = 0; i < this->products.size(); ++i) {
                if (this->products.at(i).getID() == productID) {
                    Product thisProduct = this->products.at(i);
                    Customer thisCustomer = this->customers.at(j);
                    thisCustomer.processPurchase(quantity * thisProduct.getPrice(), thisProduct);
                    thisProduct.reduceInventory(quantity);
                    this->products.at(i) = thisProduct;
                    this->customers.at(j) = thisCustomer;
                    return;
                }
            }
            throw runtime_error("Product does not exist.");
        }
    }
    throw runtime_error("Customer does not exist.");
}

void Store::takePayment(int customerID, double amount) {
    for (int i = 0; i < this->customers.size(); ++i) {
        if (this->customers.at(i).getID() == customerID) {
            this->customers.at(i).processPayment(amount);
            return;
        }
    }
    throw runtime_error("Product does not exist.");
}

void Store::listProducts(ostream& os) {
    for (int i = 0; i < this->products.size(); ++i) {
        os << this->products.at(i);
    }
}

void Store::listCustomers(ostream& os) {
    for (int i = 0; i < this->customers.size(); ++i) {
        os << this->customers.at(i);
    }
}
