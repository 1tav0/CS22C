/*
 * Graph.cpp
 *
 * Elmer Tabios
 * CIS 22C, Lab 8
 */

#include <iostream>
#include <iomanip>
#include <assert.h>
#include "Graph.h"


/**Constructors and Destructors*/

Graph::Graph(int n){
	vertices = n;
	edges = 0;

	// Defining Size of the parallel vectors
	// n+1 since index 0 is being left empty intentionally
	adj.resize(n+1);
	color.resize(n+1);
	distance.resize(n+1);
	parent.resize(n+1);
	userTable.resize(n+1);

	// For loop to initialize the parallel vectors
	for(int i = 0; i < n+1; i++){
		adj[i] = List<int>();		// Empty List
		color[i] = 'W';				// Colors 'W', later to 'G' and 'B'
		distance[i] = -1;			// Default Distance is -1
		parent[i] = 0;				// Initialized to 0
		userTable[i] = User();		// Default User Constructor
	}
}

/*** Access Functions ***/

int Graph::getNumEdges() const{
	return edges;
}

int Graph::getNumVertices() const{
	return vertices;
}

bool Graph::isEmpty() const{
	return (vertices == 0);
}

int Graph::getDistance(int v) const{
	assert(v <= vertices);	// Precondition: Integer parameter cannot be bigger than number of vertices
	return distance[v];
}

int Graph::getParent(int v) const{
	assert(v <= vertices);	// Precondition: Integer parameter cannot be bigger than number of vertices
	return parent[v];
}

char Graph::getColor(int v) const{
	assert(v <= vertices);	// Precondition: Integer parameter cannot be bigger than number of vertices
	return color[v];
}

/*** Manipulation Procedures ***/

void Graph::addEdge(User userU, User userV){
	// Preconditions weren't mentioned in header but in the future might want to consider
	// If an edge exists and if both vertex are valid
	int u = userU.getUserID();
	int v = userV.getUserID();

	if(!adj[u].isEmpty() && adj[u].linearSearch(v) != -1)
		return;
	if(!adj[v].isEmpty() && adj[v].linearSearch(u) != -1)
		return;

	// Adding v into u's adjacency list (Through a very questionable insertion sort)
	if(adj[u].isEmpty())			// Check if list is empty
		adj[u].insertFirst(v);
	else if(v <= adj[u].getFirst())	// Check if v is less than the first value in the list
		adj[u].insertFirst(v);
	else if(v >= adj[u].getLast())	// Check if v is greater than the last value in the list
		adj[u].insertLast(v);
	else{
		adj[u].startIterator();
		for(int i = 0; i < adj[u].getLength();i++){
			if(v == adj[u].getIterator()){
				adj[u].insertIterator(v);
				break;
			}
			else if(v < adj[u].getIterator()){
				adj[u].reverseIterator();
				adj[u].insertIterator(v);
				break;
			}
			adj[u].advanceIterator();
		}
	}

	// Adding u into v's adjacency list
	if(adj[v].isEmpty())			// Check if list is empty
		adj[v].insertFirst(u);
	else if(u <= adj[v].getFirst())	// Check if u is less than the first value in the list
		adj[v].insertFirst(u);
	else if(u >= adj[v].getLast())	// Check if u is greater than the last value in the list
		adj[v].insertLast(u);
	else{
		adj[v].startIterator();
		for(int i = 0; i < adj[v].getLength();i++){
			if(u == adj[v].getIterator()){
				adj[v].insertIterator(u);
				break;
			}
			else if(u < adj[v].getIterator()){
				adj[v].reverseIterator();
				adj[v].insertIterator(u);
				break;
			}
			adj[v].advanceIterator();
		}
	}

	edges++;
}

void Graph::removeEdge(User userU, User userV){
	int u = userU.getUserID();
	int v = userV.getUserID();

	assert(adj[u].linearSearch(v) != -1 && adj[v].linearSearch(u) != -1);	// Precondition: The adjacency or edge must exist for both Users

	adj[u].advanceToIndex(adj[u].linearSearch(v));
	adj[u].removeIterator();

	adj[v].advanceToIndex(adj[v].linearSearch(u));
	adj[v].removeIterator();

}

void Graph::insert(User u){
	userTable[u.getUserID()] = u;
}

