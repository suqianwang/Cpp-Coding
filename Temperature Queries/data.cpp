//
//  data.cpp
//  Temperature Queries
//
//  Created by Susan Wang on 4/19/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "data.h"
using namespace std;

Data::Data():location(0), year(0), month(0), temperature(-99.99) {}

Data::Data(int location, int year, int month, double temperature): location(location), year(year), month(month), temperature(temperature) {}

void Data::setLocation(int location) {
    this->location = location;
}

int Data::getLocation() const {
    return this->location;
}

void Data::setYear(int year) {
    this->year = year;
}

int Data::getYear() const {
    return this->year;
}

void Data::setMonth(int month) {
    this->month = month;
}

int Data::getMonth() const {
    return this->month;
}

void Data::setTemperature(double temperature) {
    this->temperature = temperature;
}

double Data::getTemperature() const {
    return this->temperature;
}

