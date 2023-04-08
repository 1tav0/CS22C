///**
//
//* Octavio Cruz
//
//* CIS 22C, Lab 2
//
//*/
//
//#include <iostream>
//#include <fstream>
//#include "List.h"
//#include <string>
//#include <locale>
//
//using namespace std;
//
//List<string> L;
//
//int main()
//{
//	string directionLineLower = "";
//	string directionLine;
//	int sourceLine, destinationLine;
//	string Line;
//	string textFile;
//	bool flag = true;
//	string title;
//	string temp;
//
//
//	cout << "Welcome to the poetry re-arranger!" << endl;
//	cout << endl;
//	cout << "Enter the name of a file containing a poem: " << endl;
//	cin >>  textFile ;
//	int linenumber=0;
//	ifstream myFile(textFile);
//	while (myFile.fail())
//	{
//
//		cout << "wrong textfile!" << endl;
//		cout << "Please re enter textfile." << endl;
//		cin >> textFile;
//		myFile.open(textFile);
//
//	}
//
//	getline(myFile,title);
//	getline(myFile, temp);
//
//	while(!myFile.eof())
//	{
//		getline(myFile,Line);
//
//		L.getLength();
//
//		//cout << Line << endl;
//		L.insertLast(Line);
//
//}
//	cout << endl;
//
//	string author=L.getLast();
//	L.removeLast();  // removing last two lines on txt file
//	L.removeLast();
//
//	cout << "There are " << L.getLength() << " lines in your poem " << endl;
//	cout <<"The poem is: " << endl;
//	cout << title<<" ";
//	cout<<author<<endl;
//	cout << endl;
//	L.printNumberedList();
//
//	L.startIterator();   // deleted this iterator must start again
//	for (int i = 1; i<sourceLine; i++, L.advanceIterator()) {
//
//		string storeData = L.getIterator();
//		L.removeIterator();
//
//		if (destinationLine>sourceLine){
//			destinationLine --;
//		}
//
//		L.startIterator();
//			for (int i = 1; i<destinationLine; i++, L.advanceIterator());
//
//		L.insertIterator(storeData);
//		}
//
//	while (flag) {
//	cout << "How would you like to re-arrange this poem? " << endl;
//	cout << endl;
//	cout<< "Please enter the line number of the poem: ";
//	cin >> sourceLine;
//
//	L.startIterator();
//	for(int i=0; i<sourceLine-1; i++)
//	{
//		L.advanceIterator();
//	}
//
//	string poemLine=L.getIterator();
//	if (poemLine==""){
//		cout << "The line is blank " << endl;
//	} else {
//		cout <<"The line is: " << poemLine << endl;
//	}
//		//for (int i = 1; i<sourceLine; i++, L.advanceIterator());
//
//		//cout << L.getIterator() << endl;
//	cout << endl;
//	cout << "Do you want to move this line up or down:";
//	cin >> directionLine;
//	cout << "How many lines do you want to move it: ";
//	cin>> destinationLine;
//if (directionLine=="up"){
//
//
//		for (int i=0;i<destinationLine + 1; i++)
//			L.reverseIterator();
//		L.insertIterator(poemLine);
//		for (int i=0; i< destinationLine + 2; i++){
//			L.advanceIterator();
//		}
//		L.removeIterator();
//
//} else if (directionLine=="down"){
//	for (int i=0;i<destinationLine; i++)
//				L.advanceIterator();
//			L.insertIterator(poemLine);
//			for (int i=0; i< destinationLine; i++){
//				L.reverseIterator();
//			}
//			L.removeIterator();
//	}
//
//
//
//	/**
//	locale loc; //starting object called locale
//	  for (string::size_type i=0; i<directionLine.length(); ++i)
//	    directionLineLower+=tolower(directionLine[i],loc);
//
//	if (directionLineLower=="up")
//	{
//		L.move(sourceLine,sourceLine-destinationLine);
//	}
//	else if (directionLineLower=="down")
//	{
//
//			L.move(sourceLine,sourceLine+destinationLine);
//		}
//		*/
//	//cout << directionLineLower;*/
//
//
//
//	cout << "The new poem is: " << endl;
//	cout << endl;
//	L.printNumberedList();
//
//	cout << "Would you like to rearrange this poem further: " ;
//	cin >> directionLineLower;
//	//for (string::size_type i=0; i<directionLine.length(); i++)
//		//    directionLineLower[i]+=tolower(directionLine[i]);
//	if (directionLineLower.compare("no") == 0){
//		flag=false;
//		cout << "Goodbye!" << endl;
//	}
//
//
//
//	}
//
//
//}
//
//
//
//
//
//
//
