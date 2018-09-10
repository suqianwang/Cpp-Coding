
  bulls and cows-flag.cpp
  bulls and cows

  Created by Susan Wang on 3/19/17.
  Copyright © 2017 Suqian Wang. All rights reserved.


#include<stdio.h>
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

int main() {
    int x, numOfDigit, lastDigit, y, realNumOfDigit, diff, guess, lastDigGuess, temp, bulls = 0, cows = 0, flag = 0;
    vector<int> list, templist, vecGuess;
//--------------------------------------------------------------------------
    cout << "Enter number of digits in code (3, 4 or 5): " << endl;
    cin >> numOfDigit;
    while ((numOfDigit != 0) && (numOfDigit != 3) && (numOfDigit != 4) && (numOfDigit != 5)) {
        cin >> numOfDigit;
    }
    if (numOfDigit == 0) {
        cout << "Enter code: " << endl;
        cin >> x;
        cout << "Enter number of digits in code: " << endl;
        cin >> numOfDigit;
    }
    else {
        srand ((unsigned int)time(NULL));
        if (numOfDigit == 3) {
            x = rand() % 1000;
        }
        else if (numOfDigit == 4) {
            x = rand() % 10000;
        }
        else {
            x = rand() % 100000;
        }
    }
//--------------------------------------------------------------------------
    y = x;
    do {
        lastDigit = y % 10;
        templist.push_back(lastDigit);
        y = int (y / 10);
    } while(y != 0);
    realNumOfDigit = int(templist.size());
    diff = numOfDigit - realNumOfDigit;
    for (int j = diff; j > 0; --j) {
        list.push_back(0);
    }
    for (int i = realNumOfDigit - 1; i >= 0; --i) {
        list.push_back(templist.at(i));
    }
//--------------------------------------------------------------------------
    cout << "Number to guess: " << endl;
    for (int k = 0; k < list.size(); ++k) {
        cout << list.at(k);
    }
//**************************************************************************
    while (flag != -1) {
        if (flag == 1) {
        flag = 0;
        }
    while (flag == 0) {
        cout << endl << "Enter guess: " << endl;;
        cin >> guess;
    temp = guess;
    lastDigGuess = temp % 10;
    vecGuess.push_back(lastDigGuess);
    temp = temp / 10;
     do {
        lastDigGuess = temp % 10;
            if (vecGuess.size() > numOfDigit - 1) {
                cout << "You can only enter " << numOfDigit << " digits." << endl;
                flag = 1;
            }
        for (int i = 0; i < vecGuess.size(); ++i) {
            if (lastDigGuess == vecGuess.at(i)) {
                cout << "Each number mush be different." << endl;
                flag = 1;
            }
        }
        vecGuess.push_back(lastDigGuess);
        temp = int (temp / 10);
        }while(temp != 0);
    if (numOfDigit - vecGuess.size() > 1) {
        cout << "Each number mush be different.";
        flag = 1;
    }
    else if (numOfDigit - vecGuess.size() == 1) {
        vecGuess.push_back(0);
    }

    for (int i = 0; i < numOfDigit; ++i) {
        if (vecGuess.at(numOfDigit - 1 - i) == list.at(i)) {
            bulls = bulls + 1;
        }
        else {
            for (int j = 0; j < numOfDigit; ++j) {
                if (vecGuess.at(numOfDigit - 1 - i) == list.at(j)) {
                    cows = cows + 1;
                }
            }
        }
    }
    if (bulls != 4) {
        cout << bulls << "bulls" << endl;
        cout << cows << "cows" << endl;
        flag = 1;
    }
    else {
        cout << "4 bulls - ";
        for (int k = numOfDigit - 1; k >= 0; --k) {
            cout << vecGuess.at(k);
        }
        cout << " is Correct!" << endl;
        flag = -1;
    }
    }
    }
}
