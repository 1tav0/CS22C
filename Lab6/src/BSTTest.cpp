/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 6
 */

#include <iostream>
#include <ostream>
#include <iomanip>
#include "BST.h"
using namespace std;

int main()
{
	//Testing insert() and inOrderPrint()
	cout << "\n** Testing insert() and inOrderPrint() **\n\n";
	BST <int> O;
	BST <int> G;
	O.insert(40);
	O.insert(10);
	cout << "Should print out 10 40 : \n";
	O.inOrderPrint(cout);
	O.insert(32);
	O.insert(78);
	O.insert(25);
	cout << "Should print nothing.\n";
	G.postOrderPrint(cout);
	cout << "Check getRoot()" << O.getRoot() << endl;
	cout << "Should print out 10 25 32 40 78: \n";
	O.inOrderPrint(cout);

	//Testing preOrderPrint()
	cout << "\n** Testing preOrderPrint() **\n\n";
	cout << "Should print nothing.\n";
	G.preOrderPrint(cout);
	cout << "Check getRoot()" << O.getRoot() << endl;
	cout << "Should print out 40 10 32 25 78: \n";
	O.preOrderPrint(cout);

	//Testing postOrderPrint()
	cout << "\n** Testing postOrderPrint() **\n\n";
	cout << "Should print nothing.\n";
	G.postOrderPrint(cout);
	cout << "Should print out 25 32 10 78 40: \n";
	O.postOrderPrint(cout);

	//Testing minimum()
	cout << "\n** Testing minimum() **\n\n";
	cout << "Assertion violated, error massage.\n";
	//G.minimum();
	cout << "Should print out 10: \n";
	cout << O.minimum() << endl;

	//Testing maximum()
	cout << "\n** Testing maximum() **\n\n";
	cout << "Should print out 0: \n";
	cout << G.maximum() << endl;
	cout << "Should print out 78: \n";
	cout << O.maximum() << endl;

	//Testing isEmpty()
	cout << "\n** Testing isEmpty() **\n\n";
	cout << "Should print out 1: \n";
	cout << G.isEmpty() << endl;
	cout << "Should print out 0: \n";
	cout << O.isEmpty() << endl;

	//Testing getSize()
	cout << "\n** Testing getSize() **\n\n";
	cout << "Should print out 0: \n";
	cout << G.getSize() << endl;
	cout << "Should print out 5: \n";
	cout << O.getSize() << endl;

	//Testing getRoot()
	cout << "\n** Testing getRoot() **\n\n";
	cout << "Assertion violated, error massage.\n";
	//G.getRoot();
	cout << "Should print out 40: \n";
	cout << O.getRoot() << endl;

	//Testing getHeight()
	cout << "\n** Testing getHeight() **\n\n";
	cout << "Should print out 0: \n";
	cout << G.getHeight() << endl;
	cout << "Should print out 4: \n";
	cout << O.getHeight() << endl;

	//Testing search()
	cout << "\n** Testing search() **\n\n";
	cout << "Assertion violated, error massage.\n";
	//G.search(10);
	cout << "Should print out 1: \n";
	cout << O.search(25) << endl;
	cout << "Should print out 0: \n";
	cout << O.search(26) << endl;

	//Testing remove()
	cout << "\n** Testing remove() **\n\n";
	cout << "Assertion violated, error massage.\n";
	//G.remove(10);
	O.remove(10);
	cout << "Should print out 25 32 40 78: \n";
	O.inOrderPrint(cout);
	cout << "Should print out 40 32 25 78: \n";
	O.preOrderPrint(cout);

	//Testing copy constructor
	cout << "\n** Testing copy constructor **\n\n";
	cout << "Should print out nothing. \n\n";
	BST<int> G2(G);
	cout << "Should print out 25 32 40 78: \n";
	BST<int> G1(O);
	G1.inOrderPrint(cout);

	return 0;
}

/*
** Testing insert() and inOrderPrint() **

Should print out 10 40 :
10 40
Should print nothing.

Check getRoot()40
Should print out 10 25 32 40 78:
10 25 32 40 78

** Testing preOrderPrint() **

Should print nothing.

Check getRoot()40
Should print out 40 10 32 25 78:
40 10 32 25 78

** Testing postOrderPrint() **

Should print nothing.

Should print out 25 32 10 78 40:
25 32 10 78 40

** Testing minimum() **

Assertion violated, error massage.
Should print out 10:
10

** Testing maximum() **

Should print out 0:
0
Should print out 78:
78

** Testing isEmpty() **

Should print out 1:
1
Should print out 0:
0

** Testing getSize() **

Should print out 0:
0
Should print out 5:
5

** Testing getRoot() **

Assertion violated, error massage.
Should print out 40:
40

** Testing getHeight() **

Should print out 0:
0
Should print out 4:
4

** Testing search() **

Assertion violated, error massage.
Should print out 1:
0
Should print out 0:
0

** Testing remove() **

Assertion violated, error massage.
Should print out 25 32 40 78:
25 32 40 78
Should print out 40 32 25 78:
40 32 25 78

** Testing copy constructor **

Should print out nothing.

Should print out 25 32 40 78:
25 32 40 78
*/
