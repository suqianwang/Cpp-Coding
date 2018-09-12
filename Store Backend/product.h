//
//  product.h
//  StoreBackend
//
//  Created by Susan Wang on 3/26/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#ifndef product_h
#define product_h

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Product {
public:
    Product (int productID, string productName);
    string getDescription() const;
    void setDescription(string description);
    string getName() const;
    int getID() const;
    int getNumberSold() const;
    double getTotalPaid() const;
    int getInventoryCount() const;
    void addShipment(int shipmentQuantity, double shipmentCost);
    void reduceInventory(int purchaseQuantity);
    double getPrice();
    bool operator!=(Product& product);
    bool operator==(Product& product);
private:
    int productID;
    string name;
    string description;
    int inventory;
    int numSold;
    double totalPaid;
};
ostream& operator<<(ostream& os, const Product& product);
#endif /* product_h */
