// Assign_04_03 - Inventory Program.cpp : Defines the entry point for the console application.
/*
Inventory Program 
Write a program that uses a structure to store the following inventory data in a file: 
Item Description 
Quantity on Hand 
Wholesale Cost 
Retail Cost 
Date Added to Inventory 

The program should have a menu that allows the userto perform the following tasks: 
•  Add new record to the file. 
•  Display any record in the file 
•  Change any record in the file. 
Requirement: File I/O should be done in binary mode. 
Input Validation:The program should not accept quantities or wholesale or retail costs 
less than 0. The program should not accept dates that the programmer determines as 
unreasonable 
*/

//Tyler Quayle
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int menu();
void addItem(fstream&);
void displayItem(fstream&, int);
void changeItem(fstream&, int);
bool validate(int, int);
void removeFile();

struct inventoryItem
{
	char description[50];
	int onHand;
	double wholesale;
	double retail;
	int month, day, year;
};



int main()
{
	while(menu());
	
	system("pause");
	return 0;
}

int menu()
{
	fstream inventory;
	inventory.open("inventory.txt", ios::in | ios::out | ios::binary | ios::app);
	
	system("cls");
	int choice, itemNumber;

	cout << "Menu\n1: Add new record\n2: Display File\n3: Change Record\n4: exit\nChoice: ";
	cin >> choice;

	switch(choice)
	{
		case 1:
			addItem(inventory);
			break;
		case 2:
			system("cls");
			cout << "Item Number to display: ";
			cin >> itemNumber;
			displayItem(inventory, itemNumber);
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Item Number to change: ";
			cin >> itemNumber;
			changeItem(inventory, itemNumber);
			break;
		case 4:
			cout << "\nEXITING\n\n";
			inventory.close();
			return 0;
			break;
		default:
			cout << "Invalid choice";
			break;
	}
	return 1;
}

void addItem(fstream &input)
{
	system("cls");
	inventoryItem tempItem;
	cout << "ADD ITEM\n\nItem Description: ";
	cin >> tempItem.description;
	cout << "On hand: ";
	cin >> tempItem.onHand;
	cout << "Wholesale: ";
	cin >> tempItem.wholesale;
	cout << "Retail: ";
	cin >> tempItem.retail;
	do{
	cout << "Month: ";
	cin >> tempItem.month;
	}while(!validate(tempItem.month, 1));
	do{
	cout << "Day: ";
	cin >> tempItem.day;
	}while(!validate(tempItem.day, 0));
	do{
	cout << "Year: ";
	cin >> tempItem.year;
	}while(!validate(tempItem.year, 2));
	input.seekp(sizeof(inventoryItem), ios::end);
	input.write(reinterpret_cast<char*>(&tempItem), sizeof(inventoryItem));
}

void displayItem(fstream &output, int itemNumber)
{
	inventoryItem outTemp;
	long seekNum = sizeof(inventoryItem)*itemNumber;
	output.seekg(seekNum, ios::beg);
	output.read(reinterpret_cast<char*>(&outTemp), sizeof(inventoryItem));

	
	cout << "DISPLAY ITEM\n";
	cout << "\nDescription:\t\t" << outTemp.description;
	cout << "\nOn Hand:\t\t" << outTemp.onHand;
	cout << "\nWholesale Cost:\t\t$" << outTemp.wholesale;
	cout << "\nRetail Cost:\t\t$" << outTemp.retail;
	cout << "\nDate:\t\t\t" << outTemp.month << "/" << outTemp.day << "/" << outTemp.year;
	cout << endl;
}

void changeItem(fstream &input, int itemNumber)
{
	system("cls");
	inventoryItem tempItem;
	cout << "CHANGE ITEM\n\nItem Description: ";
	cin >> tempItem.description;
	cout << "On hand: ";
	cin >> tempItem.onHand;
	cout << "Wholesale: ";
	cin >> tempItem.wholesale;
	cout << "Retail: ";
	cin >> tempItem.retail;
	do{
	cout << "Month: ";
	cin >> tempItem.month;
	}while(!validate(tempItem.month, 1));
	do{
	cout << "Day: ";
	cin >> tempItem.day;
	}while(!validate(tempItem.day, 0));
	do{
	cout << "Year: ";
	cin >> tempItem.year;
	}while(!validate(tempItem.year, 2));
	long seekNum = sizeof(inventoryItem)*itemNumber;
	input.seekp(seekNum, ios::beg);
	input.write(reinterpret_cast<char*>(&tempItem), sizeof(inventoryItem));
}

bool validate(int date, int choice)
{
	switch(choice)
	{
	case 0:
		if(date < 1 || date > 31)
			return 0;
		return 1;
		break;
	case 1:
		if(date < 1 || date > 12)
			return 0;
		return 1;
		break;
	case 2:
		if(date < 1900 || date > 2014)
			return 0;
		return 1;
		break;
	}

}
