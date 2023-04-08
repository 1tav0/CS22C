/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 4
 */
#include <iostream>
#include "List.h"
using namespace std;

int main() {

	/*
	//instantiate two lists for testing purposes
	List<int> L1;
	List<int> L2;

    //Testing insertFirst()
    cout << "\n**Testing InsertFirst()**\n\n";
    cout << "Should print out an empty line: \n";
    L1.printList(); //Should not print any message to the screen, just an empty line

    L1.insertFirst(0);
    cout << "Should print out 0 and then move to a new line: \n";
    L1.printList();
    for (int i = 1; i <= 10; i++) { //inserting the the values 1-10 into L1
        L1.insertFirst(i);
    }
    cout << "Should print out 10 9 8 7 6 5 4 3 2 1 0 and then move to a new line: \n";
    L1.printList();

    //Testing insertLast()
    cout << "\n**Testing insertLast()**\n\n";
    L2.insertLast(100);
    cout << "Should print out 100 and then move to a new line: \n";
    L2.printList();
    L2.insertLast(99);
    cout << "Should print out 100, 99 and then move to a new line: \n";
    L2.printList();

    //Testing removeFirst()
    cout << "\n**Testing removeFirst()**\n\n";
	L2.removeFirst();
    cout << "Should print out 99 and then move to a new line: \n";
    L2.printList();
    L2.removeFirst();
    cout << "Should print out empty list and then move to a new line: \n";
    L2.printList();
    cout << "Assertion violated, the program should halt.\n";
    //L2.removeFirst();//assertion violated

    //Testing removeLast()
    cout << "\n**Testing removeLast()**\n\n";
    for (int i = 1; i <= 2; i++) {
        L2.insertFirst(i);
    }
    L2.removeLast();
    cout << "Should print out 2 and then move to a new line: \n";
    L2.printList();
    L2.removeLast();
    cout << "Should print out empty list and then move to a new line: \n";
    L2.printList();
    cout << "Assertion violated, the program should halt.\n";
    //L2.removeLast();//assertion violated

    //Testing isEmpty()
    cout << "\n**Testing isEmpty()**\n\n";
    cout << "Should print out: 0 and then move to a new line: \n";
    cout << L1.isEmpty() << endl;
    cout << "Should print out: 1 and then move to a new line: \n";
    cout << L2.isEmpty() << endl << endl;

    //Testing getLength()
    cout << "**Testing getLength()**\n\n";
    cout << "Should print out: 11 and then move to a new line: \n";
    cout << L1.getLength() << endl;
    cout << "Should print out: 0 and then move to a new line: \n";
    cout << L2.getLength() << endl << endl;

    //Testing getFirst()
    cout << "**Testing getFirst()**\n\n";
    cout << "Should print out: 10 and then move to a new line: \n";
    cout << L1.getFirst() << endl << endl;

    //Testing getLast()
    cout << "**Testing getLast()**\n\n";
    cout << "Should print out: 0 and then move to a new line: \n";
    cout << L1.getLast() << endl << endl;
    cout << "Assertion violated, the program should halt.\n";
    //L2.getLast();//assertion violated

    //Testing startIterator()
    cout << "\n**Testing startIterator()**\n\n";
    L2.insertFirst(5);
    L2.insertLast(8);
    L2.insertFirst(2);
    L2.startIterator();
    cout << "The data at the first node is 2: \n" << L2.getIterator() << endl << endl;

    //Testing advanceIterator()
    cout << "**Testing advanceIterator()**\n\n";
    L2.advanceIterator();
    cout << "The data in the second node is 5: \n" << L2.getIterator() << endl << endl;

    //Testing offEnd()
    cout << "**Testing offEnd()**\n\n";
    L2.advanceIterator();
    cout << "The data at the last node is 8: \n" << L2.getIterator() << endl << endl;
    cout << "Iterator should NOT be off the end of the list" << endl;
    if (L2.offEnd())
        cout << "Iterator is off the end of the list" << endl;
    else
        cout << "Iterator is not off the end of the list" << endl << endl;
    L2.advanceIterator();
    cout << "Iterator should be off the end of the list" << endl;
    if (L2.offEnd())
        cout << "Iterator is off the end of the list" << endl;
    else
        cout << "Iterator is not off the end of the list" << endl;

    //Testing removeIterator()
    cout << "\n**Testing removeIterator()**\n\n";
    L2.startIterator();
    L2.advanceIterator();
    cout << "Should print out 2 8 and then move to a new line: \n";
    L2.removeIterator();
    L2.printList();//2 8
    L2.startIterator();
    L2.advanceIterator();
    cout << "Should print out 2 and then move to a new line: \n";
    L2.removeIterator();//remove iterator at last
    L2.printList();//2
    L2.insertFirst(7);
    L2.startIterator();
    cout << "Should print out 2 and then move to a new line: \n";
    L2.removeIterator();//remove iterator at last
    L2.printList();//2
    cout << "Should print out empty list and then move to a new line: \n";
    L2.startIterator();
    L2.removeIterator();
    L2.printList();//empty

    //Testing insertIterator()
    cout << "\n**Testing insertIterator()**\n\n";
    L2.insertLast(9);
    L2.startIterator();
    cout << "Should print out 9 and then move to a new line: \n";
    L2.printList();
    L2.insertIterator(7);
    cout << "Should print out 9 7 and then move to a new line: \n";
    L2.printList();
    L2.insertIterator(3);
    cout << "Should print out 9 3 7 and then move to a new line: \n";
    L2.printList();

    //Testing reverseIterator()
    cout << "\n**Testing reverseIterator()**\n\n";
    L2.printList();
    L2.startIterator();
    L2.advanceIterator();
    L2.advanceIterator();
    L2.reverseIterator();
    cout << "The data in the second node is 3 : \n" << L2.getIterator() << endl << endl;

    //Testing overloading operator== and copy constructor
    cout << "\n**Testing overloading operator== and copy constructor**\n\n";
    L1.printList();
    L2.printList();
    if(L1==L2)
          cout << "Lists are equal!\n";
    else
          cout << "Lists are unequal!\n";
    List<int> L3(L2);
    L2.printList();
    L3.printList();
    if(L2==L3)
    	cout << "Lists are equal!\n";
    else
    	cout << "Lists are unequal!\n";
*/

	List<int> L5;
	List<int> L6;
    for (int i = 0; i <= 10; i++) { //inserting the the values 0 - 10 into L6
    	L6.insertLast(i);
      }
    //Testing reversePrint()
    cout << "\n**Testing reversePrint()**\n\n";
    cout << "Should print out 10 9 8 7 6 5 4 3 2 1 0 and then move to a new line: \n";
    L6.reversePrint();
    cout << "\nShould print nothing and then move to a new line: \n";
    L5.reversePrint();

    //Testing isSorted()
    cout << "\n\n**Testing isSorted()**\n\n";
    cout << "Should print out: List is sorted and then move to a new line: \n";
    if (L6.isSorted())
    {
    	cout << "List is sorted.\n";
    }
    else
    {
    	cout << "List is not sorted.\n";
    }
    List<int> L7;
    L7.insertLast(7);
    L7.insertLast(5);
    L7.insertLast(8);
    cout << "Should print out: List is not sorted and then move to a new line: \n";
    if (L7.isSorted())
    {
    	cout << "List is sorted.\n";
    }
    else
    {
    	cout << "List is not sorted.\n";
    }

    //Testing getIndex()
    cout << "\n**Testing getIndex()**\n\n";
    cout << "Assertion violated, the program should halt.\n";
    //L6.getIndex();
    cout << "Assertion violated, the program should halt.\n";
    //L5.getIndex();
    L6.startIterator();
    cout << "Should print out 1 and then move to a new line: \n";
    cout << L6.getIndex() << endl;
    L6.advanceIterator();
    L6.advanceIterator();
    cout << "Should print out 3 and then move to a new line: \n";
    cout << L6.getIndex() << endl;

    //Testing advanceToIndex()
    cout << "\n**Testing advanceToIndex()**\n\n";
   cout << "Current index is: " << L6.getIndex() << endl;
   cout << "Current iterator data is: " << L6.getIterator() << endl;
   L6.advanceToIndex(5);
   cout << "Should print out 4 and then move to a new line: \n";
   cout << L6.getIterator() << endl;
   cout << "Assertion violated, the program should halt.\n";
   //L6.advanceToIndex(14);
   cout << "Assertion violated, the program should halt.\n";
   //L5.advanceToIndex(4);


   //Testing linearSearch()
   cout << "\n**Testing linearSearch()**\n\n";
   cout << "Assertion violated, the program should halt.\n";
   //L5.linearSearch(3);
   cout << "Should print out -1 and then move to a new line: \n";
   cout << L6.binarySearch(12) << endl;
   cout << "Should print out 7 and then move to a new line: \n";
   cout << L6.linearSearch(6) << endl;

   //Testing binarySearch()
   cout << "\n**Testing binarySearch()**\n\n";
   cout << "Assertion violated, the program should halt.\n";
   //L5.binarySearch(3);
   cout << "Should print out -1 and then move to a new line: \n";
   cout << L6.binarySearch(11) << endl;
   cout << "Should print out 9 and then move to a new line: \n";
   cout << L6.binarySearch(8) << endl;


	return 0;
}

/*
**Testing reversePrint()**

Should print out 10 9 8 7 6 5 4 3 2 1 0 and then move to a new line:
10 9 8 7 6 5 4 3 2 1 0
Should print nothing and then move to a new line:


**Testing isSorted()**

Should print out: List is sorted and then move to a new line:
List is sorted.
Should print out: List is not sorted and then move to a new line:
List is not sorted.

**Testing getIndex()**

Assertion violated, the program should halt.
Assertion violated, the program should halt.
Should print out 1 and then move to a new line:
1
Should print out 3 and then move to a new line:
3

**Testing advanceToIndex()**

Current index is: 3
Current iterator data is: 2
Should print out 4 and then move to a new line:
4
Assertion violated, the program should halt.
Assertion violated, the program should halt.

**Testing linearSearch()**

Assertion violated, the program should halt.
Should print out -1 and then move to a new line:
-1
Should print out 7 and then move to a new line:
7

**Testing binarySearch()**

Assertion violated, the program should halt.
Should print out -1 and then move to a new line:
-1
Should print out 9 and then move to a new line:
9
*/
