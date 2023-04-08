/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 7
 */

#include "Book.h"
#include "HashTable.h"
#include "BST.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	HashTable ht;
	BST<Book> bst;
	ifstream fin;
	string buffer_P, buffer_I, buffer_B ;
	int choice;
	string retitle, reauthor;
	double reprice = 0.00;
	int reisbn = 0;
	Book temp1(retitle, reauthor, reprice, reisbn);
	fin.open("catalogue.txt");
	while (!fin.eof())
	{
		getline(fin, retitle);
		getline(fin, reauthor);
		getline(fin, buffer_P);
		getline(fin, buffer_I);
		getline(fin, buffer_B);
		reprice = atof(buffer_P.c_str());
		reisbn = atoi(buffer_I.c_str());
		temp1.set_title(retitle);
		temp1.set_author(reauthor);
		temp1.set_price(reprice);
		temp1.set_isbn(reisbn);
		ht.insert(temp1);
		bst.insert(temp1);
	}
	cout << "\nWelcome to the Best Reads App!\n\n";
	do
	{
		cout << "What would you like to do?\n";
		cout << "1. Browse catalogue by title\n";
		cout << "2. Insert a new book\n";
		cout << "3. Remove a book\n";
		cout << "4. Search for a book\n";
		cout << "5. Quit\n\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << endl;

		while (cin.fail())
		{
			cout << "\nPlease enter numbers not letters\n\n";
			cout << "What would you like to do?\n";
			cout << "1. Browse catalogue by title\n";
			cout << "2. Insert a new book\n";
			cout << "3. Remove a book\n";
			cout << "4. Search for a book\n";
			cout << "5. Quit\n\n\n";
			cout << "Enter your choice: ";
			cin >> choice;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
		}
		if (choice == 1)
		{
			cout << "Here is an alphabetical list of the books in our catalogue:\n\n";
			bst.inOrderPrint(cout);
		}
		else  if (choice == 2)
		{
			cout << "\nEnter the title: ";
			getline(cin,retitle);
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nEnter the author: ";
			getline(cin,reauthor);
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nEnter the price: ";
			getline(fin, buffer_P);
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nEnter the isbn: ";
			getline(fin, buffer_I);
			cin.clear();
			cin.ignore(1000, '\n');
			reprice = atof(buffer_P.c_str());
			reisbn = atoi(buffer_I.c_str());
			temp1.set_title(retitle);
			temp1.set_author(reauthor);
			temp1.set_price(reprice);
			temp1.set_isbn(reisbn);
			bst.insert(temp1);
			ht.insert(temp1);
			cout << retitle << " has been added to the catalogue\n\n";
		}
		else  if (choice == 3)
		{
			cout << "Enter the title of the book to remove: ";
			getline(cin, retitle);
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Enter the author: ";
			getline(cin, reauthor);
			cin.clear();
			cin.ignore(1000, '\n');
			temp1.set_title(retitle);
			temp1.set_author(reauthor);
			temp1.set_price(reprice);
			temp1.set_isbn(reisbn);
			ht.remove(temp1);
			bst.remove(temp1);
			cout << retitle << " has been removed from the catalogue.\n\n";
		}
		else  if (choice == 4)
		{
			cout << "Enter the title of the book to search: ";
			getline(cin, retitle);
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Enter the author: ";
			getline(cin, reauthor);
			cin.clear();
			cin.ignore(1000, '\n');
			temp1.set_title(retitle);
			temp1.set_author(reauthor);
			temp1.set_price(reprice);
			temp1.set_isbn(reisbn);
			if (ht.search(temp1) == -1)
			{
				cout << retitle << " is not in the catalogue\n";
			}
			else
			{
				cout << retitle << " is in the catalogue\n";
			}
		}
		else if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
		{
			cout <<"\nInvalid input\n\n";
		}

	} while (choice !=5);
	cout << "Happy reading!\n";
	ofstream fout;
	fout.open("catalogue2.txt");
	bst.inOrderPrint(fout);


	fin.close();
	fout.close();
	return 0;
}



