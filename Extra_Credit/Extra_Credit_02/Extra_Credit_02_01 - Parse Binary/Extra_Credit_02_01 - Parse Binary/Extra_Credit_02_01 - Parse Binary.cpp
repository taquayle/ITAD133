// Extra_Credit_02_01 - Parse Binary.cpp : Defines the entry point for the console application.
/*
	parseBinary() function 
	
	Write a function that parses a binary number as a string into a decimal integer. 

	The function header is as follows: int parseBinary(char* binaryString) 
		
	For example, binary string 10001 is 17: 
	1*2^4 + 0*2^3 + 0*2^2 + 0*2^1 + 1*2^0
	So, parseBinary(“10001”)returns 17. 
	
	Make parseBinary()function throw an exception of type integer (like -1) in 
	case if the string that is being parsed is not a binary number (contains characters 
	other that 0 or1). 
  
	In main() ask the user to enter a binary number, pass the string given by the user 
	into the function. Surround parseBinary()function calls with try block. 
	Write catch block that catches exceptions of type integer. Test-run the code on 
	binary strings of different length. Make sure the exception is being thrown and 
	caught. 
*/

// Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int parseBinary(char*);

int main()
{
	char *userString = new char[];

	cout << "Please enter a binary number: ";
	cin >> userString;
	
	try { cout << "\n Converted to binary: "  << parseBinary(userString) << "\n"; }

	catch (int) { cout << "String contained characters other than 0 or 1\n"; }
	
	system("pause");
	return 0;
}

int parseBinary(char* binaryString)
{
	int binaryAddition = 0;
	int strLength = strlen(binaryString);
	for(int i = 0; i < strLength; i++)
	{
		if(*(binaryString+i) == '1')
			binaryAddition += pow(2, (strLength-i)-1);
		if(*(binaryString+i) != '1' && *(binaryString+i) != '0'){throw -1;}
	}
	return binaryAddition;
}
