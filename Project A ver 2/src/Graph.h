/*
 * Graph.h
 *
 * Elmer Tabios
 * CIS 22C, Lab 8
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "List.h"
#include "User.h"
using namespace std;

class Graph {
public:

struct friendRec{
	User newfriend;
	List<User> mutualFriends;
	List<string> mutualInterests;
	int numFriend = 0;
	int numInterest = 0;
	int rankScore = 0;
};

/**Constructors and Destructors*/

Graph(int n);
//initializes an empty graph to have n vertices

/*** Access Functions ***/

int getNumEdges() const;
//returns the number of edges in the graph

int getNumVertices() const;
//returns the number of vertices in the graph

bool isEmpty() const;
//returns whether the graph is empty (no vertices)

int getDistance(int v) const;
//Pre: v <= vertices
//Returns the value of the distance[v]

int getParent(int v) const;
//Pre: v <= vertices
//Returns the value of the parent[v]

char getColor(int v) const;
//Pre: v <= vertices
//Returns the value of color[v]

/*** Manipulation Procedures ***/

void addEdge(User userU, User userV);
//inserts vertex v into the adjacency list of vertex u (i.e. inserts v into the list at index u)
//and inserts u into v.

void removeEdge(User userU, User userV);
//removes vertex v from the adjacency list of vertex u
//removes vertex u from the adjacency list of vertex v

void insert(User u);
// Inserts a User object into the userTable
// Updates an existing User object information in the userTable

List<User> getFriendRecommendations(User source);
// Returns a List of recommended Users to add

/*** Additional Operations ***/

void printGraph(ostream& out);
//Prints the adjacency list of each vertex in the graph,
//vertex: <space separated list of adjacent vertices>
//Prints to the console or to an output file given the ostream parameter

void printBFS(ostream& out);
//Prints the current values in the parallel vectors after executing BFS
//Prints to the console or to an output file given the ostream parameter
//First prints the heading:
//v <tab> c <tab> p <tab> d <tab>
//Then, prints out this information for each vertex in the graph
//Note that this function is intended purely to help you debug your code

void BFS(int source);
//Performs breath first search on this Graph give a source vertex
//pre: at least one vertex must exist
//pre: source is a vertex in the graph

void printPath(int source, int destination, ostream& out);
//Prints the path from the source to the destination vertex
//Prints to the console or to an output file given the ostream parameter

private:
    int vertices, edges; //number of edges and vertices
    vector<List<int> > adj;
    vector<char> color;
    vector<int> distance;
    vector<int> parent;
    vector<User> userTable;	// User Data in vector corresponding by their User ID

};



#endif /* GRAPH_H_ */
