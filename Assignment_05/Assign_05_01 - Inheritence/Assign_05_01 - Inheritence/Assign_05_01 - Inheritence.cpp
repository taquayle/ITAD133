// Assign_05_01 - Inheritence.cpp : Defines the entry point for the console application.
/*PersonData and CustomerData Classes 

PersonData Class 
Design a class named PersonData with the following member variables: 
	•  lastName 
	•  firstName 
	•  address 
	•  phone 
All member variables are of type string. 
	•  Write appropriate accessor and mutator functions for these member variables. 
	•  Write a default constructor that sets all variablesto empty strings. 
	•  Write a non-default constructor that takes all the data about customer as 
		parameters (4 parameters) and initializes member variables. 

CustomerData Class 
Design a class named CustomerData, which is derivedfrom the PersonData class. The 
CustomerData class should have the following membervariables: 
	•  customerNumber 
	•  mailingList 
The customerNumber variable will be used to hold a unique integer for each customer. 
The mailingList variable should be a bool. It will be set to true if the customer whishes to 
be on a mailing list, or false if the customer doesnot with to be on a mailing list. 
	•  Write appropriate accessor and mutator functions for these member variables. 
	•  Write a default constructor that sets all variables(including inherited ones) to 
		empty strings. 
	•  Write a non-default constructor that takes all the data about customer as 
		parameters (name, address, etc., total of 6 parameters) and initializes member variables. 

Demonstrate an object of CustomerData class in a simple program. */

// Tyler Quayle - SIN: 950416426

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class PersonData 
{
protected:
	string lastName;
	string firstName;
	string address;
	string phone;
public:
	PersonData()
	{
		lastName = "";
		firstName = "";
		address = "";
		phone = "";
	}
	PersonData(string _lastName, string _firstName, string _address, string _phone)
	{
		lastName = _lastName;
		firstName = _firstName;
		address = _address;
		phone = _phone;
	}
	string getLastName(){ return lastName;}
	void setLastName(string _lastName) { lastName = _lastName; }
	string getFirstName(){ return firstName;}
	void setFirstName(string _firstName) { firstName = _firstName; }
	string getAddress(){ return address; }
	void setAddress(string _address) {address = _address; }
	string getPhone(){ return phone; }
	void setPhone(string _phone) { phone = _phone; }
};

class CustomerData : public PersonData
{
private:
	int customerNumber;
	bool mailingList;
public:
	CustomerData()
	{
		customerNumber = 0;
		mailingList = false;
	}
	CustomerData(int _customerNumber, bool _mailingList, string _lastName, string _firstName, string _address, string _phone)
	{
		customerNumber = _customerNumber;
		mailingList = _mailingList;
		/*PersonData(_lastName, _firstName, _address, _phone);*/
		lastName = _lastName;
		firstName = _firstName;
		address = _address;
		phone = _phone;
	}
	int getCustomerNumber() { return customerNumber; }
	void setCustomerNunmber( int _customerNumber ) { customerNumber = _customerNumber; }
	bool getMailingList() { return mailingList; }
	void setMailingList( bool _mailingList ) { mailingList = _mailingList; }
	void display()
	{
		cout << "Name: " << firstName << " " << lastName 
			<< "\nCustomer Number: " << customerNumber 
			<< "\nAdress: " << address << "\nPhone: " << phone
			<< "\nMailing List: " << boolalpha << mailingList << "\n\n";
	}

};


int main()
{
	string firstName = "Tony", lastName = "Stark", 
		   address = "10880 Malibu Point, 90265", 
		   phone = "426-476-6626";
	int customerNumber = 55847;
	bool mailingList = true;

	CustomerData newCustomer(customerNumber, mailingList, lastName, firstName, address, phone);

	newCustomer.display();

	system("pause");
	return 0;
}