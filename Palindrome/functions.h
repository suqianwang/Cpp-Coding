//
//  functions.h
//  palindrome
//
//  Created by Susan Wang on 3/17/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <cctype>
#include <ctype.h>
using namespace std;

void printUsageInfo(string inputStr);
string preprocessString(string inputStr, bool isCase, bool isSpace);
bool isPalindrome(string inputStr, bool isCase, bool isSpace);
void printResult (bool palindrome, string inputStr);

#endif /* functions_h */
