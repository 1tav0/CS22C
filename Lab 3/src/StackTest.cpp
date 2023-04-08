///*
// * Octavio Cruz
// * Gia Trinh
// *
// *  CIS 22C
// *  Assignment 3
// */
//
//#include <iostream>
//#include "Stack.h"
//using namespace std;
//
//int main() {
//
//	Stack<string> S1, S2;
//
//	//Testing push()
//	cout << "\n** Testing push()** \n\n";
//	cout << "Should print : and you did well too!\n";
//	S1.push("and you did well too!\n");
//	S1.printStack();
//	cout << "Should print : I did well and you did well too!\n";
//	S1.push("I did well");
//	S1.printStack();
//
//	//Testing pop()
//	cout << "\n** Testing pop() **\n\n";
//	cout << "Should print : and you did well too!\n";
//	S1.pop();
//	S1.printStack();
//	cout << "Assertion violated, error message.\n";
//	//S2.pop();
//
//	//Testing operator==
//	cout << "\n** Testing operator== **\n\n";
//	cout << "Should print Stacks are not the same: ";
//	if(S1==S2)
//		cout << "Stacks are the same.\n";
//	else
//		cout << "Those two stacks are not the same.\n";
//
//	S2.push("and you did well too!\n");
//	cout <<"Should print stacks are the same: ";
//	if(S1==S2) {
//		cout << "Stacks are the same.\n";
//	}
//	else {
//		cout << "Those two stacks are not the same.\n";
//	}
//
//	//Testing peek()
//	cout << "\n** Testing peek() **\n\n";
//	cout << "Should print : and you did well too!\n";
//	cout << S1.peek() << endl;
//	cout << "Assertion violated, error message.\n";
//	S1.pop();
//	//S1.peek();
//
//	//Testing getSize()
//	cout << "\n** Testing getSize() **\n\n";
//	cout << "Should print 0:  ";
//	cout << S1.getSize() << endl;
//	cout << "Should print 1:  ";
//	cout << S2.getSize() << endl;
//
//	//Testing isEmpty()
//	cout << "\n** Testing isEmpty() **\n\n";
//	cout << "Should print Stack is empty: ";
//	if (S1.isEmpty()) {
//		cout << "Stack is empty.\n";
//	}
//	else {
//		cout << "Stack is not empty.\n";
//	}
//	cout << "Should print Stack is not empty: ";
//	if (S2.isEmpty()) {
//		cout << "Stack is empty.\n";
//	}
//	else {
//		cout << "Stack is not empty.\n";
//	}
//
//	// **TEsting copy constructor
//
//	cout << "\nTesting copy constructor\n\n";
//	S2.printStack();
//
//	cout <<" should print: and you did well too!\n ";
//	Stack<string> S3(S2);
//	S3.printStack();
//
//	return 0;
//}
//
///*
// ** Testing push()**
//
//Should print : and you did well too!
//and you did well too!
//
//Should print : I did well and you did well too!
//I did well and you did well too!
//
//
//** Testing pop() **
//
//Should print : and you did well too!
//and you did well too!
//
//Assertion violated, error message.
//
//** Testing operator== **
//
//Should print Stacks are not the same: Those two stacks are not the same.
//Should print stacks are the same: Stacks are the same.
//
//** Testing peek() **
//
//Should print : and you did well too!
//and you did well too!
//
//Assertion violated, error message.
//
//** Testing getSize() **
//
//Should print 0:  0
//Should print 1:  1
//
//** Testing isEmpty() **
//
//Should print Stack is empty: Stack is empty.
//Should print Stack is not empty: Stack is not empty.
//*/
//
//
//
