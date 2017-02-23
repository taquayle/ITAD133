// Extra_Credit_02_02 - 2D Point and 3D Point.cpp : Defines the entry point for the console application.
/*
	2DPoint and 3DPoint Classes 
	1. Design a class named TwoDPoint to represent a point with x and y coordinates. 
	The class contains: 
		* Two data fields x and y that represent the coordinates. 
		* Default constructor that creates a point (0,0) 
		* A constructor that constructs a point with specified coordinates 
		* Two accessor functions 
		* A function named distance that returns the distance from this point to 
			the origin. Function header: 
				virtual double distance() const 
 
 Formula for calculating distance between two-dimensional point 
	(x1, y1) and the origin is: 
		d = sqrt( (x1)2+(y1)2) 

	2. Create a class named ThreeDPoint to model a point in a three-dimensional 
	space. let ThreeDPoint be derived from TwoDPoint with the following 
	additional features: 
		* A data field z that represents the z-coordinate. 
		* Default constructor that creates a point (0,0,0) Lake Washington Institute of Technology 
		* Accessor function for z 
		* Override the distance function to return the distance between the 
			point in the three-dimensional space and the origin. Function header: 
				double distance() const 

	Formula for calculating this distance is 
		d = sqrt( (x1)2+(y1)2+(z1)2) where the coordinates of the point are (x1, y1, z1)

	3. Test your new classes in main(). Specifically, make sure that the following code 
	calls the correct implementation of the distance function: 
		TwoDPoint * ptPtr1 = new TwoDPoint(3, 5); 
		TwoDPoint * ptPtr2 = new ThreeDPoint(7, 10, 15); 
		cout<<”The 2D distance is “<< ptPtr1->distance();
		cout<<”The 3D distance is “<< ptPtr2->distance(); 
*/

// Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
using namespace std;

class TwoDPoint
{
private:
	double x;
	double y;
public:
	// Default Constructor setting x and y to zero;
	TwoDPoint(){ x = 0; y = 0;}
	// Constructor to specific points
	TwoDPoint(double _x, double _y) { x = _x; y = _y;}		

	double getX() { return x; } 
	double getY() { return y; }

	void setX(double _x) { x = _x; }
	void setY(double _y) { y = _y; }

	// Distance from Origin
	virtual double distance() { return sqrt(pow(x,2) + pow(y,2)); }
};

class ThreeDPoint : public TwoDPoint
{
private:
	double z;
public:
	// Default Constructor, set everything to zero, call to super.defualt
	ThreeDPoint():TwoDPoint(){ z = 0;}
	// Constructor to specific point
	ThreeDPoint(double _x, double _y, double _z) : TwoDPoint(_x, _y){ z = _z; }

	double getZ() { return z; }

	double setZ(double _z) { z = _z;}

	// Distance from Origin
	double distance() { return sqrt(pow(getX(),2) + pow(getY(),2) + pow(z,2)); }
};

int main()
{
	TwoDPoint * ptPtr1 = new TwoDPoint(3, 5); 
	TwoDPoint * ptPtr2 = new ThreeDPoint(7, 10, 15); 
	cout << "The 2D distance is "<< ptPtr1->distance();
	cout << "\nThe 3D distance is "<< ptPtr2->distance(); 
	cout << endl;

	system("pause");
	return 0;
}

