/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 7
 */

#include <iostream>
#include "HashTable.h"
#include "List.h"
#include <iomanip>
#include <string>
#include <assert.h>
using namespace std;


int HashTable::hash(string key) const
{
	int sum = 0;
	for (int i=0; i < key.length(); i++)
	{
		sum += key[i];
	}
	return sum % SIZE;
}

int HashTable::countBucket(int index) const
{
	assert(0 <= index && index < SIZE);
	return Table[index].getLength();
}

int HashTable::search(Book b) const
{
	int index = hash(b.get_title() + b.get_author());
	if(Table[index].isEmpty() || Table[index].linearSearch(b) == -1)
	{
		return -1;
	} else
	{
		return index;
	}
}

void HashTable::insert(Book b)
{
	int index = hash(b.get_title() + b.get_author());
	Table[index].insertLast(b);
}

void HashTable::remove(Book b)
{
	int index = hash(b.get_title() + b.get_author());
	if(countBucket(index) == 0)
	{
		cout << "This book is not in the table." << endl;
	}
	else if(countBucket(index) == 1)
	{
		Table[index].removeFirst();
	}
	else
	{
		Table[index].advanceToIndex(Table[index].linearSearch(b));
		Table[index].removeIterator();
	}
}

void HashTable::printBucket(ostream& out, int index) const
{
	assert(0 <= index && index < SIZE);
	Table[index].printList();
}

void HashTable::printTable(ostream& out) const
{
	for (int i = 0; i < SIZE; i++)
	{
		if (!Table[i].isEmpty())
		{
			Book temp = Table[i].getFirst();
			out << "Group: " << i+1 << endl;
			out << temp.get_title() << " by " << temp.get_author() << endl;
			out << "$" << temp.get_price() << endl;
			out << "ISBN#: " << temp.get_isbn() << endl << endl;
			out << "+" << countBucket(i)-1<< " more book(s)" << endl;
			out << endl << endl << endl;
		}
	}
}





