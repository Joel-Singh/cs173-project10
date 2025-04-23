//==============================================================
// Joel Singh
// April 22nd
// List.cpp
// This file contains the class method definitions for
// the List class.
//==============================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

//================================================= 
// Default constructor
// Creates an empty list where head points to nullptr
// Parameters:
//  None 
//================================================= 
template <typename T>
List<T>::List() {
	head = nullptr;
}

//==============================================================
// copy constructor
//==============================================================

//================================================= 
// Destructor
// Cleans up the memory of the list, deleting every node
// Parameters:
//  None 
//================================================= 
template <typename T>
List<T>::~List() {
}

//==============================================================
// operator=
//==============================================================

//================================================= 
// Append
// Appends an element to the back of the list
// Parameters:
//  item: The element to append 
// Return Value:
//  Void
//================================================= 
template <typename T>
void List<T>::append(const T& item) {
	Node* n = new Node;

	n->item = item;
	n->next = nullptr;

	Node* last = head;
	if (last == nullptr) {
		head = n;
		return;
	}

	while (last->next != nullptr) {
		last = last->next;
	}

	last->next = n;
}

//==============================================================
// insert  ( item, position )
//==============================================================

//==============================================================
// length
//==============================================================

//==============================================================
// operator[]
// Valid indices are 0 to size-1.   Invalid indices generate
// a run-time error and end the program.
//==============================================================

//==============================================================
// remove
// Valid indices are 0 to size-1.   Invalid indices generate
// a run-time error and end the program.
//==============================================================

//================================================= 
// isEmpty
// Returns false if list is empty, true otherwise
// Parameters:
//  None 
// Return Value:
//  Bool, whether or not the list is empty
//================================================= 
template <typename T>
bool List<T>::isEmpty() const {
	return head == nullptr;
}

//==============================================================
// operator+  (concatenate two lists)
//==============================================================

//==============================================================
// clear
//==============================================================

