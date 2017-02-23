// Assign_02_02 - InventoryClass.cpp : Defines the entry point for the console application.
//

// Tyler Quayle - SIN: 950416426
#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int DEFAULT_SIZE = 51;

class InventoryItem
{
private:
   char *description;  // The item description
   double cost;        // The item cost
   int units;          // Number of units on hand
   
   // Private member function.
   void createDescription(int size, char *value)
      { // Allocate the default amount of memory for description.
        description = new char [size+1];
        
        // Store a value in the memory.
        strcpy(description, value); }

public:
   // Constructor #1
   InventoryItem()
      { // Store an empty string in the description
        // attribute.
        description=NULL;
        
        // Initialize cost and units.
        cost = 0.0;
        units = 0; }

   // Constructor #2
   InventoryItem(char *desc)
      { // Allocate memory and store the description.
        createDescription(strlen(desc), desc); 
        
        // Initialize cost and units.
        cost = 0.0;
        units = 0; }

   // Constructor #3
   InventoryItem(char *desc, double c, int u)
      { // Allocate memory and store the description.
        createDescription(strlen(desc), desc); 

        // Assign values to cost and units.
        cost = c;
        units = u; }      
        
   // Destructor
   ~InventoryItem()
      { 
		  if(description) {delete [] description; } 
	  }

   // Mutator functions
   void setDescription(char *d) 
      {   
		  if(description) { delete [] description; }
		  createDescription(strlen(d), d); 
	  }

   void setCost(double c)
      { cost = c; }
      
   void setUnits(int u)
      { units = u; }

   // Accessor functions
   const char *getDescription() const
      { return description; }
         
   double getCost() const
      { return cost; }

   int getUnits() const
      { return units; }

   /*********************/
   //	START My Code	//
   /*********************/
   InventoryItem (const InventoryItem &newItem)
   {
		createDescription(strlen(newItem.description), newItem.description);
		cost = newItem.cost;
		units = newItem.units;
   }

   InventoryItem& InventoryItem :: operator=(const InventoryItem &rightItem)
   {
	  if(description != rightItem.description)
	   {
			delete [] description;
			description = new char[strlen(rightItem.description)+1];
			strcpy(description, rightItem.description);
			cost = rightItem.cost;
			units = rightItem.units;
	  }
	  return *this;
   }
   /*********************/
   //	END My Code		//
   /*********************/
};
int main()
{
	InventoryItem item1("Wrench", 5.5, 10);
	item1.setDescription("Big Wrench");

   const int NUM_ITEMS = 5;
   InventoryItem inventory[NUM_ITEMS] = { 
                  InventoryItem("Hammer", 6.95, 12),
                  InventoryItem("Wrench", 8.75, 20),
                  InventoryItem("Pliers", 3.75, 10),
                  InventoryItem("Ratchet", 7.95, 14),
                  InventoryItem("Screwdriver", 2.50, 22) };

   cout << setw(14) <<"Inventory Item" 
        << setw(8) << "Cost" << setw(8) 
        << setw(16) << "Units On Hand\n";
   cout << "-------------------------------------\n";

   for (int i = 0; i < NUM_ITEMS; i++)
   {
      cout << setw(14) << inventory[i].getDescription();
      cout << setw(8) << inventory[i].getCost();
      cout << setw(7) << inventory[i].getUnits() << endl;
   }
	
	/********************/
	//	START My Code	//
	/********************/
	InventoryItem myItem("MyItem", 10, 20);
   
	cout << setw(14) << myItem.getDescription();
	cout << setw(8) << myItem.getCost();
	cout << setw(7) << myItem.getUnits() << endl;

	InventoryItem constructor_copy(myItem);
	
	cout << setw(14) << constructor_copy.getDescription();
	cout << setw(8) << constructor_copy.getCost();
	cout << setw(7) << constructor_copy.getUnits() << endl;

	InventoryItem operator_copy;
	operator_copy = myItem;
	cout << setw(14) << operator_copy.getDescription();
	cout << setw(8) << operator_copy.getCost();
	cout << setw(7) <<  operator_copy.getUnits() << endl;
	
	/*********************/
	//	END My Code		//
	/*********************/
	system("pause");
   return 0;
}
