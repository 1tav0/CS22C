#include <iostream>
#include <cstddef>
#include <assert.h>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main()
{
	//instantiate two stacks for testing purposes
	Stack S1;
	Stack S2;

	//Testing push()
	cout << "\n**Testing push()**\n\n";
	cout << "should print out hard work I so money love I" << endl;
	S1.push("I");
	S1.push("love");
	S1.push("money");
	S1.push("so");
	S1.push("I");
	S1.push("work");
	S1.push("hard");
	S1.print();

	//Testing pop()
	cout << "\n**Testing pop()**\n\n";
	cout << "should print out error message" << endl;
	//S2.pop();
	cout << "should print out work I so money love I  " << endl;
	S1.pop();
	S1.print();


	// Testing getSize()
	cout << "\n**Testing getSize()**\n\n";
	cout << "Should printout 6" << endl;
	cout << S1.getSize() << endl;
	cout << "Should printout 0" << endl;
	cout << S2.getSize() << endl;

	// Testing isEmpty()
	cout << "\n**Testing isEmpty()**\n\n";
	cout << "should print out 0" << endl;
	cout << S1.isEmpty() << endl;
	cout << "should print out 1" << endl;
	cout << S2.isEmpty() << endl;

	// Testing getTop()
	cout << "\n**Testing getTop()**\n\n";
	cout << "Should give error message" << endl;
	//cout << S2.getTop() << endl;
	cout << "should print out work" << endl;
	cout << S1.getTop() << endl;



}




