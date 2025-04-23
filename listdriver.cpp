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

	cout << "Append appends an item" << endl;
	List<int> list2;
	list2.append(0);
	cout << "Expected: [ 0 ]" << endl;
	cout << "Actual: " << list2 << endl;
	cout << endl;

	cout << "Append twice appends two items" << endl;
	list2.append(1);
	cout << "Expected: [ 0, 1 ]" << endl;
	cout << "Actual: " << list2 << endl;
	cout << endl;

	cout << "Append thrice appends three items" << endl;
	list2.append(2);
	cout << "Expected: [ 0, 1, 2 ]" << endl;
	cout << "Actual: " << list2 << endl;
	cout << endl;

}

