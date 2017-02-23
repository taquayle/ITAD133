// Assign_07_01 - Min Max Templates.cpp : Defines the entry point for the console application.
/*
	Minimum/Maximum Templates

	Write templates for the two functions minimumand maximum. The minimumfunction 
	should accept two arguments and return the value ofthe argument that is lesser of the 
	two. The maximumfunction should accept two arguments and return the value of the 
	argument that is the greater of the two. Design a simple driver program (main()) that 
	demonstrates the templates with various data types 
*/

// Tyler Quayle - SIN 950416426
#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T> T maximum (T a, T b){ return (a<b)?b:a;}

template <class T> T minimum (T a, T b){ return (a>b)?b:a;}

int main()
{
	int i_x = 0, i_y = 3;
	cout << "Compare - (Int, Int)\n";
	cout << "Compare " << i_x << " and " << i_y  << "|| max: " << maximum(i_x, i_y);
	cout << "\nCompare " << i_x << " and " << i_y  << "|| min: " << minimum(i_x, i_y);

	double d_x = 4, d_y = 7;
	cout << "\n\nCompare - (Double, Double)\n";
	cout << "Compare " << d_x << " and " << d_y  << " || max: " << maximum(d_x, d_y);
	cout << "\nCompare " << d_x << " and " << d_y  << " || min: " << minimum(d_x, d_y);

	long l_x = 8, l_y = 9;
	cout << "\n\nCompare - (Long, Long)\n";
	cout << "Compare " << l_x << " and " << l_y  << " || max: " << maximum(l_x, l_y);
	cout << "\nCompare " << l_x << " and " << l_y  << " || min: " << minimum(l_x, l_y);

	cout << "\n\n";
	system("pause");
	return 0;
}


