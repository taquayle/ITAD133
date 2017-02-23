// Assign_07_03 - NumberList.cpp : Defines the entry point for the console application.
/*
	NumberList Functions 

	Modify the NumberListclass (provided) to include two new member functions: 

	1.  Function search should search the list for a specific value. If the value is 
	found, function should return the number of the element in the list that holds the 
	value. Start counting elements from 0. If the valueis not found, the function 
	should return -1. Demonstrate the function in a driver program. 
	 
	 Function header: int NumberList :: search(int key) 
	Example: 
		Given the list 2 -> 7 -> 1 -> 7 -> 12 -> 7 
		int n= list.search(1);// n holds 2 now 
		n= list.search(15);// n holds -1 now   

	2.  Function deleteDuplicates should scan the linked list and delete all 
	duplicates of the given value in the list. Only one element with the given value 
	should be left in the list. Do not assume that the list is sorted. If there was no 
	duplicates of the given value (or no such value found), the list should stay 
	unchanged. 
	 Function header: void NumberList ::deleteDuplicates(int key)
	
		Example: 
			list: 2 -> 7 -> 1 -> 7 -> 12 -> 7 
			function call: list.deleteDuplicatest(7); 
			list after function call : 2 -> 7 -> 1 -> 12 
	 Demonstrate the function in a driver program. 
	
	Requirement:Do not call deleteNodemember function in your function implementation. 
*/

#include "stdafx.h"
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
   // Define a NumberList object.
   NumberList list;

   // Build the list with some values.
   list.appendNode(2);
   list.appendNode(7);
   list.appendNode(1);
   list.appendNode(7);
   list.appendNode(12);
   list.appendNode(7);
   list.appendNode(12);
   list.appendNode(2);
   list.appendNode(9);
   
   // Display the list.
   cout << "Here are the initial values:\n";
   list.displayList();
   cout << endl;
   cout << "\nSearch for 15, index @: " << list.search(15);
   cout << "\nSearch for 1, index @: " << list.search(1);
   cout << "\nSearch for 9, index @: " << list.search(9);

   cout << "\n\nDelete all duplicate elements with value 7\n";
   list.deleteDuplicates(7);
   list.displayList();

   cout << "\n\nDelete all duplicate elements with value 12\n";
   list.deleteDuplicates(12);
   list.displayList();

   cout << "\n\nDelete all duplicate elements with value 2\n";
   list.deleteDuplicates(2);
   list.displayList();

   cout << "\n\nSearch for 9, index @: " << list.search(9);
   cout << endl << endl;
   system("pause");
   return 0;
}