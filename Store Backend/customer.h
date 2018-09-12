//
//  customer.h
//  StoreBackend
//
//  Created by Susan Wang on 3/26/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#ifndef customer_h
#define customer_h

#include <stdio.h>
#include <string>
#include <vector>
#include "product.h"
#include <iostream>
using namespace std;

class Customer {
public:
    Customer(string customerName, int customerID, bool credit);
    string getName()const;
    void setName(string name);
    int getID()const;
    bool getCredit()const;
    void setCredit(bool hasCredit);
    double getBalance()const;
    void processPayment(double amount);
    void processPurchase(double amount, Product product);
    void listProductsPurchased(ostream& os);
    bool operator!=(Customer& customer);
    bool operator==(Customer& customer);
private:
    int customerID;
    string name;
    bool credit;
    double balance;
    vector<Product> productsPurchased;
};
ostream& operator<<(ostream& os, const Customer& customer);

#endif /* customer_h */
