
/* This program is designed for asking a user for his name, year of birth and height, and calculate his average annual growth as output  */
//
//  annual_growth.cpp
//  Annual Growth
//
//  Created by Susan Wang on 2/7/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName;
    string lastName;
    int birthYear = 0;
    double heightInFeet = 0.0;
    double heightInInches = 0.0;
    int age = 0;
    double heightInCentimeters = 0.0;
    double avgAnnualGrowth = 0.0;
    
    cout << "Please enter youe first name: ";
    cin  >> firstName;
    cout << "Please enter your last name: ";
    cin >> lastName;
    cout << "Please enter your birth year: ";
    cin >> birthYear;
    cout << "Please enter your height in feet: ";
    cin >> heightInFeet;
    cout << "Please enter your height in inches: ";
    cin >> heightInInches;
    
    int CURRENT_YEAR = 2017;
    double HEIGHT_AT_BIRTH = 51;    // unit: centimeter
    
    age = CURRENT_YEAR - birthYear;
    heightInCentimeters = 2.54 * heightInInches + 2.54 * 12 * heightInFeet;
    avgAnnualGrowth = (heightInCentimeters - HEIGHT_AT_BIRTH) / age;
    
    cout << endl << "Hello " << firstName << " " << lastName << ". " ;
    cout << "You are " << age << " years old in " << CURRENT_YEAR << ", ";
    cout << "and your height is " << heightInCentimeters << " cm. ";
    cout << "That means that you grew an average of " << avgAnnualGrowth << " cm per year " ;
    cout << "(assuming you were " << HEIGHT_AT_BIRTH << " cm at birth)." << endl;
    return 0;
}
