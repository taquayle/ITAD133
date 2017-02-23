// Specification file for the DynIntStack class
#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H
#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
class DynIntStack
{
private:
   // Structure for stack nodes
   struct StackNode
   {
      T value;        // Value in the node
      StackNode *next;  // Pointer to the next node
   };

   StackNode *top;      // Pointer to the stack top

public:
   // Constructor
   DynIntStack()
      {  top = NULL; }

   DynIntStack(DynIntStack *rightObj)
   {
	   DynIntStack<T> *tempStack = new DynIntStack<T>;
	   top = NULL;
	   T temp = NULL;
	   
	   //Pop list to get reverse order of input, destroys rightObj with pop calls
	   while(!rightObj -> isEmpty())
	   {
		   rightObj->pop(temp);
		   tempStack -> push(temp);
	   }
	   
	   //Push so they are in correct order, rebuilding rightObj since it was destoryed when it popped
	   while(!tempStack -> isEmpty())
	   {
		   tempStack -> pop(temp);
		   rightObj -> push(temp);
		   push(temp);
	   }
   }


	//**************************************************
	// Destructor                                      *
	// This function deletes every node in the list.   *
	//**************************************************
	~DynIntStack()
	{
	   StackNode *nodePtr, *nextNode;

	   // Position nodePtr at the top of the stack.
	   nodePtr = top;

	   // Traverse the list deleting each node.
	   while (nodePtr != NULL)
	   {
		  nextNode = nodePtr->next;
		  delete nodePtr;
		  nodePtr = nextNode;
	   }
	}

	//************************************************
	// Member function push pushes the argument onto *
	// the stack.                                    *
	//************************************************

	void DynIntStack::push(T num)
	{
	   StackNode *newNode; // Pointer to a new node

	   // Allocate a new node and store num there.
	   newNode = new StackNode;
	   newNode->value = num;

	   // If there are no nodes in the list
	   // make newNode the first node.
	   if (isEmpty())
	   {
		  top = newNode;
		  newNode->next = NULL;
	   }
	   else  // Otherwise, insert NewNode before top.
	   {
		  newNode->next = top;
		  top = newNode;
	   }
	}

	//****************************************************
	// Member function pop pops the value at the top     *
	// of the stack off, and copies it into the variable *
	// passed as an argument.                            *
	//****************************************************

	void DynIntStack::pop(T &num)
	{
	   StackNode *temp; // Temporary pointer

	   // First make sure the stack isn't empty.
	   if (isEmpty())
	   {
		   throw -1;
	   }
	   else  // pop value off top of stack
	   {
		  num = top->value;
		  temp = top->next;
		  delete top;
		  top = temp;
	   }
	}

	//****************************************************
	// Member function isEmpty returns true if the stack *
	// is empty, or false otherwise.                     *
	//****************************************************

	bool DynIntStack::isEmpty()
	{
	   bool status;

	   if (!top)
		  status = true;

	   
	   else
		  status = false;

	   return status;
	}
}; 
#endif
