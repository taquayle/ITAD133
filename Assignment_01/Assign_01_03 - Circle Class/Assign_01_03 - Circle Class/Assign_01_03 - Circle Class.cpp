// Assign_01_03 - Circle Class.cpp : Defines the entry point for the console application.
/*
Circle Class 
Write a Circleclass that has the following member variables: 
  radius: a double
  pi: a double initialized with the value 3.14159 
The class should have the following member functions: 
  *Default constructor. A default constructor that sets radius to 0.0 
  *Constructor. Accepts the radius of the circle as an argument. 
  *setRadius. A mutator function for the radius variable. 
  *getRadius.An accessor function for the radius variable. 
  *GetArea. Returns the area of the circle, which is calculated as 
		area = pi * radius * radius
  *getDiameter. Returns the diameter of the circle, which is calculated as 
		diameter = radius * 2
  *getCircumference. Returns the circumference of the circle, which is calculated as 
		circumference = 2* pi * radius 
Write a program that demonstrates the Circleclass by asking the user of the circle’s 
radius, creating a Circleobject, and then reporting the circle’s area, diameter, and 
circumference. 
*/

//Tyler Quayle - SIN:950416426
#include "stdafx.h"
#include <iostream>
using namespace std;

class Circle
{
private:
	double radius;
	double pi;
public:
	Circle();
	Circle(double);

	void setRadius(double);
	double getRadius() const;
	double getArea() const;
	double getDiameter() const;
	double getCircumference() const;
};

Circle::Circle()
{
	radius = 0.0;
	pi = 3.14159;
}

Circle::Circle (double r)
{
	radius = r;
	pi = 3.14159;
}


double Circle:: getRadius() const
{
	return radius;
}

double Circle:: getArea() const
{
	return (pi * radius * radius);
}

double Circle:: getDiameter() const
{
	return (radius+radius);
}

double Circle:: getCircumference() const
{
	return (2*pi*radius);
}


int main()
{
	int userRadius;

	cout << "Hello, please enter the radius of your circle: ";
	cin >> userRadius;

	Circle userCircle(userRadius);
	cout << "\nRadius: " << userCircle.getRadius();
	cout << "\nArea of circle: " << userCircle.getArea();
	cout << "\nDiameter of circle: " << userCircle.getDiameter();
	cout << "\nCircumference of circle: " << userCircle.getCircumference()<<"\n\n";

	system("pause");
	return 0;
}


