/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 8
 */

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	string input, output;
	int vertex = 0;
	int u, v;

	cout << "Welcome to WriteGraph! \n\nEnter the name of the file containing the graph information: ";

	getline(cin, input);
	fin.open(input.c_str());

	while (!fin)
	{
		cout << "Invalid file name! \n\n Please enter the name of the file: ";
		cin.clear();
		getline(cin, input);
		fin.open(input.c_str());
	}

	cout << "\n***Reading from " << input << "***\n";
	fin >> vertex;
	Graph G(vertex);
	while (!fin.eof())
	{
		if(u == 0 && v == 0)
			break;
		fin >> u >> v;
		G.addEdge(u, v);
	}

	cout << "\nPlease enter the name of the output file: ";
	getline(cin, output);
	fout.open(output.c_str());
	G.printGraph(fout);
	//G.printGraph(cout); //for testing

	while(fin >> u >> v)
	{
		if(u == 0 && v == 0)
			break;
		G.BFS(u);
		fout << "The distance from " << u << " to " << v << " : " << G.getDistance(v) << endl;
		fout << "A shortest path from " << u << " to " << v << " : ";
		G.printPath(u, v, fout);
		fout << endl;
	}
	//G.printBFS(fout); //for testing
	cout << "\nThank you! Your Graph is now written to " << output << "!" << endl;

	fin.close();
	fout.close();

	return 0;
}



