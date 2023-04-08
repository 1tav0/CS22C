/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 7
 */


#include <iostream>
#include <ostream>
#include <iomanip>
#include "HashTable.h"
#include "Book.h"
#include "List.h"
#include <cstddef>
#include <assert.h>
#include <string>

using namespace std;

//int main()
//{
//	HashTable ht;
//	Book pp("Pride and Prejudice", "Jane Austen", 4.95, 1234567);
//	Book c("Contact", "Carl Sagan", 9.95, 99993339);
//    Book hg("The Hunger Games", "Suzanne Collins", 13.55, 12388888);
//    Book hp("Harry Potter", "J.K. Rowlings", 12.99, 55555678);
//    Book mhc("The Man in the High Castle", "Philip K Dick", 15.95, 95959595);
//    Book bh("Bleak House", "Charles Dickens", 8.00, 473890238);
//
//    ht.insert(pp);
//    ht.insert(c);
//    ht.insert(hg);
//    ht.insert(mhc);
//    ht.insert(bh);
//
//    //Testing hash()
//    cout << "**Testing hash()**\n\n";
//    cout<<"The hash value for the book 'Contact' by 'Carl Sagan' in the Hash table is: \n";
//    cout << ht.hash("The Hunger GamesSuzanne Collins") << endl;
//
//    //Testing countBucket()
//    cout << "\n**Testing countBucket()**\n\n";
//    cout<<"The number of bucket for index of 9 is: "<< ht.countBucket(9) << endl;
//
//    //Testing printBucket()
//    cout << "\n**Testing printBucket()**\n\n";
//    ht.printBucket(cout, 9);
//
//    //Testing printTable()
//    cout << "\n**Testing printTable()**\n\n";
//    ht.printTable(cout);
//
//    //Testing search()
//    cout << "\n**Testing search()**\n\n";
//    cout<<"The index for book 'Contact' in the Hash table is: \n"<< ht.search(c) << endl;
//    cout<<"The index for book 'Pride and prejudice' in the Hash table is: \n"<< ht.search(pp) << endl;
//
//    //Testing remove()
//    cout << "\n**Testing remove()**\n\n";
//    ht.remove(c);
//
//
//	return 0;
//}

/*
**Testing hash()**

The hash value for the book 'Contact' by 'Carl Sagan' in the Hash table is:
9

**Testing countBucket()**

The number of bucket for index of 9 is: 2

**Testing printBucket()**

The Hunger Games by Suzanne Collins
$13.55
ISBN#: 12388888


The Man in the High Castle by Philip K Dick
$15.95
ISBN#: 95959595



**Testing printTable()**

Group: 1
Bleak House by Charles Dickens
$8
ISBN#: 473890238

+0 more book(s)



Group: 3
Pride and Prejudice by Jane Austen
$4.95
ISBN#: 1234567

+0 more book(s)



Group: 5
Contact by Carl Sagan
$9.95
ISBN#: 99993339

+0 more book(s)



Group: 10
The Hunger Games by Suzanne Collins
$13.55
ISBN#: 12388888

+1 more book(s)




**Testing search()**

The index for book 'Contact' in the Hash table is:
4
The index for book 'Pride and prejudice' in the Hash table is:
2

**Testing remove()**
*/