List<User> Graph::getFriendRecommendations(User source){
	cout << "Starting getFriendRecommendations" << endl;
	List<friendRec> rankedList;							// List of the recommended friends statistics
	List<User> userFriends = source.getFriendsList();	// sourceUser's list of friends
	List<string> userInterests = source.getInterests();	// sourceUser's list of interests
	List<User> recommendedFriends;						// The list of recommended Users to be returned

	BFS(source.getUserID());							// Call BFS on sourceUser

	for(int i = 1; i <= vertices; i++){					// Loop through all vertices of Graph

		if(distance[i] == 2){							// Distance of 2 gets friends of friends within 1 edge
			User u = userTable[i];						// User info grabbed from userTable
			cout << u.getFirstName() << " " << u.getLastName() << endl;
			friendRec temp;								// friendRec object created to hold statistics
			temp.newfriend = u;

			cout << "Checking mutual friends" << endl;
			List<User> uFriends = u.getFriendsList();	// Check for mutual friends +1 to rankScore for each
			uFriends.startIterator();					// Compare friends list and count each mutual friend
			while(!uFriends.offEnd()){
				User commonF = uFriends.getIterator();
				if(userFriends.linearSearch(commonF) != -1){
					temp.mutualFriends.insertLast(commonF);
					temp.numFriend += 1;
					temp.rankScore += 1;
				}
				uFriends.advanceIterator();
			}
			cout << "Mutual Friends: " << temp.numFriend << " Rank Score: " << temp.rankScore << endl;

			cout << "Checking mutual interests" << endl;
			List<string> uInterests = u.getInterests();	// Check for mutual interests +1 to rankScore for each
			uInterests.startIterator();					// Compare interest list and count each mutual interest
			while(!uInterests.offEnd()){
				string commonI = uInterests.getIterator();
				if(userInterests.linearSearch(commonI) != -1){
					temp.mutualInterests.insertLast(commonI);
					temp.numInterest += 1;
					temp.rankScore += 1;
				}
				uInterests.advanceIterator();
			}
			cout << "Mutual Interests: " << temp.numInterest << " Rank Score: " << temp.rankScore << endl;

			cout << "Sorting into rankedList" << endl;
			if(rankedList.isEmpty())					// Sorts rankedList by rankScore (Highest to Lowest)
				rankedList.insertFirst(temp);
			else if(temp.rankScore >= rankedList.getFirst().rankScore){
				rankedList.insertFirst(temp);
			}
			else if(temp.rankScore <= rankedList.getLast().rankScore){
				rankedList.insertLast(temp);
			}else{
				rankedList.startIterator();
				for(int i = 0; i < rankedList.getLength();i++){
					if (temp.rankScore == rankedList.getIterator().rankScore){
						rankedList.insertIterator(temp);
						break;
					}else if(temp.rankScore > rankedList.getIterator().rankScore){
						rankedList.reverseIterator();
						rankedList.insertIterator(temp);
						break;
					}
					rankedList.advanceIterator();
				}
			}

		}
	}

	cout << "\n\nRecommended Friends: " << endl;
	rankedList.startIterator();
	int num = 1;
	while(!rankedList.offEnd()){
		friendRec temp = rankedList.getIterator();
		cout << num++ << ". " << temp.newfriend.getFirstName() << " " << temp.newfriend.getLastName()
		<< " | " << temp.numFriend << " mutual friend(s)" << " | " << temp.numInterest << " mutual interest(s)" << endl;
		//cout << num++ << ". "<< rankedList.getIterator().newfriend.getFirstName() << " " << rankedList.getIterator().newfriend.getLastName() << endl;
		rankedList.advanceIterator();
	}
	if(num == 1)
		cout << "No Results" << endl;


	return recommendedFriends;
}

/*** Additional Operations ***/

void Graph::printGraph(ostream& out){
	for(int i = 1; i < vertices+1; i++){
		out << i << ": ";
		adj[i].printList(out);
	}
	out << endl;
}

void Graph::BFS(int source){
	assert(vertices > 0);		// Precondition: At least one vertex must exist
	assert(source <= vertices);	// Precondition: Source is a vertex in the graph

	for(int i = 0; i < vertices+1; i++){	// Normalize/Default all vertex characteristics
		color[i] = 'W';
		distance[i] = -1;
		parent[i] = 0;
	}

	List<int> queue;				// Implementing a 'Queue' with a List

	color[source] = 'G';			// Color of Source Vertex is 'Grey'

	distance[source] = 0;			// Distance from source is 0

	queue.insertLast(source);		// Enqueue source vertex into our 'Queue'

	while(!queue.isEmpty()){		// While Queue is not empty

		int x = queue.getFirst();	// X equals front of Queue
		queue.removeFirst();		// Remove front(x) from queue

		for(int i = 0; i < adj[x].getLength();i++){	// Iterating through vertex X's adjacency list
			adj[x].advanceToIndex(i+1);
			int y = adj[x].getIterator();

			if(color[y] == 'W'){				// Have we seen this node? 'W' White = No
				color[y] = 'G';					// Assign 'G' Grey = First time reaching this node
				distance[y] = distance[x] +1;	// Distance of Y equal distance of X's distance + 1
				parent[y] = x;					// Make vertex X the parent of vertex Y
				queue.insertLast(y);			// Add vertex Y to our 'Queue'
			}
		}
		color[x] = 'B';	// Color 'B' Black = Indicates we are finished we this vertex
	}
}

void Graph::printBFS(ostream& out){
	// 'V' = Vector | 'C' = Color | 'P' = Parent | 'D' = Distance
	out << "v" << setw(4) << "c" << setw(4) << "p" << setw(4) << "d" << endl;
	for(int i = 1; i < vertices+1; i++)
		out << i << setw(4) << color[i] << setw(4) << parent[i] << setw(4) << distance[i] << endl;
}

void Graph::printPath(int source, int destination, ostream& out){
	if(destination == source)
		out << source << " ";
	else if(parent[destination] == 0)
			out << "No path from " << source << " to " << destination << " exists.";
	else{
		printPath(source,parent[destination],out);
		out << destination << " ";
	}
}


