/*
NumDays Class 
Implement a class called NumDays. The class’s purpose is to store a value that represents 
a number of work hours and convert it to a number of days. For example, 8 hours would 
be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would be 
converted to 2.25 days. The class should have a constructor that accepts a number of 
hours, default constructor, member functions for storing and retrieving the hours and 
days. The class should also have the following overloaded operators: 
		
Demonstrate (test) all the member functions and overloaded operators in main(). 
*/

//Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
using namespace std;

class numDays
{
private:
	double hours;
public:
	numDays();
	numDays(double _hours);
	double getDays();
	void setDays(double);
	double getHours();
	void setHours(double);
	numDays operator+(const numDays&);
	numDays operator-(const numDays&);
	numDays& operator++();
	numDays operator++(int _NOUSE);
	numDays& operator--();
	numDays operator--(int _NOUSE);
	friend ostream& operator<<(ostream&, const numDays&);
	bool operator<(const numDays&);
	bool operator>(const numDays&);
	bool operator==(const numDays&);
};


/* Defualt Constructor */
numDays :: numDays()
{
	hours = 0;
}

/* Assignment Constructor */
numDays :: numDays(double _hours)
{
	hours = _hours;
}



/* Get/Set for Hours */
double numDays :: getHours(){ return hours; }
void numDays :: setHours(double _hours) { hours = _hours; }

//**********************************************************************************/
//	1.  + Addition operator.When two numDays objects are added together, the		/
//	overloaded + operator should return the sum of the two object’s hours members.	/ 
//**********************************************************************************/
numDays numDays :: operator+(const numDays &rightObj)
{
	numDays temp;
	temp.hours = hours + rightObj.hours;
	return temp;
}

//**********************************************************************************/
//	2.  - Subtraction operator. When one NumDays Object is subtracted from another,	/ 
//	the overloaded – operator should return the difference of the two object’s hours/	 
//	members																			/
//**********************************************************************************/
numDays numDays :: operator-(const numDays &rightObj)
{
	numDays temp;
	temp.hours = hours - rightObj.hours;
	return temp;
}

//**********************************************************************************/
//	3.  ++ Prefix and postfix increment operators.These operators should increment	/
//	the number of hours stored in the object. When incremented, the number of days	/
//	should be automatically re-calculated (if you store number of days in member	/
//	variable).																		/
//**********************************************************************************/
numDays& numDays :: operator++()			//Prefix
{
	++hours;
	numDays temp(hours);
	return temp;
}

numDays numDays :: operator++(int _NOUSE)	//Postfix
{
	numDays temp(hours);
	hours++;
	return temp;;
}

//**********************************************************************************/
//	4.  -- Prefix and postfix decrement operators.These operators should decrement	/ 
//	the number of hours stored in the object. When decremented, the number of days	/
//	should be automatically re-calculated (if you storenumber of days in member		/
//	variable).																		/
//**********************************************************************************/
numDays& numDays :: operator--()			//Prefix
{
	--hours;
	numDays temp(hours);
	return temp;
}

numDays numDays :: operator--(int _NOUSE)	//Postfix
{
	numDays temp(hours);
	hours--;
	return temp;
}

//**********************************************************************************/
//	5.  << cout’s stream insertion operator.This operator should cause the days and	/ 
//	hours to be displayed in the form:  1.5 day(s) -- 18 hour(s).					/
//	 Overload << as friend function.												/
//**********************************************************************************/
ostream &operator<<(ostream &output, const numDays &rightObj)
{
	output << (rightObj.hours/8) << " day(s) -- "; 
	output << rightObj.hours << " hour(s)\n"; 
	return output;
}

//**********************************************************************************/
//	6.  < Less operator. Relational operator returns true if the number ofdays and	/ 
//	hours of the right operand is less than the number of days and hours of the left/ 
//	operand.																		/
//**********************************************************************************/
bool numDays :: operator<(const numDays &rightObj)
{
	if(hours < rightObj.hours) return true;
	
	else return false;
}

//**********************************************************************************/
//	7.  > More operator.															/	
//**********************************************************************************/
bool numDays :: operator>(const numDays &rightObj)
{
	if(hours > rightObj.hours) return true;
	
	else return false;
}

//**********************************************************************************/
//	8.  == Equal Operator.															/
//**********************************************************************************/
bool numDays :: operator==(const numDays &rightObj)
{
	if(hours == rightObj.hours) return true;
	
	else return false;
}

int main()
{
	numDays dayOne(8), dayTwo(16);

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


