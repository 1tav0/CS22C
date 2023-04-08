/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 4
 */

#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

template <class listdata> //list stores generic listdata, not any specific C++ type

class List {

private:
    struct Node {
    	listdata data;
        Node* next;
        Node* prev;

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
    void reversePrint(Node* node) const;
    //Helper function for the public reversePrint() function.
    //Recursively prints the data in a List in reverse.
    bool isSorted(Node* node) const;
    //Helper function for the public isSorted() function.
    //Recursively determines whether a list is sorted in ascending order.
    int binarySearch(int low, int high, listdata data) const;
    //Recursively search the list by dividing the search space in half
    //Returns the index of the element, if it is found in the List
    //Returns -1 if the element is not in the List
    //Post: The iterator location has not been changed

public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Constructs a new linked list object.
    //Postcondition: An empty list was created.

    List (const List &List);
    //Makes a copy of the list object

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: Freeing memory by deleting the linked list.

    /**Accessors*/

    listdata getFirst() const;
    //Returns the first data in the list
    //Precondition: The list must not be empty

    listdata getLast() const;
    //Returns the last data in the list
    //Precondition: The list must not be empty

    bool isEmpty() const;
    //Determines whether a list is empty.

    int getLength() const;
    //Returns the current length of the list

    listdata getIterator() const;
    //Returns the element currently pointed at by the iterator

    bool offEnd() const;
    //Returns whether the iterator is off the end of the list, i.e. is NULL

    bool operator==(const List& list);
    //Compares two lists to see if they are equal

    bool isSorted() const;
    //Wrapper function that calls the isSorted helper function to determine whether
    //a list is sorted in ascending order.
    //We will consider that a list is trivially sorted if it is empty.
    //Therefore, no precondition is needed for this function

    int getIndex() const;
    //Indicates the index of the Node where the iterator is currently pointing
    //Nodes are numbered starting at 1 through the size of the list
    //Pre: !offEnd()

    int linearSearch(listdata data) const;
    //Searchs the list, element by element, from the start of the List to the end of the List
    //Returns the index of the element, if it is found in the List
    //Does not call the indexing functions in the implementation
    //Returns -1 if the element is not in the List
    //Pre: length != 0
    //Post: The iterator location has not been changed

    int binarySearch(listdata data) const;
    //Returns the index where data is located in the List
    //Calls the private helper function binarySearch to perform the search
    //Pre: length != 0
    //Pre: List is sorted (must test on a sorted list)
    //Post: The iterator location has not been changed


    /**Manipulation Procedures*/

    void removeFirst();
    //Removes the value stored in first node in the list
    //Precondition: The list must not be empty
    //Postcondition: The first data is removed

    void removeLast();
    //Removes the value stored in the last node in the list
    //Precondition: The list must not be empty
    //Postcondition: The last data is removed

    void insertFirst (listdata data);
    //Inserts a new data at the beginning of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: The new data added to the front of the list

    void insertLast(listdata data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: The new data added to the end of the list

    void startIterator();
    //Moves the iterator to the start of the list

    void advanceIterator();
    //Moves the iterator up by one node

    void reverseIterator();
    //Moves the iterator down by one node

    void removeIterator();
    //Removes the element currently pointed to by the iterator. Iterator then points to NULL.

   	void insertIterator(listdata data);
   	//Inserts an element after the node currently pointed to by the iterator

   	void advanceToIndex(int index);
   	//Moves the iterator to the node whose index number is specified in the parameter
   	//Nodes are numbered starting at 1 through the size of the List
   	//Pre: size != 0
   	//Pre: index <= size

    /**Additional List Operations*/

    void printList() const;
    //Prints to the console the value of each data in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty..

    void reversePrint() const;
    //Wrapper function that calls the reverse helper function to print a list in reverse
    //prints nothing if the List is empty

};


template <class listdata>
List<listdata>::List()
{
	length = 0;
	first = NULL;
	last = NULL;
	iterator = NULL;
}
	//Default constructor; initializes and empty list
    //Postcondition: An empty list was created.

template <class listdata>
List<listdata>::List(const List &list)
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
            iterator->next->prev = iterator;
            iterator = iterator->next; //advance to this new node
        }
        last = iterator; //Why do I need this line of code?
        iterator = NULL;
    }
    length = list.length;
}

