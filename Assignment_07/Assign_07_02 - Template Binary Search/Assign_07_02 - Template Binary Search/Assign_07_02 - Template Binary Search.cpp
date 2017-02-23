// Assign_07_02 - Template Binary Search.cpp : Defines the entry point for the console application.
/*
	Template Iterative Binary Search 

	Write a template version of the iterative binary search (code provided). In the comments 
	next to the template definition specify requirements on the template parameter type. 
	Include additional code in main that tests your newtemplate to work well not only for 
	integers, but for characters too. 
*/

// Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
using namespace std;
const int ARRAY_SIZE = 10;


template <typename t, typename b>
void search(t a[], t , t, t, b& , t& );
//Precondition: a[lowEnd] through a[highEnd] are sorted in increasing 
//order.
//Postcondition: If key is not one of the values a[lowEnd] through 
//a[highEnd], then found == false; otherwise a[location] == key and 
//found == true.
int main( )
{
    int a[ARRAY_SIZE];
    const int finalIndex = ARRAY_SIZE - 1;

    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        a[i] = 3*i;
    cout << "Array conatins:\n";
    for (i = 0; i < ARRAY_SIZE; i++)
        cout << a[i] << " ";
    cout << endl;

    int key, location;
    bool found;
    cout << "Enter number to be located: ";
    cin >> key;
    search(a, 0, finalIndex, key, found, location);

    if (found)
        cout << key << " is in index location "
             << location << endl;
    else
        cout << key << " is not in the array." << endl;

	system("pause"
		);
    return 0;
}

template <typename t, typename b>
void search(t a[], t lowEnd, t highEnd, t key, b& found, t& location)
{
    int first = lowEnd;
    int last = highEnd;
    int mid;

    found = false;//so far
    while ( (first <= last) && !(found) )
    {
        mid = (first + last)/2;
        if (key == a[mid])
        {
            found = true;
            location = mid;
        }
        else if (key < a[mid])
        {
            last = mid - 1;
        }
        else if (key > a[mid])
        {
            first = mid + 1;
        }
    }
}


