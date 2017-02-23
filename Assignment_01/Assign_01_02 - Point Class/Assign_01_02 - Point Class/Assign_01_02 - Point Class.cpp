// Assign_01_02 - Point Class.cpp : Defines the entry point for the console application.
/*
Point Class 
Write a definition of a class named Pointthat might be used to store and manipulate the 
location of a point on the plane. You will need to declare and implement the following 
member functions: 

1.  The member function setthat sets the private data after an object of thisclass is 
created. 

2.  The member function to move the point by an amount along the vertical and 
horizontal directions specified by the first and second arguments. 

3.  The member function to rotate the point by 90 degrees clockwise around the 
origin. 

4.  two accessor functions to retrieve the coordinates of the point 

Document these functions with appropriate comments.Embed your class in a test 
program that requests the data for several points from the user, creates a point, then calls 
the member functions. 
*/

//Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	void set(int, int);
	void move(int, int);
	void rotate();
	int getX() const;
	int getY() const;
};

void Point::set(int tempX, int tempY) //Set the two private variable X and Y
{
	x = tempX;
	y = tempY;
}

void Point::move(int moveX, int moveY) //Move the X and Y by the user entered values
{
	x += moveX;
	y += moveY;
}

void Point::rotate() //Rotate the x and y coordinates around the origin
{
	int tempMoveX = x;
	x = y;
	y = (0 - tempMoveX);
}

int Point::getX() const // Returns the X value, const so cannot be used to change the values
{
	return x;
}

int Point::getY() const // Returns the Y value, const so cannot be used to chsnge the value of Y
{
	return y;
}


int main()
{
	int userX, userY, moveX, moveY;
	Point userPoint;

	cout << "Enter value of X coordinate: ";
	cin >> userX;

	cout << "Enter value of Y coordinate: ";
	cin >> userY;

	cout << "Enter value to move the X coordinate by: ";
	cin >> moveX;

	cout << "Enter value to move the Y coordinate by: ";
	cin >> moveY;

	userPoint.set(userX, userY);

	cout << "\nUser entered point:\nPoint: (" << userPoint.getX() << ", " << userPoint.getY() << ")" << endl;

	userPoint.move(moveX, moveY);
	cout << "\nPoint after move:\nPoint: (" << userPoint.getX() << ", " << userPoint.getY() << ")" << endl;

	userPoint.rotate();
	cout << "\nPoint after clock rotation:\nPoint: (" << userPoint.getX() << ", " << userPoint.getY() << ")" << endl;
	
	system("pause");
	return 0;
}

