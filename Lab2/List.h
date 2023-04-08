/**

* Octavio Cruz

* CIS 22C, Lab 2

*/

#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL
#include <assert.h>  //for assert
#include <iostream>
#include "List.h"
using namespace std;

template <class listdata> //list stores generic listdata, not any specific C++ type

class List {  // 1st

private:   //2nd
    struct Node {          //declare a data structure that will be used for nodes
        listdata data;
        Node* next;			//pointer to the next node
        Node* prev;
       /* struct ListNode
        * {
        * double value;
        * ListNode *next;
        */

        Node(listdata newData){
            data = newData;
            next = NULL;
            prev = NULL;
        }
    };



    Node* first;
    Node* last;
    Node* iterator;
    int length;

public:

    /**Constructors and Destructors and copy constructor*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: The initial size of the list is 0

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: The list -> null

    List(const List &list);
//copy constructor

    /**Accessors*/


    listdata getFirst();
    //Returns the first data in the list
    //Precondition: The size of the list is not 0

    listdata getLast();
    //Returns the last data in the list
    //Precondition: The size of the list is not 0


    bool isEmpty();
    //Determines whether a list is empty.

    int getLength();
    //Returns the size of the list

    /**Manipulation Procedures*/
    void removeFirst();
    //Removes the value stored in first node in the list
    //Precondition: the size of the list is not zero
    //Postcondition:  The last element in the list is removed
    // 			     Size - 1


    void removeLast();
    //Removes the value stored in the last node in the list
    //Precondition: the size of the list is not zero
    //Postcondition: The last element in the list is removed
    //   			 Size - 1


    void insertFirst (listdata data);
    //Inserts a new data at the beginning of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: Size+1 and a new element is added

    void insertLast(listdata data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: Size+1 and a new element is added

    void move(int sourceLine, int destinationLine);
    // moves data from sourveline to destinationline


    /**Additional List Operations*/

    void printList() ;
    //Prints to the console the value of each data in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty..

    void printNumberedList() ;

    void startIterator();

    listdata getIterator();

    bool offEnd();

    void advanceIterator();

    void removeIterator();

    void insertIterator(listdata data);

    bool operator == (const List &list);

    void reverseIterator();

};

//Constructor
template <class listdata>
List<listdata>::List() {
    first = NULL;
    last = NULL;
    iterator = NULL;
    length = 0;
}


//Destructor
template <class listdata>
List<listdata>::~List()
{
    Node* b = first;
    Node* a; //a stands for "after" (i.e. after b)
    while (b != NULL)
    {
        a = b->next; //move a to node after b
        delete b; //remove b (you know it is not NULL from if)
        b = a; //b "catches up" with a (both point to same place in list)
    }
}

// copy constructor
template <class listdata>
List<listdata>::List(const List &list) //orlength(list.length)
{

    if(list.first == NULL) //If the original list is empty, make an empty list for this list
    {
        first = last = iterator = NULL;
    }
    else
    {
        first = new Node(list.first->data); //calling Node constructor
        Node* temp = list.first; //set a temporary node pointer to point at the first of the original list
        iterator = first; //set iterator to point to first node of the new list

        while(temp->next != NULL)
        {

            temp = temp->next; //advance up to the next node in the original list
            iterator->next = new Node(temp->data); //using node constructor to create new node w/ copy of data
            iterator = iterator->next; //advance to this new node

        }

        last = iterator; //Why do I need this line of code?
        iterator = NULL;

    }

    length = list.length;
}

// printList()
template <class listdata>
void List<listdata>::printList()
{
    Node* temp = first; //create a temporary iterator
    while (temp != NULL) {

        cout <<temp->data<< endl;
        temp = temp->next;       //Add two lines of code here

    }
    cout << endl; //What does this do? Answer: After while loop, print a new line

}

//printNumberedList() ;
template <class listdata>
void List<listdata>::printNumberedList()
{
    Node* temp = first; //create a temporary iterator
    int i=1;
    while (temp != NULL) {

        cout << i << ". " << temp->data<<  endl;
        temp = temp->next;       //Add two lines of code here
        i++;
    }
    cout << endl; //What does this do? Answer: After while loop, print a new line

}

//startIterator
template <class listdata>
void List<listdata>::startIterator()
{
    iterator = first;
}

//removeIterator
template <class listdata>
void List<listdata>::removeIterator()
{
	assert(!isEmpty());
    if (offEnd())
    {
    	cout<<"Error! The iterator is off the end of the List!/n";
    }

    else if (iterator == first) {
        removeFirst();
    }
    else if(iterator == last) {
        removeLast();
    }
    else
    {
        iterator->prev->next = iterator->next;
        iterator->next->prev = iterator->prev;
        delete iterator;
        iterator = NULL;
        length--;
    }

}

//insertIterator
template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
    if (offEnd())
    {
    	cout<<"Error! The iterator is off the end of the List!/n";
    }
    else if (iterator == last) {
        insertLast(data);
    }
    else{
        Node* N = new Node(data);
        N->prev = iterator;
        N->next = iterator->next;
        iterator->next = N;
        N->next->prev = N;
        length++;
    }
}

