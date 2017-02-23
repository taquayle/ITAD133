//hotdogs.cpp
//This program defines a class for tracking hot dog sales.
//
//It tracks the stand's ID number, hot dogs sold at each stand,
//  and hot dogs sold at all stands.

#include <iostream>
#include <cstdlib>

using namespace std;

class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(int newID, int newNnumSold);
	int GetID();
	void SetID(int newID);
	void JustSold();
	int GetNumSold();
	static int GetTotalSold();

private:
	static int totalSold;
	int numSold;
	int ID;
};

// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

// ======================
// HotDogStand::HotDogStand
// The default constructor initializes the ID and num sold to zero.
// ======================


// ======================
// HotDogStand::HotDogStand
// This constructor initializes the ID and num sold.
// ======================


// ======================
// HotDogStand::GetID
// Returns the ID number of this stand.
// ======================


// ======================
// HotDogStand::SetID
// Sets the ID number of this stand.
// ======================


// ======================
// HotDogStand::JustSold
// Increments the number of hotdogs this stand
// has sold by one.
// ======================


// ======================
// HotDogStand::GetNumSold
// Returns the number of hotdogs this stand has sold.
// ======================

// ======================
// HotDogStand::GetTotalSold
// Returns the number of hotdogs sold by all stands
// ======================


//
// --------------------------------
// --------- END USER CODE --------
// --------------------------------



// ======================
//     main function
// ======================
int main()
{
  // Test our code with three hot dog stands
  HotDogStand s1(1,0),s2(2,0),s3(3,0);
  
  // Sold at stand 1, 2
  s1.JustSold();
  s2.JustSold();
  s1.JustSold();

  cout << "Stand " << s1.GetID() << " sold " << s1.GetNumSold() << endl;
  cout << "Stand " << s2.GetID() << " sold " << s2.GetNumSold() << endl;
  cout << "Stand " << s3.GetID() << " sold " << s3.GetNumSold() << endl;
  cout << "Total sold = " << s1.GetTotalSold() << endl;
  cout << endl;

  // Sold some more
  s3.JustSold();
  s1.JustSold();

  cout << "Stand " << s1.GetID() << " sold " << s1.GetNumSold() << endl;
  cout << "Stand " << s2.GetID() << " sold " << s2.GetNumSold() << endl;
  cout << "Stand " << s3.GetID() << " sold " << s3.GetNumSold() << endl;
  cout << "Total sold = " << s1.GetTotalSold() << endl;
  cout << endl;
  return 0;
}
