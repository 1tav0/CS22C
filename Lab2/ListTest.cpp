/**

* Octavio Cruz

* CIS 22C, Lab 2

*/

//#include <iostream>
//#include "List.h"
//
//using namespace std;
//
//int main() {
//
//    //instantiate two lists for testing purposes
//
//	   List<int> L1;
//     List<string> L2;
//
//	  Testing insertStart() and print()
//    cout << "**Testing InsertFirst**\n\n";
//   cout << "Should print out an empty line: \n";
//  L1.printList(); //Should not print any message to the screen, just an empty line
//
//
//  L1.insertFirst(0);
//  cout << "Should print out 0 and then move to a new line: \n";
//  L1.printList();
//  for (int i = 1; i <= 10; i++) { //inserting the the values 1-10 into L1
//      L1.insertFirst(i);
//  }
//
//  cout << "Should print out 10 9 8 7 6 5 4 3 2 1 0 and then move to a new line: \n";
//  L1.printList();
//
//	Testing insertLast();
//	L1.insertLast(0);
//  cout << "Should print out 0 at end of the list and then move to a new line: \n";
//  L1.printList();
//  for (int i = 1; i<=10; i++){
//      L1.insertLast(i);
//  }
//  cout <<"Should print out 0 1 2 3 4 5 6 7 8 9 10 at end of the list and then move to a new line: \n";
//  L1.printList();
//
//  Testing startIterator and getIterator
//  L1.startIterator();
//  cout <<"Should print 10:" << L1.getIterator()<< endl;
//
//  Testing advanceIterator
//  L1.advanceIterator();
//  cout <<"Should print 9: " <<L1.getIterator()<<endl;
//
//
// 	Testing advanceIterator
//  L1.advanceIterator();
//    cout <<"Should print 8: " <<L1.getIterator()<<endl;
//  Testing reverseIterator
//  L1.reverseIterator();
//    cout <<"Should print 9: " << L1.getIterator()<<endl;
//
//  Testing getStart
//    cout << "Should print 9: " << L1.getFirst() << endl;
//
//  Testing getStop
//   cout <<"Should print 9: " << L1.getLast() << endl;
//
//  Testing getSize
//  cout <<"Should print 22: " << L1.getLength() << endl;
//
//
//
//
//
//
//		L.insertFirst(5);
//	    L.printList();
//	    L.insertFirst(6);
//		L.printList();
//
//
//
//	   L2.insertFirst("hi");
//
//	   L2.insertFirst("hello");
//	   L2.printList();
//
//		List<char> L3;
//
//		L3.insertFirst('A');
//		L3.insertFirst('B');
//		L3.printList();
//
//		List<doubles> L4;
//		L4.insertFirst(5.2);
//	    L4.insertLast(8.1);
//	    L4.insertFirst(2.6);
//	    cout << "The list should contain: 2.6 5.2 8.1:" << endl;
//	    L4.printList();
//		List<double> L_copy(Lo);
//	    cout << "The copy of the list should contain: 2.6 5.2 8.1:" << endl;
//	    L_copy.printList();
//
//		List<int> L_original;
//	    L_original.insertFirst(5);
//	    L_original.insertLast(8);
//	    L_original.insertFirst(2);
//
//	    cout << "The list should contain: 2 5 8:" << endl;
//	    L_original.printList();
//
//	    List<int> L_copy(L_original); //calling the copy constructor to make a copy of the original list
//	    //Alternately: List L_copy = L_original; will also call copy constructor
//
//	    cout << "The copy of the list should contain: 2 5 8:" << endl;
//	    L_copy.printList();
//
//	    return 0;
//}
//
// should print out
// **Testing InsertFirst**
// Should print out an empty line:
// Should print out 0 and then move to a new line:
// 0
// Should print out 10 9 8 7 6 5 4 3 2 1 0 and then move to a new line:
// 10 9 8 7 6 5 4 3 2 1 0
// Should print out 0 at end of the list and then move to a new line:
// 0
// Should print out   0 1 2 3 4 5 6 7 8 9 10 at end of the list and then move to a new line:
// 10 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9 10
// Should print 10:
// 10
// Should print 9:
// 9
// Should print 8:
// 8
// Should print 9:
// 9
// Should print 9:
// 9
// Should print 9:
// 9
// Should print 22:
// 22
// 5
// 5 6
// The list should contain: 2.6 5.2 8.1:
// 2.6 5.2 8.1
// The copy of the list should contain: 2.6 5.2 8.1:
// 2.6 5.2 8.1
// The list should contain: 2 5 8:
// 2 5 8
// The copy of the list should contain: 2 5 8:
// hi hello
// A B

