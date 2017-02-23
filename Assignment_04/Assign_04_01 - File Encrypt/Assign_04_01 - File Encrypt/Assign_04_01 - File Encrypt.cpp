// Assign_04_01 - File Encrypt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int encrypt(ifstream&, ofstream&);

int main()
{
	char currentChar;

	int seed = 0;
	int i = 0;

	ifstream startFile("input.txt");
	ifstream displayFile("input.txt");
	ofstream encryptedFile("encrypted.txt");

	char password[20];
	cout << "Please enter a Encryption password: ";
	cin >> password;

	while(password[i] != -52){
		if(i % 2 == 0) seed += (int)password[i++];
		if(i % 2 != 0) seed -= (int)password[i++];}

	srand(seed); 

	if(encrypt(displayFile, encryptedFile))
		cout << "\n\t\nFile Successfully Encrypted";
	else cout << "\n\n\tFailure to encrypted";

	system("Pause");
	return 0;
}

int encrypt(ifstream &input, ofstream &output)
{
	char currentChar;
	if (input == NULL)
	{
		cout << "\nERROR: Input file failed to open" << endl;
		return 0;
	}
	if(output == NULL)
	{
		cout << "\nERROR: Output file failed to open" << endl;
		return 0;
	}

	else
	{
		cout << "\nFiles successfully opened\n" << endl;
		
		cout << "\n\n Input Text:\n\n";
		input.get(currentChar);
		
		while(!input.eof()){
		input.get(currentChar);
		cout << currentChar;}

		input.clear();
		input.seekg(0, ios::beg);

		cout << "\n\n Encrypted Text:\n\n";
		
		input.get(currentChar);
		while(!input.eof())
		{
		    currentChar += rand() % 15;
		    output << currentChar;
		    cout << currentChar;
			input.get(currentChar);
			
		}

		output.close();
		input.close();

		return 1;
	}
}