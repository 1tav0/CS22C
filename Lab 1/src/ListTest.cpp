#include <iostream>
#include "List.h"
using namespace std;

int main() {

    //instantiate two lists for testing purposes
    List L1;
    List L2;

    //Testing insertFirst() and printList()
    cout << "**Testing InsertFirst**\n\n";
    cout << "Should print out an empty line: \n";
    L1.printList(); //Should not print any message to the screen, just an empty line


    L1.insertFirst(0);
    cout << "Should print out 0 and then move to a new line: \n";
    L1.printList();

    L1.insertFirst(1);
    cout << "should print out 1 0 and then move to a new line: \n";
    L1.printList();

    for (int i = 1; i <= 10; i++) { //inserting the the values 1-10 into L1
        L1.insertFirst(i);
    }
    cout << "Should print out 10 9 8 7 6 5 4 3 2 1 0 and then move to a new line: \n";
    L1.printList();

    cout << "should print out 11 and then move to a new line" << endl;
    cout << L1.getLength() << endl;

    cout << "should print out 10 and then move to a new line " << endl;
    cout << L1.getFirst() << endl;

L1.insertLast(7);
cout << "should print out 10 9 8 7 6 5 4 3 2 1 0 7  and then move to a new line:" << endl;
L1.printList();

L1.insertLast(8);
cout << "should print out 10 9 8 7 6 5 4 3 2 1 0 7 8 and then move to a new line:" << endl;
L1.printList();

L1.removeFirst();
cout << "should print out 9 8 7 6 5 4 3 2 1 0 7 8 and then move to a new line:" << endl;
L1.printList();

cout << "should print out 8 and then move to a new line: " << endl;
    cout << L1.getLast() << endl;


L1.removeFirst();
cout << "should print out 8 7 6 5 4 3 2 1 0 7 8 and then move to a new line: " << endl;
L1.printList();

L1.removeLast();
cout << "should print out 8 7 6 5 4 3 2 1 0 7 and then move to a new line:" << endl;
L1.printList();

L1.removeLast();
cout << "should print out 8 7 6 5 4 3 2 1 0  and then move to a new line:" << endl;
L1.printList();

cout << "should print out 8 and then move to a new line: " << endl;
        cout << L1.getFirst() << endl;

cout << "should print out 0 and then move to a new line: " << endl;
            cout << L1.getLast() << endl;


cout << "should print out 9 and then move to a new line:" << endl;
cout << L1.getLength() << endl;






}
