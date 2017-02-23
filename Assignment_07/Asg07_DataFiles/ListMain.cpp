
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
   // Define a NumberList object.
   NumberList list;

   // Build the list with some values.
   list.appendNode(2.5);
   list.appendNode(7.9);
   list.appendNode(12.6);

   // Display the list.
   cout << "Here are the initial values:\n";
   list.displayList();
   cout << endl;

   
   return 0;
}
