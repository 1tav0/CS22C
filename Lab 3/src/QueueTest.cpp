//============================================================================
// Name        : Queue.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "queue.h"
using namespace std;

int main() {
	Queue <int> Q1, Q2;

	//Testing enqueue()
	cout << "\n** Testing enqueue()** \n\n";
	cout << "Should print 5 7 2 : \n";
	Q1.enqueue(5);
	Q1.enqueue(7);
	Q1.enqueue(2);
	Q1.printQueue();

	//Testing dequeue()
	cout << "\n** Testing dequeue()** \n\n";
	cout << "Should print 7 2 : \n";
	Q1.dequeue();
	Q1.printQueue();

	//Testing operator==
	cout << "\n** Testing operator== **\n\n";
	cout << "Should print Queues are not the same: ";
	if(Q1==Q2)
		cout << "Queues are the same.\n";
	else
		cout << "Those two Queues are not the same.\n";
	Q2.enqueue(7);
	Q2.enqueue(2);
	cout << "Should print Queues are the same: ";
	if(Q1==Q2)
		cout << "Queues are the same.\n";
	else
		cout << "Those two Queues are not the same.\n";

	//Testing getFront()
	cout << "\n** Testing getFront() **\n\n";
	cout << "Should print 7 : \n";
	cout << Q2.getFront() << endl;
	cout << "Assertion violated, error message.\n";
	Q2.dequeue();
	Q2.dequeue();
	//Q1.getFront();

	//Testing getSize()
	cout << "\n** Testing getSize() **\n\n";
	cout << "Should print 2 : \n";
	cout << Q1.getSize() << endl;
	cout << "\n** Testing getSize() **\n\n";
	cout << "Should print 0 : \n";
	cout << Q2.getSize() << endl;

	// **TEsting copy constructor

		cout << "\nTesting copy constructor\n\n";

		cout <<" should print: 7 2\n ";
		Queue<int> Q3(Q1);
		Q3.printQueue();


	return 0;
}