//reverseIterator()
template<class listdata>
void List<listdata>::reverseIterator(){
	assert(!offEnd());
		iterator=iterator->prev;

}


//getIterator()
template<class listdata>
listdata List<listdata>::getIterator()
{
	assert(!isEmpty());
	assert(iterator!= NULL);
	return iterator ->data;
}

/*template<class listdata>
listdata List<listdata>::getIterator1(int numline)
{
	assert(!isEmpty());
	iterator=first;
	for(int i=1;i<numline;i++)
	{
		assert(iterator!= NULL);
		iterator=iterator->next;
	}

	return iterator ->data;
}
*/				//this is wrong, its for me to keep track of this mistake



//advanceIterator
template<class listdata>
void List<listdata>::advanceIterator()
{
	assert(!offEnd());
	assert(iterator!=NULL);
	iterator = iterator->next;

}


//insertFirst()
template <class listdata>
void List<listdata>::insertFirst(listdata data)
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
        first->prev = N;
        first = N;
    }
    length++;
}
//insertLast()
template <class listdata>
void List<listdata>::insertLast(listdata data)
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
        N -> prev = last;
        last = N;
    }

    length++;
}

/*template <class listdata>
void List<listdata>::move(int sourceLine, int destinationLine){
	assert(!isEmpty());  //if(length == 0)
	if(length == 1){
		//nothing
	}

	startIterator();   // deleted this iterator must start again
	for (int i = 1; i<sourceLine; i++, advanceIterator());

	listdata storeData = getIterator();
	L.removeIterator();

	if (destinationLine>sourceLine){
		destinationLine --;
	}

	startIterator();
		for (int i = 1; i<destinationLine; i++, advanceIterator());

	insertIterator(storeData);

	}*/    //this is also wrong.

// removeFirst
template <class listdata>
void List<listdata>::removeFirst()
{
	assert(!isEmpty());  //if(length == 0)
	if(length == 1)
    {
        delete first;
        first = last = iterator = NULL;
        length = 0;
    }
    else
    {
    	if (iterator == first)
    		iterator = NULL;
        Node* temp = first;   //store pointer to first so we don't lose access to it
        first = first->next;   //advance the pointer
        delete temp;		//free the memory for the original first node
        first -> prev = NULL;
        length--;
    }
}
//removeLast
template <class listdata>
void List<listdata>::removeLast()
{
    //if (length == 0){cout << "removeLast: List is empty. No data to remove." << endl; //fill in the line here}


	assert (!isEmpty());
	if (length==1) {

        delete first;

        first = last = iterator = NULL;

		length = 0;       //fill in the missing lines here

    } else {
    	if (iterator == last)
    	    		iterator = NULL;

        Node* temp = last;
        last = last->prev;
        delete temp;
        last->next = NULL; //set pointer to point at NULL rather than deallocated memory

        length--;

    }

}

// isEmpty
template <class listdata>
bool List<listdata>::isEmpty()
{
    return (length == 0);
}

// getLength()
template <class listdata>
int List<listdata>::getLength()
{
	return length;
}

// getFirst()
template <class listdata>
listdata List<listdata>::getFirst()
{
	assert(!isEmpty());
    return first -> data;

         }
// getLast()
template <class listdata>
listdata List<listdata>::getLast()
{
	assert(!isEmpty());
	return last->data;
}

//offEnd
template<class listdata>
bool List<listdata>::offEnd()
{
	if(iterator == NULL)
		return true;
	else
		return false;
}

// == operator
template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(length != list.length)
        return false;
    Node* temp1 = first;
    Node* temp2 = list.first;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;



}

#endif /* LIST_H_ */



