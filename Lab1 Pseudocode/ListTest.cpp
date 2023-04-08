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
    for (int i = 1; i <= 10; i++) { //inserting the the values 1-10 into L1
        L1.insertFirst(i);
    }

    cout << "Should print out 10 9 8 7 6 5 4 3 2 1 0 and then move to a new line: \n";
    L1.printList();


}
