// Assignment_06_02 - Sum of Numbers.cpp : Defines the entry point for the console application.
/*
	Sum of numbers 

	Write a recursive function that accepts an integer argument and returns the sum of all the 
	integers from 1 up to the number passed as an argument. For example, if 50 was passed 
	as an argument, the function will return the sum: 1+2+3+…+50. 
	Demonstrate the function in a program. 
*/

// Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
using namespace std;

int recSumOfNumber(int);
int sumOfNumber(int);

int main()
{
	int userNumber;
	cout << "Enter a number for Recursive Sum of Numbers: ";
	cin >> userNumber;
	
	cout << "\nAnswer with recursive function:\t" << recSumOfNumber(userNumber);
	cout << "\nAnswer check using while loop:\t" << sumOfNumber(userNumber) << "\n\n";

	system("pause");
	return 0;
}

int recSumOfNumber(int n)
{
	if(n) return recSumOfNumber(--n) + (n + 1);
	return n;
}

int sumOfNumber(int n)
{
	int temp = 0;
	for(int i = 0; i <= n; i++)
		temp += i;
	return temp;
}