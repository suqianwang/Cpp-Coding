#ifndef NODE
#define NODE

// Include the header file for the data struct/class if you use one.
// For example, if you have a data class in data.h, put
//  #include "data.h"
// below.
#include "data.h"

struct Node {
	// Add your member variable for the data fields here.
	// You can use an extra struct/class for storing the data. In that case, put
	// your definition of the data class in a separate header file, for example:
	// data.h
    Data content;

	// Pointer to the next node in the linked list
	Node* next;

	// Default constructor
	Node() : next(nullptr) {
		// Initialize your data members properly inside the function body
	}

	Node(Data data) : next(nullptr) {
		// Initialize your data members properly inside the function body
        content.setLocation(data.getLocation());
        content.setYear(data.getYear());
        content.setMonth(data.getMonth());
        content.setTemperature(data.getTemperature());
	}

  // The function below is written. Do not modify it
	virtual ~Node() {}
};

#endif
