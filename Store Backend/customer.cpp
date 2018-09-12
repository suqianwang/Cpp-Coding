//
//  customer.cpp
//  StoreBackend
//
//  Created by Susan Wang on 3/26/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include "customer.h"
#include <stdexcept>
using namespace std;

Customer::Customer(string customerName, int customerID, bool credit): name(customerName), customerID(customerID), credit(credit), balance(0) {}

string Customer::getName() const{
    return this->name;
}

void Customer::setName(string name) {
    this->name = name;
}

int Customer::getID() const{
    return this->customerID;
}

bool Customer::getCredit() const{
    return this->credit;
}

void Customer::setCredit(bool hasCredit) {
    this->credit = hasCredit;
}

double Customer::getBalance() const{
    return this->balance;
}

void Customer::processPayment(double amount) {
    if (amount < 0) {
        throw runtime_error("Invalid amount.");
    }
    this->balance = this->balance + amount;
}

void Customer::processPurchase(double amount, Product product) {
    if (amount > 0) {
        if (this->credit) {
            this->balance = this->balance - amount;
            if (this->productsPurchased.size() == 0)
                (this->productsPurchased).push_back(product);
            else {
            for (int i = 0; i < (this->productsPurchased).size(); ++i) {
                if ((this->productsPurchased).at(i) != product) {
                    (this->productsPurchased).push_back(product);
                }
            }
            }
        }
        else {
            if (this->balance >= amount) {
                this->balance = this->balance - amount;
                if (this->productsPurchased.size() == 0)
                    (this->productsPurchased).push_back(product);
                else {
                    for (int i = 0; i < (this->productsPurchased).size(); ++i) {
                        if ((this->productsPurchased).at(i) != product) {
                            (this->productsPurchased).push_back(product);
                        }
                    }
                }
            }
            else {
                throw runtime_error("Balance is not allowed to be negative if you do not have credit.");
            }
        }
    }
    else if (amount < 0) {
        throw runtime_error("Invalid amount.");
    }
}

void Customer::listProductsPurchased(ostream& os) {
    for (int i = 0; i < (this->productsPurchased).size(); ++i)
        os << this->productsPurchased.at(i);
}

bool Customer::operator!=(Customer& customer) {
    if (this->customerID == customer.customerID) {
        return (this->name == customer.name);
    }
    else {
        return false;
    }
}

bool Customer::operator==(Customer& customer) {
    if (this->customerID == customer.customerID) {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<<(ostream& os, const Customer& customer) {
    os << customer.getName() << customer.getID();
    return os;
}
