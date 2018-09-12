//
//  store.h
//  StoreBackend
//
//  Created by Susan Wang on 3/31/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#ifndef store_h
#define store_h

#include <stdio.h>
#include <string>
#include "product.h"
#include "customer.h"
using namespace std;

class Store {
public:
    Store();
    Store(string name);
    string getName() const;
    void setName(string name);
    void addProduct(int productID, string productName);
    void addCustomer(int customerID, string customerName, bool credit = true);
    Product& getProduct(int productID);
    Customer& getCustomer(int customerID);
    void takeShipment(int productID, int quantity, double cost);
    void makePurchase(int customerID, int productID, int quantity);
    void takePayment(int customerID, double amount);
    void listProducts(ostream& os);
    void listCustomers(ostream& os);
private:
    vector<Product> products;
    vector<Customer> customers;
    string name;
};


#endif /* store_h */
