//This program defines a class for storing the names of classes that a student has enrolled in.

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Student
{
public:
	Student();
	Student(Student& obj); // copy constructor
	~Student();
	void InputData();		// Input all data from user
	void OutputData();		// Output class list to console
	void ResetClasses();		// Reset class list
	Student operator =(const Student& rightSide);	// Assignment operator

private:
	string name;
	int numClasses;
	string *classList;
};

// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

// ======================
// Student::Student
// The default constructor initialized variables to empty.
// The dynamic array is intialized to NULL.
// ======================

// ======================
// Student::Student
// The copy constructor creates adeep copy of the prameter object
// ======================

// ======================
// Student::~Student
// The destructor frees up any memory allocated to
// the dynamic array.
// ======================

// ======================
// Student::ResetClasses
// This method deletes the class list
// ======================

// ======================
// Student::InputData
// This method inputs all data from the user. 
// It allows the user to enter an arbitrary number of classes
// using a dynamic array to store the strings.

// Reset the class list before entering data just in case this method
// was called repeatedly and the dynamic array wasn't cleared
// ======================


// ======================
// Student::OutputData
// This method outputs the data entered by the user.
// ======================


// ======================
// Student::=
// This method copies a new classList to
// the target of the assignment.  Without overloading this
// operator, we would end up with two references to the same
// class list when the assignment operator is used.
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
  // Test our code with two student classes
  Student s1, s2;

  s1.InputData();		// Input data for student 1
  cout << "Student 1's data:" << endl;
  s1.OutputData();		// Output data for student 1

  cout << endl;

  s2 = s1;	
  cout << "Student 2's data after assignment from student 1:" << endl;
  s2.OutputData();		// Should output same data as for student 1

  s1.ResetClasses();
  cout << "Student 1's data after reset:" << endl;
  s1.OutputData();		// Should have no classes

  cout << "Student 2's data, should still have original classes:" << endl;
  s2.OutputData();		// Should still have original classes

  Student s3(s2);  // explicit copy constructor call
  cout << "Student 3's data after assignment from student 2:" << endl;
  s2.OutputData(); // should have the same classes as student 2

  cout << endl;
  system("pause");
  return 0;
}

