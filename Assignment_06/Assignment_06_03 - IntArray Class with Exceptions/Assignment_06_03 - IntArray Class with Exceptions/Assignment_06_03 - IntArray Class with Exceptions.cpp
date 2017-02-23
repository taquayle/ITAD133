// Assignment_06_03 - IntArray Class with Exceptions.cpp : Defines the entry point for the console application.
/*
	IntArray Class with Exceptions 

	1.  Modify the definition of the IntArray class (code provided in IntArray.cpp file), 
		so it has an exception class OutOfRange defined in the public section.The 
		exception class should have a private int member and a private string member. It 
		should have a public constructor that has int and string arguments, and a set of 
		accessor functions. 

	2.  Modify the implementation of operator [] of the IntArray class so it throws 
		exceptions of type OutOfRange instead of calling subscriptError() function when
		index is out of range. The offending index value along with a message should be 
		stored in the exception object. Choose the appropriate message to describe the 
		situation. 

	3.  Test your code. Write a small driver program that gets an array index from the 
		user and calls [] operator with that index in the try block. Write a catch block that 
		catches exceptions of type OutOfRange, and outputs appropriate messages on the 
		screen. 

	4.  Test-run your code, calling [] operator with an invalid index, one that is out of 
		range for the array in your code 
			•  example: table[-5]

	See whether the exceptions is being thrown and caught. 
*/

// Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;




class IntArray 
{
private:
	int *aptr;                     // Pointer to the array
	int arraySize;                 // Holds the array size
  
public:
	IntArray(int);                 // Constructor
	IntArray(const IntArray &);    // Copy constructor
	~IntArray();                   // Destructor
	class OutOfRange
	{	
	private:
		string eString;
		int eInt;
	public:
		OutOfRange() { eString = "Error"; eInt = 0; }
		OutOfRange(string _eString, int _eInt) { eString = _eString; eInt = _eInt; }

		int getExceptionInt() { return eInt; }
		void setExceptionInt(int _eInt) { eInt = _eInt; }

		string getExceptionString() { return eString; }
		void setExceptionString(string _eString) { eString = _eString; }
	};

	int size() const               // Returns the array size
      { return arraySize; }

	int &operator[](const int &);  // Overloaded [] operator
};


//*******************************************************
// Constructor for IntArray class. Sets the size of the *
// array and allocates memory for it.                   *
//*******************************************************

IntArray::IntArray(int s)
{
   arraySize = s;
   aptr = new int [s];
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//******************************************************
// Copy Constructor for IntArray class.                *
//******************************************************

IntArray::IntArray(const IntArray &obj)
{
   arraySize = obj.arraySize;
   aptr = new int [arraySize];
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//******************************************************
// Destructor for IntArray class.                      *
//******************************************************

IntArray::~IntArray()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

int &IntArray::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
	   throw OutOfRange("\n\nError: Trying to access array out of bounds at: ", sub);
   return aptr[sub];
}

int main()
{

	int temp;
	cout << "Please enter a size for the array: ";
	cin >> temp;
	
	const int SIZE = temp;  // Array size
	srand(time(NULL));
	
	// Define an IntArray of SIZE
	IntArray table(SIZE);

	// Store values in the array.
	for (int x = 0; x < SIZE; x++)
	table[x] = x;
	
	try
	{
		if(!temp) cout << "Nice try, but array cannot be 0";
		// SIDENOTE: Got bored so decided to make the checking a bit more fun
		while(temp){ cout << "\nChecking Array at: " << table[(rand() % SIZE) - rand() % (SIZE*-1)/2]; }
	}
	catch(IntArray :: OutOfRange e)
	{
		cout << e.getExceptionString() << e.getExceptionInt();
	}

	cout << endl;
   
	system("pause");
	return 0;
}