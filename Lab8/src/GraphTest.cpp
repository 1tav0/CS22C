/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 8
 */

#include <iostream>
#include "Graph.h"
#include "assert.h"
using namespace std;

//int main()
//{
//	Graph G(5);
//	G.addEdge(1,2);
//	G.addEdge(1,5);
//	G.addEdge(2,3);
//	G.addEdge(2,4);
//	G.addEdge(3,4);
//	G.addEdge(4,5);
//	G.addEdge(5,5);
//	cout << endl;
//	G.printGraph(cout);
//	G.BFS(1);
//	G.printBFS(cout);
//
//	cout<< "\nThe distance of 1 is " << G.getDistance(1) << endl;
//	cout<< "The distance of 2 is " << G.getDistance(2) << endl;
//	cout<< "The distance of 3 is " << G.getDistance(3) << endl;
//	cout<< "The distance of 4 is " << G.getDistance(4) << endl;
//	cout<< "The distance of 5 is " << G.getDistance(5) << endl;
//
//
//	cout << "\nThe path from vertex 1 to 4 : ";
//	G.printPath(1, 4, cout);
//	cout << "\nThe path from vertex 1 to 6 : ";
//	G.printPath(1, 6, cout);
//
//	cout << endl << "Testing getColor() of vertex 0 : " << G.getColor(0) << endl;
//	cout << "Testing getNumEdges() of Graph : " << G.getNumEdges() << endl;
//	cout << "Testing getNumVertices() of Graph: " << G.getNumVertices() << endl;
//	cout << "Testing getParents() of vertex 3 : " << G.getParent(3) << endl;
//
//	return 0;
//}

/*
1: 2 5
2: 1 3 4
3: 2 4
4: 2 3 5
5: 1 4 5

v	c  	p  	d
1 	B 	0 	0
2 	B 	1 	1
3 	B 	2 	2
4 	B 	2 	2
5 	B 	1 	1

The distance of 1 is 0
The distance of 2 is 1
The distance of 3 is 2
The distance of 4 is 2
The distance of 5 is 1

The path from vertex 1 to 4 : 1 2 4
The path from vertex 1 to 6 : No path from 1 to 6 exits

Testing getColor() of vertex 0 : W
Testing getNumEdges() of Graph : 7
Testing getNumVertices() of Graph: 5
Testing getParents() of vertex 3 : 2

*/
