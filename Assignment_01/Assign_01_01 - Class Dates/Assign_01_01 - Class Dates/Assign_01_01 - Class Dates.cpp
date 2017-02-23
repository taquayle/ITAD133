// Assign_01_01 - Class Dates.cpp : Defines the entry point for the console application.
/*
Date Class  
Design a class called Date. The class should store a date in three integers: month, day, 
and year. There should be member functions to print the date in the following forms:  

12/25/06 
December 25, 2006 
25 December 2006  

Demonstrate the class by writing a complete program implementing it. Input validation: 
Do not accept values for the day greater than 31 or less than 1. Do not accept values 
for the month greater than 12 or less than 1. 
*/

// Tyler Quayle  - SID: 950416426
#include "stdafx.h"
#include <iostream>
using namespace std;

const char* monthName[] = {"", "January", "Feburary", "March", "April", 
						"May", "June", "July", "August", "September", 
						"October", "November", "December"};

bool validate(int, int);

class Date
{
private:
	int day,
		month,
		year;
public:
	void setDate(int, int, int);
	void displayOne();
	void displayTwo();
	void displayThree();
};

void Date::setDate(int tempDay, int tempMonth, int tempYear)
{
	day = tempDay;
	month = tempMonth;
	year = tempYear;
}

void Date::displayOne()
{
	cout << endl << month << "/" << day << "/" << (year%100) << endl;
}

void Date::displayTwo()
{
	cout << monthName[month] << " " << day << ", " << year << endl;
}

void Date::displayThree()
{
	cout << day << " " << monthName[month] << " " << year << endl;
}

int main()
{
	Date userDate;
	int tempDay, tempMonth, tempYear;

	do{
	cout << "\nPlease enter the day: ";
	cin >> tempDay;
	}while(!validate(tempDay, 1));

	do{
	cout << "Please enter the month: ";
	cin >> tempMonth;
	}while(!validate(tempMonth, 0));

	cout << "Please enter the year: ";
	cin >> tempYear;

	userDate.setDate(tempDay, tempMonth, tempYear);
	userDate.displayOne();
	userDate.displayTwo();
	userDate.displayThree();

	system("Pause");
	return 0;
}

bool validate(int checkInt, int day_or_month)
{
	if(day_or_month)
	{
		if(checkInt < 1 || checkInt > 31)
		{
			cout << "\nERROR: Day must be 1-31\n";
			return false;
		}
		return true;
	}
	else
	{
		if(checkInt < 1 || checkInt > 12)
		{
			cout << "\nERROR: Month must be 1-12\n";
			return false;
		}
		return true;
	}
}
