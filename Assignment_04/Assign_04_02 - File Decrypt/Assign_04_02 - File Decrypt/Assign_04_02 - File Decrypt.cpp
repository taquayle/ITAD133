// Assign_04_02 - File Decrypt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int decrypt(ifstream&, ofstream&);

int main()
{
	int i = 0, seed = 0;

	ifstream decryptIn("encrypted.txt");
	ofstream decryptedFile("decrypted.txt");

	char password[20];
	cout << "Please enter a Decryption password: ";
	cin >> password;

	while(password[i] != -52){
		if(i % 2 == 0) seed += (int)password[i++];
		if(i % 2 != 0) seed -= (int)password[i++];
	}


	srand(seed); 
	
	if(decrypt(decryptIn, decryptedFile))
		cout << "\n\nTest";
	else cout << "Failure to decrypt";

	cout << endl << endl;
	system("Pause");
	return 0;
}




int decrypt(ifstream &input, ofstream &output)
{
	if (input == NULL || output == NULL)
	{
		cout << "ERROR: file failed to open" << endl;
		return 0;
	}

	else
	{
		char currentChar;


		cout << "\nFile successfully opened\n" << endl;

		cout << "\n\n Input Text:\n\n";
		input.get(currentChar);
		
		while(!input.eof()){
		input.get(currentChar);
		cout << currentChar;}

		input.clear();
		input.seekg(0, ios::beg);

		cout << "\n\n Decrpytion check:\n\n";
		input.get(currentChar);
		while(!input.eof())
		{
			currentChar -= rand() % 15;
			cout << currentChar;
			output << currentChar;
			input.get(currentChar);
		}
	}

	output.close();
	input.close();
	return 1;
}
