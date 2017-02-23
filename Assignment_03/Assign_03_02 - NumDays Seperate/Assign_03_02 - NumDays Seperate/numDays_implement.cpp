#include "stdafx.h"
#include "numDays.h"

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