// Assign_05_02 - Shapes.cpp : Defines the entry point for the console application.
/*
	Shapes 
Define a pure abstract base class called BasicShape. The BasicShapeclass should 
have the following members: 
	Protected member variable: 
		area, a double used to hold the shape’s area. 
	Public member functions: 
		getArea, accessor function for the area. 
		calcArea, pure virtual function. 

Next, define a class named Circle. It should be derived from the BasicShapeclass. 
It should have the following members: 
	Private member variables: 
		centerX, integer to hold x coordinate of the circle’s center. 
		centerY, integer to hold y coordinate of the circle’s center. 
		radius, integer to hold the radius of the circle. 
	Public member functions: 
		Default constructor 
		constructor – accepts values for centerX, centerY, and radius. Should call the overridden 
			calcAreafunction described below. 
		getCenterX– returns the value in centerX. 
		getCenterY– returns the value in centerY. 
		calcArea– calculates the area of the circle (area = 3.14*radius*radius) and stores it in 
			the area member variable. 

Next, define a class named Rectangle. It should be derived from the BasicShape
class. It should have the following members: 
	Private member variables: 
		width, integer to hold the width of the rectangle. 
		length, integer to hold the length of the rectangle. 
	Public member functions: 
		Default constructor 
		constructor – accepts values for length and width. Should call the overridden calcArea
			function described below. 
		getLength– returns the value in length. 
		getWidth– returns the value in width. 
		calcArea– calculates the area of the rectangle (area = length*width) and stores it in 
			the area member variable. 

After you have created these classes, create a driver program that defines a Circle
object and a Rectangleobject. Demonstrate that each object properly calculates and 
reports its area.
*/

// Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
using namespace std;

#define PI 3.141592653589

class BasicShape
{
protected:
	double area;
public:
	double getArea() { return area; }
	virtual double calcArea() = 0;
};

class Circle : public BasicShape
{
private:
	int centerX;
	int centerY;
	int radius;
public:
	Circle() { centerX = centerY = radius = 0; }
	Circle(int _X, int _Y, int _R)
	{
		centerX = _X;
		centerY = _Y;
		radius = _R;
		area = calcArea();
	}
	int getCenterX() { return centerX; }
	int getCenterY() { return centerY; }
	int getRadius() { return radius; }
	double calcArea() { return PI*radius*radius; }
};

class Rectangle : public BasicShape
{
private:
	int width;
	int length;
public:
	Rectangle() { width = length = 0; }
	Rectangle(int _W, int _L)
	{
		width = _W;
		length = _L;
		area = calcArea();
	}
	int getLength() { return length; }
	int getWidth() { return width; }
	double calcArea() { return length * width; }
};


int main()
{
	Circle userCircle(0,2,3);
	Rectangle userRectangle(2,4);

	cout << "Circle with center at (" << userCircle.getCenterX() 
			<< ", " << userCircle.getCenterY()  
			<< ") and radius of " << userCircle.getRadius()
			<< ". Has an Area of " << userCircle.getArea() << "\n\n";

	cout << "Rectangle with Length of " << userRectangle.getLength() 
			<< " and Width of " << userRectangle.getWidth()
			<< " has an Area of " << userRectangle.getArea() << "\n\n";
	system("pause");
	return 0;
}

