//
//  palindromes.cpp
//  palindrome
//
//  Created by Susan Wang on 3/17/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "functions.h"
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    string programname = argv[0];
    bool isSpace = 0;
    bool isCase = 0;
    if (argc == 0) {
        printUsageInfo(programname);
        return 0;
    }
        vector<string> inputStrVec;
        for (int i = 1; i < argc; ++i) {
            string temp = argv[i];
            if (temp.at(0) == '-') {
                if (temp.find('c')!=string::npos || temp.find('C')!=string::npos) {
                    isCase = 1;
                }
                if (temp.find('s')!=string::npos || temp.find('S')!=string::npos) {
                    isSpace = 1;
                }
            }
            else {
                inputStrVec.push_back(temp);
            }
        }
        if (inputStrVec.size() == 0) {
            printUsageInfo(programname);
            return 1;
        }
            for (int k = 0; k < inputStrVec.size(); ++k) {
                string preprocessedStr = preprocessString(inputStrVec.at(k), isCase, isSpace);
                bool palindrome = isPalindrome(preprocessedStr, isCase, isSpace);
                printResult(palindrome, inputStrVec.at(k));
            }
            return 0;


}
