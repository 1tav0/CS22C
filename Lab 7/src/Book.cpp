/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 7
 */

#include "Book.h"
#include <iostream>
#include <iomanip>
using namespace std;

Book::Book():title(""), author(""), price(0.0), isbn(0){};

Book::Book(string t, string a, double p, unsigned i) {
    title = t;
    author = a;
    price = p;
    isbn = i;
}

/**Access Functions*/

string Book::get_title() {
    return title;
}

string Book::get_author() {
    return author;
}

unsigned Book::get_isbn() {
    return isbn;
}

double Book::get_price() {
    return price;
}

/**Manipulation Procedures*/

void Book::set_title(string t){
    title = t;
}

void Book::set_author(string a) {
    author = a;
}

void Book::set_isbn(unsigned i) {
    isbn = i;
}

void Book::set_price(double p) {
    price = p;
}

/**Additional Functions*/


bool Book::operator==(const Book& book)
{
    return (title == book.title && author==book.author);
}

//To-do: Add <, > and << here

ostream& operator<<(ostream& os, const Book& book)
{
	os << book.title << " by " << book.author << endl;
	os << "$" << book.price << endl;
	os << "ISBN#: " << book.isbn << endl;
	return os;
}

bool Book::operator<(const Book& book)
{
	if(title == book.title)
	{
		return (author < book.author);
	}
	else
	{
	return (title < book.title);
	}
}

bool Book::operator>(const Book& book)
{
	if(title == book.title)
	{
		return (author>book.author);
	}
	else
	{
		return (title > book.title);
	}
}
