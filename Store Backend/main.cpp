//
//  main.cpp
//  StoreBackend
//
//  Created by Susan Wang on 4/6/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "customer.h"
#include "product.h"
#include "store.h"

int main() {
    
    Store store("Kroger");
    int customerID = 1729;
    string name = "Michael Morre";
    bool has_credit = true;
    
    store.addCustomer(customerID, name);
    
    int customerID2 = 1735;
    name = "Yao Ming";
    has_credit = true;
    
    store.addCustomer(customerID2, name);
    return 0;
}
