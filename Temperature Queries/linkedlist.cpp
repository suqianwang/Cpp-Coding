#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr){}

LinkedList::~LinkedList() {
	// Implement this function
    this->clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function
    if (source.head == nullptr) {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        Node* temp = source.head;
        while (temp != nullptr) {
            insert(temp->content.getLocation(), temp->content.getYear(), temp->content.getMonth(), temp->content.getTemperature());
            temp = temp->next;
        }
    }
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
    if (this != &source) {
        clear();
        Node* temp = source.head;
        while (temp != nullptr) {
            insert(temp->content.getLocation(), temp->content.getYear(), temp->content.getMonth(), temp->content.getTemperature());
            temp = temp->next;
        }
    }
    return *this;
}

void LinkedList::insert(int location, int year, int month, double temperature) {
	// Implement this function
    Data newData;
    newData.setLocation(location);
    newData.setYear(year);
    newData.setMonth(month);
    newData.setTemperature(temperature);
    Node* newNode = new Node(newData);
    if (tail != nullptr)
        tail->next = newNode;
    tail = newNode;
    if (head == nullptr)
        head = newNode;
}

void LinkedList::clear() {
	// Implement this function
    Node* current = head;
    while (current != nullptr) {
        Node* deleteNode = current;
        current = current->next;
        delete deleteNode;
    }
    head = nullptr;
    tail = nullptr;
}

void LinkedList::print() const {
	/* Do not modify this function */
	print(cout);
}

void LinkedList::print(ostream& os) const {
	/* Do not modify this function */
	os << *this;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	// Implement this function
    Node* temp = ll.head;
    while (temp != nullptr) {
        os << temp->content.getLocation() << " " << temp->content.getYear() << " " << temp->content.getMonth()  << " " << temp->content.getTemperature() << endl;
        temp = temp->next;
    }
    return os;
}
