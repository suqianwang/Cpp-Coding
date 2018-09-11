//
//  mountainpaths.cpp
//  Mountain Paths
//
//  Created by Susan Wang on 4/19/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
using namespace std;

int rows, columns, data;
string filename, outfilename;
vector<vector<int>> avgElevation;

int userinput() {
    cout << "Enter the number of rows in the map: ";
    cin >> rows;
    cout << "Enter the number of columns in the map: ";
    cin >> columns;
    while (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Error." << endl;
        return 1;
    }
    cout << "Enter the name of the file containing the map data: ";
    cin >> filename;
    return 0;
}

vector<vector<int>> readData(ifstream& dataIn) {
    if (!dataIn.is_open()) {
        cerr << "Error." << endl;
    }
    vector<vector<int>> temp2dVec;
    for (int i = 0; i < rows; i++) {
        vector<int> tempVec;
        for (int j = 0; j < columns; j++) {
            dataIn >> data;
            tempVec.push_back(data);
        }
        temp2dVec.push_back(tempVec);
    }
    
    return temp2dVec;
}

void scale(vector<vector<int>>& scaledElevation) {
    int min = scaledElevation.at(0).at(0), max = scaledElevation.at(0).at(0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (scaledElevation.at(i).at(j) < min) {
                min = scaledElevation.at(i).at(j);
            }
            if (scaledElevation.at(i).at(j) > max) {
                max = scaledElevation.at(i).at(j);
            }
        }
    }
    double k = ((double)(max - min)) / 255;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            scaledElevation.at(i).at(j) = (scaledElevation.at(i).at(j) - min) / k;
        }
    }
}

vector<int> greedypathRow(int start_row, const vector<vector<int>>& heightMap) {
    int i, change1, change2, change3;
    
    vector<int> rowPosition;
    rowPosition.push_back(start_row);
    for (i = 0; i < columns - 1; ++i) {
        
        if (start_row == 0) {
            change2 = abs(heightMap.at(start_row).at(i) - heightMap.at(start_row).at(i+1));
            change3 = abs(heightMap.at(start_row).at(i) - heightMap.at(start_row+1).at(i+1));
            if (change3 < change2) {
                start_row = start_row + 1;
            }
        }
        else if (start_row == rows-1) {
            change1 = abs(heightMap.at(start_row).at(i) - heightMap.at(start_row-1).at(i+1));
            change2 = abs(heightMap.at(start_row).at(i) - heightMap.at(start_row).at(i+1));
            if (change1 < change2) {
                start_row = start_row - 1;
            }
        }
        else{
            change1 = abs(heightMap.at(start_row).at(i) - heightMap.at(start_row-1).at(i+1));
            change2 = abs(heightMap.at(start_row).at(i) - heightMap.at(start_row).at(i+1));
            change3 = abs(heightMap.at(start_row).at(i) - heightMap.at(start_row+1).at(i+1));
            if (change1 < change2) {
                if (change1 < change3) {
                    start_row = start_row - 1;
                }
                else {
                    start_row = start_row + 1;
                }
            }
            else {
                if (change2 > change3) {
                    start_row = start_row + 1;
                }
            }
        }
        rowPosition.push_back(start_row);
//        cout << start_row << endl;
    }
    return rowPosition;
}

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>&r, vector<vector<int>>&g, vector<vector<int>>&b, int color_r, int color_g, int color_b, int start_row) {
    int total = 0;

    vector<int> rowPosition = greedypathRow(start_row, heightMap);
    for (int k = 0; k < columns-1; ++k) {
        total = total + abs(heightMap.at(rowPosition.at(k)).at(k)-heightMap.at(rowPosition.at(k+1)).at(k+1));
    }

    for (int i = 0; i < columns; ++i) {
        r.at(rowPosition.at(i)).at(i) = color_r;
        g.at(rowPosition.at(i)).at(i) = color_g;
        b.at(rowPosition.at(i)).at(i) = color_b;
    }
    return total;
}

void color(const vector<vector<int>>& heightMap, vector<vector<int>>&r, vector<vector<int>>&g, vector<vector<int>>&b) {
//    for (int i = 0; i < rows; ++i) {
//        colorPath(avgElevation, r, g, b, 252, 25, 63, i);
//    }
    int mintotal = colorPath(avgElevation, r, g, b, 31, 253, 13, 0);
    int minindex = 0;
    for (int i = 1; i < rows; ++i) {
        if (colorPath(avgElevation, r, g, b, 252, 25, 63, i) < mintotal) {
            colorPath(avgElevation, r, g, b, 252, 25, 63, minindex);
            mintotal = colorPath(avgElevation, r, g, b, 31, 253, 13, i);
            minindex = i;
        }
        else {
            colorPath(avgElevation, r, g, b, 252, 25, 63, i);
            colorPath(avgElevation, r, g, b, 31, 253, 13, minindex);
        }
    }
//    cout << colorPath(avgElevation, r, g, b, 31, 253, 13, minindex);
}

//void colorPosition(vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int start_row, int start_col) {
//    r.at(start_row).at(start_col) = color_r;
//    g.at(start_row).at(start_col) = color_g;
//    b.at(start_row).at(start_col) = color_b;
//}
//
//

void outputFile(ofstream& dataOut, vector<vector<int>> r, vector<vector<int>> g, vector<vector<int>> b) {
    dataOut << "P3" << endl;
    dataOut << columns << " " << rows << endl;
    dataOut << "255" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            dataOut << r.at(i).at(j) <<" " << g.at(i).at(j) << " " << b.at(i).at(j) << " ";
        }
    }
}

int main() {
    
    userinput();
    
    ifstream dataIn = ifstream(filename);
    avgElevation = readData(dataIn);
    
    vector< vector<int> > scaledElevation = avgElevation;
    scale(scaledElevation);
    
    vector<vector<int>> r = scaledElevation, g = scaledElevation, b = scaledElevation;
    color(avgElevation, r, g, b);
    
//    int ec_row = 164, ec_column = 388;
////    cout << "Enter any row and column: ";
////    cin >> ec_row >> ec_column;
////    if(cin >> ec_row >> ec_column) {
//        colorPath(avgElevation, r, g, b, 19, 254, 253, ec_row, ec_column);
////    }

    
//    cout << "save file now" << endl;
    
    outfilename = filename.append(".dat.ppm");
    ofstream dataOut = ofstream(outfilename);
    outputFile(dataOut, r, g, b);
}
