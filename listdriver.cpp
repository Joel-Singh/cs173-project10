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

	cout << "Insert at beginning of empty list" << endl;
	List<int> list3;
	list3.insert(99, 0);
	cout << "Expected: [ 99 ]" << endl;
	cout << "Actual: " << list3 << endl;
	cout << endl;

	cout << "Insert at beginning of non-empty list" << endl;
	List<int> list4;
	list4.insert(99, 0);
	list4.insert(99, 0);
	cout << "Expected: [ 99, 99 ]" << endl;
	cout << "Actual: " << list4 << endl;
	cout << endl;

	cout << "Insert in the middle of a list" << endl;
	List<string> list5;
	list5.append("Begin");
	list5.append("End");
	list5.insert("Middle", 1);
	cout << "Expected: [ Begin, Middle, End ]" << endl;
	cout << "Actual: " << list5 << endl;
	cout << endl;

	cout << "Insert in the middle of a list with index > 1" << endl;
	List<string> list6;
	list6.append("Begin");
	list6.append("Middle");
	list6.append("End");
	list6.insert("New node", 2);
	cout << "Expected: [ Begin, Middle, New node, End ]" << endl;
	cout << "Actual: " << list6 << endl;
	cout << endl;
	
	cout << "Insert in the middle of a list" << endl;
	List<int> list7;
	list7.append(0);
	list7.append(1);
	list7.append(2);
	list7.append(3);
	list7.append(4);
	list7.append(5);
	list7.append(6);
	list7.append(7);
	list7.insert(99, 5);
	cout << "Expected: [ 0, 1, 2, 3, 4, 99, 5, 6, 7 ]" << endl;
	cout << "Actual:   " << list7 << endl;
	cout << endl;

	cout << "Insert at invalid lower index throws error" << endl;
	List<int> list8;
	cout << "Expected output: Thrown error" << endl;
	cout << "Actual output: ";
	try {
		list8.insert(99, -1);
		cout << "Not thrown error" << endl;
	} catch (...) {
		cout << "Thrown error" << endl;
	}
	cout << endl;

	cout << "Insert at invalid higher index throws error" << endl;
	List<int> list9;
	list9.append(0);
	list9.append(0);
	list9.append(0);
	list9.append(0);
	cout << "Expected output: Thrown error" << endl;
	cout << "Actual output: ";
	try {
		list9.insert(99, 5);
		cout << "Not thrown error" << endl;
	} catch (...) {
		cout << "Thrown error" << endl;
	}
	cout << endl;

	cout << "Insert at the end of the list" << endl;
	List<int> list10;
	list10.append(0);
	list10.append(1);
	list10.append(2);
	list10.append(3);
	cout << "Expected: [ 0, 1, 2, 3, 99 ]" << endl;
	list10.insert(99, 4);
	cout << "Actual: " << list10 << endl;
	cout << endl;
}

