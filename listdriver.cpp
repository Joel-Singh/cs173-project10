//========================================================
// CS 173
// Fall 2024
// listdriver.cpp
// This file tests the List class.
//========================================================

#include <iostream>
#include "List.h"

int main ( void )
{
	List<int> list1;
	cout << "isEmpty should be true" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual: " << list1.isEmpty() << endl;
	cout << endl;
}

