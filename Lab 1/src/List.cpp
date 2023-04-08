#include "List.h"
#include <iostream>

using namespace std;

//Constructor
List::List() {
    first = NULL;
    last = NULL;
    length = 0;
}
//Destructor
List::~List()
{
    Node* b = first;
    Node* a = NULL; //a stands for "after" (i.e. after b)
    while (b != NULL)
    {
        a = b->next; //move a to node after b
        delete b; //remove b (you know it is not NULL from if)
        b = a; //b "catches up" with a (both point to same place in list)
    }
}

// printList()
void List::printList()const
{
    Node* temp = first; //create a temporary iterator
    while (temp != NULL) {

        cout <<temp->data<<" ";
        temp = temp->next;       //Add two lines of code here

        //Hint: One statement should contain a cout

    }
    cout << endl; //What does this do? Answer: After while loop, print a new line

}
//insertFirst()
void List::insertFirst(int data)
{
    Node* N = new Node(data);
    if (length == 0)  // to make sure the list is not empty
    {
        first = N;
        last = N;
    }
    else
    {
        N->next = first;
        first = N;
    }
    length++;
}
//insertLast()
void List::insertLast(int data)
{
    Node* N = new Node(data);
    if (length==0)
    {
        first = N;
        last = N;

    }
    else
    {
        last-> next = N;
        last = N;
    }

    length++;
}
// removeFirst
void List::removeFirst()
{
    if(length == 0)
    {
        cout << "removeFirst : List is empty, no data to remove." << endl;
        return;
    }
    else if(length == 1)
    {
        delete first;
        first = last = NULL;
        length = 0;
    }
    else
    {
        Node* temp = first;
        first = first->next;
        delete temp;
        length--;
    }
}
//removeLast
void List::removeLast()
{
    if (length==0){

    cout << "removeLast: List is empty. No data to remove." << endl; //fill in the line here

        } else if (length==1) {

        delete first;

        first = last = NULL;

		length = 0;       //fill in the missing lines here

    } else {
        Node* temp = first;
        while(temp->next != last) //move temp to second to last node in list
        {
            temp = temp->next;

        }
        delete last;

        last = temp; //set last to be the former second to last node stored in temp
        last->next = NULL; //set pointer to point at NULL rather than deallocated memory

        length--;

    }

}
// isEmpty

bool List::isEmpty() const
{
    return (length == 0);
}
// getLength()
int List::getLength() const
{
	return length;
}

// getFirst()
int List::getFirst() const
{
    return first -> data;

         }
// getLast()
int List::getLast() const
{
	return last->data;
}






