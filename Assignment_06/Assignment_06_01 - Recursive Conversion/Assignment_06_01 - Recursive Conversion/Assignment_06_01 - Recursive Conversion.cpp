// Assignment_06_01 - Recursive Conversion.cpp : Defines the entry point for the console application.
/*
	Recursive conversion 
	
	Convert the following function into a one that usesrecursion. 
	
	void sign(int n) 
	{ 
		while(n-->0) 
		  cout << "No Parking \n"; 
	} 
	Demonstrate function with the driver program.
*/

// Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
using namespace std;


void rSign(int);

int main()
{
	rSign(10);

	system("pause");
	return 0;
}

void rSign(int n) 
{ 
	cout << "No Parking \n"; 
	if(--n) rSign(n);
} 