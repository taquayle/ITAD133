#ifndef NUMDAYS_H
#define NUMDAYS_H

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

#endif