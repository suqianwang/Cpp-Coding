//
//  functions.cpp
//  palindrome
//
//  Created by Susan Wang on 3/17/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <cctype>
#include <ctype.h>
#include "functions.h"
using namespace std;

void printUsageInfo(string inputStr) {
    cout << "Usage: " << inputStr << " [-c] [-s] string ..." << endl;
    cout << "-c: case sensitivity turned on" << endl;
    cout << "-s: ignoring spaces turned off" << endl;
}

string preprocessString(string inputStr, bool isCase, bool isSpace) {
    for (int i = 0; i < inputStr.length(); ++i) {
        if (ispunct(inputStr.at(i)) && !isspace(inputStr.at(i))) {
            inputStr.erase(i, 1);
            i = i - 1;
        }
    }
    if (!isCase) {
        for (int i = 0; i < inputStr.length(); ++i) {
            inputStr.at(i) = tolower(inputStr.at(i));
        }
    }
    if (!isSpace) {
        for (int i = 0; i < inputStr.length(); ++i) {
//            inputStr.erase(remove(inputStr.begin(), inputStr.end(), ' '), inputStr.end());
//            if (inputStr.find(" ", i) == i || inputStr.find(";", i) == i ||inputStr.find("?", i) == i || inputStr.find("!", i) == i || inputStr.find(":", i) == i || inputStr.find(".", i) == i) {
//                inputStr.erase(i, 1);
//                i  = i - 1;
//            }
            if (isspace(inputStr.at(i))) {
                inputStr.erase(i, 1);
                i = i - 1;
            }
        }
    }
    return inputStr;
}

bool isPalindrome(string inputStr, bool isCase, bool isSpace) {
    string proStr;
    proStr = preprocessString(inputStr, isCase, isSpace);
    string first = proStr.substr(0,1);
    string last = proStr.substr((proStr.length()-1),1);
    
    if (first == last) {
        proStr = proStr.substr(1, (proStr.length()-2));
        if (proStr.length() <= 1) {
            return true;
        }
        return isPalindrome(proStr, isCase, isSpace);
    }
    else {
        return false;
    }
}

void printResult (bool palindrome, string inputStr) {
    if (palindrome) {
        cout << "\"" << inputStr << "\"" << " is a palindrome." << endl;
    }
    else {
        cout << "\"" << inputStr << "\"" << " is not a palindrome." << endl;
    }
}
