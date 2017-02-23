// Assign_08_01 - DynIntStack.cpp : Defines the entry point for the console application.
/*
	Stack Class Improvements 

	Make two improvements to the DynIntStackclass (provided): 
		
		1.  Write a copy constructor for the DynIntStack class. Explicitly call copy 
		constructor in main().
		
		2.  Make pop member function throw an exception of type int when someone tries 
		to pop element from an empty stack. Run a test in main():pop from an empty 
		stack, use try-catch block to handle the exception.
	
	Stack Class Template 
	
	Transform DynIntStackinto a template class. Test template in main(), create stacks of 
	chars and doubles, run pop and push functions on them. 
*/


// Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include "DynIntStack.h"
#include <iostream>
using namespace std;

template <class C>
void DynIntStack_Runner();

int main()
{
	int choice = 1;
	while(choice)
	{
		system("cls");
		cout << "Pick a type to assign Dynamic Stack\n\n1: Int\n2: Double\n3: Char\n0: exit\n\nChoice: ";
		cin >> choice;

		switch(choice)
		{
		case 1:
			system("cls");
			cout << "Dynamic Stack of type INT chosen\n";
			DynIntStack_Runner<int>();
			break;
		case 2:
			system("cls");
			cout << "Dynamic Stack of type DOUBLE chosen\n";
			DynIntStack_Runner<double>();
			break;
		case 3:
			system("cls");
			cout << "Dynamic Stack of type CHAR chosen\n";
			DynIntStack_Runner<char>();
			break;
		case 0:
			break;
		default:
			cout << "\n\nIncorrect Choice\n\n";
			system("pause");
		}
	}
	return 0;
}

template <class C>
void DynIntStack_Runner()
{
	DynIntStack<C> *iStack = new DynIntStack<C>();
	
	cout << "\nPushing values into int Dynamic Stack\n";
	for(int i = 65; i < 91; i++)
		iStack->push((C)i);
	
	cout << "\nCalling Copy Contructor\n";
	DynIntStack<C> *iStack_Copy = new DynIntStack<C>(iStack);


	C temp = 0;
	cout << "\n\nPopping Stack, should throw exception\n";
	for(int j = 65; j < 92; j++)
	{
		try{ iStack->pop((C)temp); 		
		cout << temp << " ";}
		catch(int){cout << "\nERROR: index out of bounds\n\n";}

	}

	cout << "\n\nPopping Stack COPY, should throw exception\n";
	for(int j = 65; j < 92; j++)
	{
		try{ iStack_Copy->pop((C)temp); 
		cout << temp << " ";}
		catch(int){cout << "\nERROR: index out of bounds\n\n";}
		
	}
	system("pause");
}
