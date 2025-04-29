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

//================================================= 
// Copy constructor
// Copies one list from another
// Parameters:
//  mylist: The other list 
//================================================= 
template <typename T>
List<T>::List(const List<T>& mylist) {
	head = nullptr;

	for (int i = 0; i < mylist.length(); i++) {
		this->append(mylist[i]);
	}
};

//================================================= 
// Destructor
// Cleans up the memory of the list, deleting every node
// Parameters:
//  None 
//================================================= 
template <typename T>
List<T>::~List() {
	clear();
}

//================================================= 
// Assignment operator
// Assigns one list to another
// Parameters:
//  mylist: The list to copy 
// Return Value:
//  *this
//================================================= 
template <typename T>
List<T> List<T>::operator=(const List<T>& mylist) {
	Node* next = head;
	while (next != nullptr) {
		next = head->next;
		delete head;
		head = next;
	}

	for (int i = 0; i < mylist.length(); i++) {
		this->append(mylist[i]);
	}

	return *this;
};

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

//================================================= 
// insert
// Inserts a new value at the specified position. Valid indices are 0..length. A runtime error is generated for invalid indexes.
// Parameters:
//  item: The item to insert 
//  index: The index to insert at, index=length is like append
// Return Value:
//  Void
//================================================= 
template <typename T>
void List<T>::insert(const T& item, int index) {
	if (index < 0) {
		throw runtime_error("Invalid index");
	}

	Node* n = new Node;
	n->item = item;
	n->next = nullptr;

	// Empty list
	if (head == nullptr) { 
		head = n;
		return;
	}

	// Beginning of the list
	if (index == 0) {
		n->next = head;
		head = n;
		return;
	}

	Node* ptr = head;
	for (int i = 0; i < (index-1); i++) {
		ptr = ptr->next;
		// Invalid higher index
		if (ptr == nullptr) {
			throw runtime_error("Invalid index");
		}
	}

	// End of the list
	if (ptr->next == nullptr) {
		ptr->next = n;
		return;
	}

	// Middle of the list
	n->next = ptr->next;
	ptr->next = n;
}

//================================================= 
// length
// Returns the length of the list
// Parameters:
//  None 
// Return Value:
//  Integer, the length of a list
//================================================= 
template <typename T>
int List<T>::length() const {
	int len = 0;
	Node* ptr = head;
	while (ptr != nullptr) {
		len++;
		ptr = ptr->next;
	}

	return len;
};


//==============================================================
// operator[]
// Valid indices are 0 to size-1.   Invalid indices generate
// a run-time error and end the program.
//==============================================================
template <typename T>
T& List<T>::operator[](int index) const {
	if (index < 0)	{
		throw runtime_error("Invalid index");
	} else if (head == nullptr) {
		throw runtime_error("Can't access empty list");
	}

	Node* ptr = head;
	for (int i = 0; i < index; i++) {
		ptr = ptr->next;
	}

	return ptr->item;
};

//================================================= 
// remove
// Removes an element. Valid indices are 0 to size-1. Invalid indices generate
// a run-time error and end the program.
// Parameters:
//  index: The indice to remove 
// Return Value:
//  Void
//================================================= 
template <typename T>
void List<T>::remove(int index) {
	if (index < 0) {
		throw runtime_error("Can't remove from a negative indice");
	}

	if (head == nullptr) {
		throw runtime_error("Can't remove from empty list");
	}

	// Single element list
	if (index == 0 && head->next == nullptr) {
		head = nullptr;
		return;
	}

	// Beginning of list
	if (index == 0) {
		head = head->next;
		return;
	}

	Node* ptr = head;
	for (int i = 0; i < (index-1); i++) {
		if (ptr->next == nullptr) {
			throw runtime_error("Invalid index");
		}
		ptr = ptr->next;
	}
	if (ptr->next == nullptr) {
		throw runtime_error("Invalid index");
	}
	ptr->next = ptr->next->next;
}


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

//================================================= 
// Concatentation operator
// Concatenate 2 lists with the plus
// Parameters:
//  mylist: The list to concatenate with this 
// Return Value:
//  Concatenated list
//================================================= 
template <typename T>
List<T> List<T>::operator+(const List<T>& mylist) const {
	List a(mylist);
	List b(*this);

	for (int i = 0; i < b.length(); i++) {
		a.append(b[i]);
	}

	return a;
};


//================================================= 
// clear
// Clears the list, leaving it empty
// Parameters:
//  None 
// Return Value:
//  Void
//================================================= 
template <typename T>
void List<T>::clear() {
	Node* next = head;
	while (next != nullptr) {
		next = head->next;
		delete head;
		head = next;
	}

	head = nullptr;
};