template <class listdata>
List<listdata>::~List()
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
	//Destructor. Frees memory allocated to the list
	//Postcondition: Freeing memory by deleting the linked list.

template <class listdata>
listdata List<listdata>::getFirst() const
{
	assert (length != 0);
	return first -> data;
}
    //Returns the first data in the list
    //Precondition: The list must not be empty

template <class listdata>
listdata List<listdata>::getLast() const
{
	assert (length != 0);
	return last -> data;
}
    //Returns the last data in the list
    //Precondition: The list must not be empty

template <class listdata>
bool List<listdata>::isEmpty() const
{
    return length == 0;
}
    //Determines whether a list is empty.

template <class listdata>
int List<listdata>::getLength() const
{
    return length;
}
    //Returns the size of the list

template <class listdata>
listdata List<listdata>::getIterator() const
{
	assert (iterator != NULL);
	return iterator -> data;
}
	//returns the element currently pointed at by the iterator

template <class listdata>
bool List<listdata>::offEnd() const
{
	if (iterator == NULL)
		return true;
	else
		return false;
}
	//returns whether the iterator is off the end of the list, i.e. is NULL

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
	//compares two lists to see if they are equal.

template <class listdata>
void List<listdata>::removeFirst()
{
	assert (length!=0);
	if(length == 1)
    {
    	delete first;
    	first = last = NULL;
    	length = 0;
    }
    else
    {
    	Node* temp = first;
    	first = first->next;
    	first->prev = NULL;
    	delete temp;
    	length--;
    }
}
    //Removes the value stored in first node in the list
    //Precondition: The list must not be empty
    //Postcondition: The first data is removed

template <class listdata>
void List<listdata>::removeLast()
{
	assert (length!=0);
	if (length == 1)
    {
    	delete last;
    	last = first = iterator = NULL;
    	length = 0;
    }
    else
    {
    	if (iterator == last)
    	{
    		iterator = NULL;
    	}
    	Node* temp = last;
    	last = last -> prev;
    	last->next = NULL; //set pointer to point at NULL rather than deallocated memory
    	delete temp;
    	length--;
    }
}
    //Removes the value stored in the last node in the list
    //Precondition: The list must not be empty
    //Postcondition: The last data is removed

template <class listdata>
void List<listdata>::insertFirst(listdata data)
{
	Node* N = new Node(data);
	if (length == 0)
	{
		last = first = N;
	}
    else
    {
    	N->next = first;
    	first->prev = N;
    	first = N;
    }
    	length++;
}
    //Inserts a new data at the beginning of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: The new data added to the front of the list

template <class listdata>
void List<listdata>::insertLast(listdata data)
{
    Node* N = new Node(data);
    if (length == 0)
    {
    	last = first = N;
    }
    else
    {
    	N->next = NULL;
    	N->prev = last;
    	last -> next = N;
    	last = N;
    }
    length++;
}
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: The new data added to the end of the list

template <class listdata>
void List<listdata>::startIterator()
{
	iterator = first;
}
	//moves the iterator to the start of the list

template <class listdata>
void List<listdata>::advanceIterator()
{
	assert (iterator != NULL);
	iterator = iterator->next;
}
	//moves the iterator up by one node

template <class listdata>
void List<listdata>::reverseIterator()
{
	assert (iterator != NULL);
	iterator = iterator->prev;
}
	//moves the iterator down by one node

template <class listdata>
void List<listdata>::removeIterator()
{
	assert(iterator != NULL);
	if (iterator == first) {
		removeFirst();
	}
	else if (iterator == last) {
		removeLast();
	}
	else {
	    iterator->prev->next = iterator->next;
	    iterator->next->prev = iterator->prev;
	    delete iterator;
	    iterator = NULL;
	    length--;
	}
}
	//removes the element currently pointed to by the iterator. Iterator then points to NULL.

template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
	assert(iterator != NULL);
	if (iterator == last)
	{
		insertLast(data);
	}
	else
	{
		Node* N = new Node(data);
		N->next = iterator->next;
	    N->prev = iterator;
	    iterator->next->prev = N;
	    iterator->next = N;
	    length++;
	}
}
	//inserts an element after the node currently pointed to by the iterator

