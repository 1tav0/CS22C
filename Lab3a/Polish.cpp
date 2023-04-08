/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 3
 */

#include <iostream>
#include "Stack.h"
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

bool isNumeric(string s);

int main() {

	Stack <string> St;
	Stack <int> Si;

	stringstream mystream;
	string input, buffer, tempt;
	int tempi, a, b, c;

	cout << "\nWelcome!\n\n";
	cout << "Please enter an equation in Polish Notation or \"q\" to quit: \n";
	getline(cin, input);

	while ((input != "q") && (input != "Q"))
	{
		mystream.str(input);
		while (mystream >> buffer)
		{
			St.push(buffer);
		}
		while (St.getSize()!=0)
		{
			tempt = St.peek();
			if (isNumeric(tempt))
			{
				tempi = atoi(tempt.c_str());
				St.pop();
				Si.push(tempi);
			}
			else
			{
				if (tempt == "+")
				{
					a = Si.peek();
					Si.pop();
					b = Si.peek();
					Si.pop();
					c = a + b;
					Si.push(c);
				}
				else if (tempt == "-")
				{
					a = Si.peek();
					Si.pop();
					b = Si.peek();
					Si.pop();
					c = a - b;
					Si.push(c);
				}
				else if (tempt == "*")
				{
					a = Si.peek();
					Si.pop();
					b = Si.peek();
					Si.pop();
					c = a * b;
					Si.push(c);
				}
				else if (tempt == "/")
				{
					a = Si.peek();
					Si.pop();
					b = Si.peek();
					Si.pop();
					c = a / b;
					Si.push(c);
				}
				else
				{
					cout << "Wrong input\n";
				}
				St.pop();
			}

		}
		cout << "The answer is: ";
		Si.printStack();
		Si.pop();
		cout << "\nPlease enter an equation in Polish Notation or \"q\" to quit: \n";
		getline(cin, input);
		mystream.clear();

	}
	cout << "\nGoodbye!";

return 0;
}

bool isNumeric(string s)
{
	for (int i=0; i < s.length(); i++)
	{
		if(s[i]>= 48 && s[i]<= 57)
			return true;
	}
	return false;
}

/*

Welcome!

Please enter an equation in Polish Notation or "q" to quit:
* 3 + 4 5
The answer is: 27

Please enter an equation in Polish Notation or "q" to quit:
- * - 9 2 3 4
The answer is: 17

Please enter an equation in Polish Notation or "q" to quit:
/ * + 5 3 4 7
The answer is: 4

Please enter an equation in Polish Notation or "q" to quit:
+ 13 14
The answer is: 27

Please enter an equation in Polish Notation or "q" to quit:
Q

Goodbye!

*/

