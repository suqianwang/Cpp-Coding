//
//  product.cpp
//  StoreBackend
//
//  Created by Susan Wang on 3/26/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include "product.h"
#include <stdexcept>
using namespace std;

Product::Product (int productID, string productName): productID(productID), name(productName), numSold(0), totalPaid(0), inventory(0) {}

string Product::getDescription() const {
    return description;
}

void Product::setDescription(string description) {
    this->description = description;
}

string Product::getName() const {
    return name;
}

int Product::getID() const {
    return productID;
}

int Product::getNumberSold() const {
    return numSold;
}

double Product::getTotalPaid() const {
    return totalPaid;
}

int Product::getInventoryCount() const {
    return inventory;
}

void Product::addShipment(int shipmentQuantity, double shipmentCost) {
    if (shipmentCost < 0) {
        throw runtime_error("Invalid shipmentCost.");
    }
    if (shipmentQuantity < 0) {
        throw runtime_error("Invalid shipmentQuantity.");
    }
    this->inventory = this->inventory + shipmentQuantity;
    this->totalPaid = this->totalPaid + shipmentCost;
    return;
}

void Product::reduceInventory(int purchaseQuantity) {
    if (purchaseQuantity > this->inventory) {
        throw runtime_error("There is not enough inventory.");
    }
    if (purchaseQuantity < 0) {
        throw runtime_error("Invalid purchaseQuantity.");
    }
    this->inventory = this->inventory - purchaseQuantity;
    this->numSold = this->numSold + purchaseQuantity;
}

double Product::getPrice() {
    double price;
    if (this->totalPaid == 0) {
        price = 0;
    }
    else {
        price = double(this->totalPaid)/(this->inventory + this->numSold) * 1.25;
    }
    return price;
}

bool Product::operator!=(Product& product) {
        if (this->productID == product.productID) {
            return false;
        }
        else {
            return true;
        }
}

bool Product::operator==(Product& product) {
    if (this->productID == product.productID) {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<<(ostream& os, const Product& product) {
    os << product.getName() << product.getID();
    return os;
}