template <class listdata>
void List<listdata>::printList() const
{
    Node* temp = first; //create a temporary iterator
    if (temp == NULL)
    {
    	cout << endl;
    }
    while (temp != NULL)
    {
    	cout << temp -> data << " ";
        temp = temp -> next;
        cout << endl << endl; //Move to a new line
    }
}
    	//Prints to the console the value of each data in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty
        //Prints a empty newline character if it's empty..

template <class listdata>
void List<listdata>::reversePrint(Node* node) const
{
	if(node)
	{
		reversePrint(node->next);
		cout << node->data << " ";
	}
}
//Helper function for the public reversePrint() function.
//Recursively prints the data in a List in reverse.

template <class listdata>
void List<listdata>::reversePrint() const
{
	reversePrint(first);
}
//Wrapper function that calls the reverse helper function to print a list in reverse
//prints nothing if the List is empty

template <class listdata>
bool List<listdata>::isSorted(Node* node) const
{
	if(node->next == NULL)
	{
		return true;
	}
	else if ((node->data) > (node->next->data))
	{
		return false;
	}
	else
	{
		return isSorted(node->next);
	}
}
//Helper function for the public isSorted() function.
//Recursively determines whether a list is sorted in ascending order.

template <class listdata>
bool List<listdata>::isSorted() const
{
	if(isEmpty())
	{
		return true;
	}
	else
	{
		return isSorted(first);
	}
}
//Wrapper function that calls the isSorted helper function to determine whether
//a list is sorted in ascending order.
//We will consider that a list is trivially sorted if it is empty.
//Therefore, no precondition is needed for this function

template <class listdata>
int List<listdata>::getIndex() const
{
	assert(length != 0);
	assert(!offEnd());
	Node* temp = first;
	int index = 1;
	while (temp != iterator)
	{
	    index ++;
	    temp = temp->next;
	}
	return index;
}
//Indicates the index of the Node where the iterator is currently pointing
//Nodes are numbered starting at 1 through the size of the list
//Pre: !offEnd()

template <class listdata>
void List<listdata>::advanceToIndex(int index)
{
	assert(length != 0);
	assert(index <= length);
	Node* temp = first;
	for (int i = 1; i <= index; i++)
	{
	    iterator = temp;
	    temp = temp->next;
	}
}
//Moves the iterator to the node whose index number is specified in the parameter
//Nodes are numbered starting at 1 through the size of the List
//Pre: size != 0
//Pre: index <= size

template <class listdata>
int List<listdata>::binarySearch(int low, int high, listdata data) const
{
	if(high < low)
	{
		return -1;
	}
	int mid = low + (high - low) / 2;
	Node* temp = first;
	for (int i = 1; i < mid; i ++)
	{
		temp = temp->next;
	}
	if((temp->data) == data)
	{
		return mid;
	}
	else if(data < (temp->data))
	{
		return binarySearch(low,mid-1, data);
	}
	else
	{
		return binarySearch(mid+1, high, data);
	}
	return -1;
}
//Recursively search the list by dividing the search space in half
//Returns the index of the element, if it is found in the List
//Returns -1 if the element is not in the List
//Post: The iterator location has not been changed

template <class listdata>
int List<listdata>::binarySearch(listdata data) const
{
	assert(!isEmpty());
	if(!isSorted())
	{
		return -1;
	}
	else
	{
		return binarySearch(first->data, last->data, data);
	}
}
//Returns the index where data is located in the List
//Calls the private helper function binarySearch to perform the search
//Pre: length != 0
//Pre: List is sorted (must test on a sorted list)
//Post: The iterator location has not been changed

template <class listdata>
int List<listdata>::linearSearch(listdata data) const
{
	assert(!isEmpty());
	Node* temp = first;
	int index = 1;
	while(temp != NULL)
	{
		if((temp->data) == data)
		{
			return index;
		}
		else
		{
			index ++;
			temp = temp->next;
		}
	}
	return -1;
}
//Searchs the list, element by element, from the start of the List to the end of the List
//Returns the index of the element, if it is found in the List
//Does not call the indexing functions in the implementation
//Returns -1 if the element is not in the List
//Pre: length != 0
//Post: The iterator location has not been changed




#endif /* LIST_H_ */
