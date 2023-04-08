#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL
using namespace std;

class List {

private:
    struct Node {
        int data;
        Node* next;

        Node(int newData){
            data = newData;
            next = NULL;
        }
    };

    Node* first;
    Node* last;
    int length;

public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: The initial size of the list is 0

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: The list -> null


    /**Accessors*/

    int getFirst() const;
    //Returns the first data in the list
    //Precondition: The size of the list is not 0

    int getLast() const;
    //Returns the last data in the list
    //Precondition: The size of the list is not 0


    bool isEmpty() const;
    //Determines whether a list is empty.

    int getLength() const;
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


    void insertFirst (int data);
    //Inserts a new data at the beginning of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: Size+1 and a new element is added

    void insertLast(int data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: Size+1 and a new element is added

    /**Additional List Operations*/

    void printList() const;
    //Prints to the console the value of each data in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty..
};
#endif /* LIST_H_ */



