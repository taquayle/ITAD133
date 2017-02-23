// Extra_Credit_01_01 - Month Class.cpp : Defines the entry point for the console application.
/*
	Month Class (Aggregation example) 
	Design a class named Month. The class should have the following private members: 
		•  name - AMyStringobject (from the MyStringclass presented in 
			Chapter 14’s Case Study, source code provided) The name object should hold the 
			name of a month, such as “January”, “February”, etc. This is an example of class 
			aggregation: Class month “has an” object oh class MyString as a member 
			variable. 
		•  monthNumber- An integer variable that holds the number of the month. For 
			example, January would be 1, February would be 2 etc. Valid values for this 
			variable are 1 through 12. 
	In addition, provide the following member functions: 
		•  A default constructor that sets monthNumberto 1 and nameto “January”. 
		•  A constructor that accepts the name of the month asan argument. It should set 
			nameto the value passed as the argument and set monthNumberto the correct 
			value. 
		•  A constructor that accepts the number of the month as an arguments. It should set 
			monthNumberto the value passed as the argument and set nameto the correct 
			month name. 
		•  Appropriate set and get functions for the nameand monthNumbermember 
			variables. 
		•  Prefix and postfix overloaded ++ operator functionsthat increment 
			monthNumberand set nameto name of the next month. If monthNumberis 
			set to 12 when these functions execute, they shouldset monthNumberto 1 and 
			nameto “January”. 
		•  Prefix and postfix overloaded -- operator functionsthat decrement 
			monthNumber and set nameto name of previous month. If monthNumberis 
			set to 1 when these functions execute, they should set monthNumberto 12 and 
			nameto “December” 
	Also, you should overload cout’s << operator and cin’s >> operator to work with the 
	Monthclass. Demonstrate the class in a program, test all the operators and functions you 
	wrote. 
*/

//Tyler Quayle - SIN: 950416426

#include "stdafx.h"
#include "MyString.h"
#include <iostream>;
using namespace std;

MyString IntToMonth(int);
int MonthToInt(MyString);

class Month
{
private:
	MyString monthName;
	int monthNumber;
public:
	/* Constructors*/
	Month() { monthName = "January"; monthNumber = 1; }
	Month(MyString _monthName)	{ monthName = _monthName; monthNumber = Check(MonthToInt(_monthName));}
	Month(int _monthNumber)		{ monthName = IntToMonth(Check(_monthNumber)); monthNumber = Check(_monthNumber); }
	/* END Constructors */

	/* Get Functions */
	MyString getMonthName(){ return monthName; }
	int getMonthNumber() { return monthNumber;}
	/* END Get Functions */

	/* Set Functions */
	void setMonthName(MyString _monthName)	{ monthName = _monthName; monthNumber = Check(MonthToInt(_monthName));}
	void setMonthNumber(int _monthNumber)	{ monthName = IntToMonth(Check(_monthNumber)); monthNumber = Check(_monthNumber); }
	/* END Set Functions*/

	/* Overloading Operators */
	Month operator--(int)				// POST-FIX
	{
		Month  temp(monthNumber--);
		setMonthNumber(monthNumber);
		return temp;
	}

	Month &operator--()					// PRE-FIX
	{
		setMonthNumber(--monthNumber);
		return *this;
	}

	Month operator++(int)				// POST-FIX
	{
		Month  temp(monthNumber++);
		setMonthNumber(monthNumber);
		return temp;
	}

	Month &operator++()					// PRE-FIX
	{
		setMonthNumber(++monthNumber);
		return *this;
	}

	friend ostream& operator<<(ostream&, const Month&);
	friend istream& operator>>(istream&, const Month&);
	/* END Overloading Operators */

	int Check(int toCheck)
	{
		if(toCheck < 1)
			return 12;
		if(toCheck > 12)
			return 1;
		return toCheck;
	}

};
ostream &operator<<(ostream &output, const Month &rightObj)
{
	output  << "\nMonth: "<< rightObj.monthNumber;
	output  << " - " << rightObj.monthName;
	return output;
}
istream &operator>>(istream &input, Month &rightObj)
{
	int temp;
	input >> temp;
	rightObj.setMonthNumber(temp);
	return input;
}

int main()
{
	Month monthOne, monthTwo(2);
	cout << "Please enter a Month Number (1-12): ";
	cin >> monthOne;

	cout << "\nMonthOne: " << monthOne << "\n\nMonthTwo: " << monthTwo;
	cout << "\n\nPostFix (++) MonthOne" << monthOne++;
	cout << "\n\nPreFix (++) MonthOne" << ++monthOne;
	cout << "\n\nPostFix (--) MonthTwo" << monthTwo--;
	cout << "\n\nPreFix (--) MonthTwo" << --monthTwo;
	cout << "\n\n";

	system("pause");
	return 0;
}

MyString IntToMonth(int i)
{
	MyString temp;
	switch(i)
	{
	case 1:
		temp = "Janurary";
		break;
	case 2:
		temp = "Feburary";
		break;
	case 3:
		temp = "March";
		break;
	case 4:
		temp = "April";
		break;
	case 5:
		temp = "May";
		break;
	case 6:
		temp = "June";
		break;
	case 7:
		temp = "July";
		break;
	case 8:
		temp = "August";
		break;
	case 9:
		temp = "September";
		break;
	case 10:
		temp = "October";
		break;
	case 11:
		temp = "November";
		break;
	case 12:
		temp = "December";
		break;
	default:
		temp = "unknown month";
	}
	return temp;
}

int MonthToInt(MyString name)
{
	if(name == "Janurary")
		return 1;
	else if(name == "Feburary")
		return 2;
	else if(name == "March")
		return 3;
	else if(name == "April")
		return 4;
	else if(name == "May")
		return 5;
	else if(name == "June")
		return 6;
	else if(name == "July")
		return 7;
	else if(name == "August")
		return 8;
	else if(name == "September")
		return 9;
	else if(name == "October")
		return 10;
	else if(name == "November")
		return 11;
	else if(name == "December")
		return 12;
	else
		return 1;

}