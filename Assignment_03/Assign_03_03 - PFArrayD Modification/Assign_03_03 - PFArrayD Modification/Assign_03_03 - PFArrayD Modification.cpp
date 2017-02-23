/*
	PFArrayD Modification 

	Start with the source code of the PFArrayD class. Modify the program to use namespaces 
	and separate compilation. Put class definition and other function declarations in one file. 
	Place the implementations in a separate file. Placethe demonstration program in a third 
	file. 
	
	Create a namespace for the PFArrayD class. Distribute the namespace definition across 
	two files: header and implementation. 
	
	To provide access to names in namespaces, you may use local “using” declarations such as: 
	
	using std::cout; 
	
	or qualify names using the names of namespaces, such as: 
	
	std::cout.
	
	You may not use global namespace directives (such as using namespace std;) which are 
	not in block and apply to the entire file. 
*/

// Tyler Quayle - SIN: 950416426
#include "stdafx.h"
//Program to demonstrate the class PFArrayD.
#include <iostream>
#include "PFArrayD.h";
using std::cout;
using std::cin;
using std::endl;
using PF_D :: PFArrayD;
//Objects of this class are partially filled arrays of doubles.


void testPFArrayD( );
//Conducts one test of the class PFArrayD.

int main( )
{
    cout << "This program tests the class PFArrayD.\n";

    char ans;
    do
    {
        testPFArrayD( );
        cout << "Test again? (y/n) ";
        cin >> ans;
    }while ((ans == 'y') || (ans == 'Y'));

    return 0;
}

void testPFArrayD( )
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
 
    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
        temp.addElement(next);
        cin >> next;
    }

    cout << "You entered the following " 
         << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}
