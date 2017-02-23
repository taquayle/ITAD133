/*
	Part 2 
	Separate Compilation for NumDays Class 
	Modify the program for NumDays Class to use separate compilation. Put class 
	definition in a .h file. Place the implementations in a separate .cpp file. Place main() in 
	the third file. Compile and run your program. 
*/

//Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
#include "numDays.h"
using namespace std;





int main()
{
	numDays dayOne(24), dayTwo(23);

	cout << "Day One: " << dayOne << "Day Two: " << dayTwo;

	numDays postFix = dayOne++;
	numDays preFix = ++dayOne;
	cout << "\nPostFix Inc:\t" << postFix << "PreFix Inc:\t" << preFix;

	postFix = dayOne--;
	preFix = --dayOne;
	cout << "\nPostFix Dec:\t" << postFix << "PreFix Dec:\t" << preFix;
	
	numDays dayAddition = dayOne + dayTwo;
	cout <<"\n\nAddition (DayOne + DayTwo):\t" << dayAddition;
	
	numDays daySubtraction = dayOne - dayTwo;
	cout <<"\nSubtraction (DayOne - DayTwo):\t" << daySubtraction;
	

	cout << boolalpha; // Boolalapha displays True/False instead of 1/0 for bool outputs
	
	cout << "\n\nGreater Than (DayOne > DayTwo):\t" << (dayOne > dayTwo);
	cout << "\nLess Than (DayOne < DayTwo):\t" << (dayOne < dayTwo);
	cout << "\nEqual to (DayOne == DayTwo):\t" << (dayOne == dayTwo);

	cout << endl << endl;
	system("pause");
}


