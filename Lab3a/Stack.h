/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 3
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <cstddef>
#include <assert.h>

using namespace std;

template <class stackdata>
class Stack
{
    public:
        /**constructors and destructors*/

        Stack();

        //initializes an empty stack
        //post: an empty stack created with all fields assigned default values

        Stack(const Stack &S);
        //initializes this stack to have same elements as S
        //post: a deep copy of the stack S


        ~Stack();
        //frees memory allocated to the stack
        //post: memory for stack has been freed

        /**manipulation procedures*/

        void pop();
        //removes an element from the top of the stack
        //pre: size != 0
        //post: an element has been removed from the top of the stack

        void push(stackdata data);
        //adds an element to the top of the stack
        //post: an element added to the top of the stack

        /**accessors*/


       bool operator==(const Stack &S);
       //returns whether this stack is equal to another stack S

       stackdata peek() const;
       //returns the element at the top of the stack
       //pre: size != 0

       int getSize() const;
       //returns the size of the stack

       bool isEmpty() const;
       //returns whether the stack is empty


       /**additional operations*/

       void printStack() const;
       //prints the elements in the stack each element separate by a blank space to stdout

    private:
       struct Node {
           stackdata data;
           Node* next;

           Node(stackdata d){
               data = d;
               next = NULL;
           }
       };

       Node* top;
       int size;

};

template<class stackdata>
Stack<stackdata>::Stack()
{
	top = NULL;
	size = 0;
}

template<class stackdata>
Stack<stackdata>::Stack(const Stack &S)

{
	if (S.top == NULL)
	{
		top = NULL;
	}
	else
	{
		top = new Node;
		top->data = S.top->data;
		Node* temp1 = S.top();
		Node* temp2 = top;
		while (temp1->next != NULL)
		{
			temp2 -> next = new Node;
			temp2 = temp2 -> next;
			temp1 = temp1 -> next;
			temp2->data = temp1->data;
		}
	}
	size = S.top();
}


template<class stackdata>
Stack<stackdata>::~Stack()

{
	Node* temp = top;
	Node* temp1 = top;
	while (temp != NULL)
	{
		temp =temp->next;
		delete temp1;
		temp1 = temp;
	}
}

template<class stackdata>
void Stack<stackdata>::pop()
{
	assert ( size!=0);
	if (size == 0)
	{
		cout << " The stack is empty " << endl;
	}
	else
	{
		Node* temp = top -> next;
		delete top;
		top = temp;
	}
	size --;
}

template<class stackdata>
void Stack<stackdata>::push(stackdata data)
{
	Node* N = new Node(data);
	if (size == 0)
	{
		top = N;
	}
	else
	{
		N->next = top;
		top =N;
	}
	size ++;
}

template<class stackdata>
bool Stack<stackdata>:: operator == (const Stack &S)
{
	if(size != S.size)
		return false;
	else
	{
		Node * temp1 =  top;
		Node * temp2 =S.top;

		while(temp1 != NULL)
		{
			if (temp1->data != temp2->data)
				return false;
			else
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
			}

		}
		return true;
	}
}

template<class stackdata>
stackdata Stack<stackdata>::peek() const
{
	assert ( size != 0);
	return top-> data;
}

template<class stackdata>
bool Stack<stackdata>::isEmpty() const
{
if (size == 0) {
	return true;
}
else {
	return false;
}

}
template<class stackdata>
int Stack<stackdata>::getSize() const
{
	return size;
}

template<class stackdata>
void Stack<stackdata>::printStack() const
{
	Node * temp =  top;
	while ( temp != NULL){
		cout << temp-> data << " ";
		temp = temp->next;
	}
	cout << endl;
}

#endif /* STACK_H_ */

