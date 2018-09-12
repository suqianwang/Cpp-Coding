#include "temperaturedb.h"

#include <fstream>
using namespace std;

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function
    ifstream inFile(filename);
    while (!inFile.eof()) {
        inFile >> 
    }
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function
}
