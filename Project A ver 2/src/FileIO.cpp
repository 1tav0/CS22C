/*
 * FileIO.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: Work
 */

#include "FileIO.h"
#include <fstream>
#include <iostream>

FileIO::FileIO(){
	userTable.resize(16);
	userFriends.resize(16);

	for(int i = 0; i < 16; i++){
		userTable[i] = User();
		userFriends[i] = List<string>();
	}
}

//void FileIO::loadData(string filename,BST<User> &bst,HashUser &hu,HashInterest &hi,HashLogin &hl,Graph &g)
void FileIO::loadData(string filename,BST<User> &bst,HashUser &hu,HashLogin &hl, HashInterest &hi,Graph &g){

	string buffer, buffer1, firstname, lastname, username, password, company, city, userID, friends, interests;
	int pos,id;
	ifstream fin;
	User temp;
	User blank;

	fin.open(filename.c_str());

	while (getline(fin,buffer))
	{
		if (buffer.size() == 2) continue;

		if (buffer.find("First") != string::npos)
		{
			pos = buffer.find(':');
			firstname = buffer.substr(pos+2, buffer.length());
			//cout << "Firstname : " << firstname << endl;
			continue;
		}
		else if (buffer.find("Last") != string::npos)
		{
			pos = buffer.find(':');
			lastname = buffer.substr(pos+2, buffer.length());
			//cout << "Lastname : " << lastname << endl;
			continue;
		}
		else if (buffer.find("Login") != string::npos)
		{
			pos = buffer.find(':');
			username = buffer.substr(pos+2, buffer.length());
			//cout << "Login : " << username << endl;
			continue;
		}
		else if (buffer.find("Password") != string::npos)
		{
			pos = buffer.find(':');
			password = buffer.substr(pos+2, buffer.length());
			//cout << "Password : " << password << endl;
			continue;
		}
		else if (buffer.find("Company") != string::npos)
		{
			pos = buffer.find(':');
			company = buffer.substr(pos+2, buffer.length());
			//cout << "Company : " << company << endl;
			continue;
		}
		else if (buffer.find("City") != string::npos)
		{
			pos = buffer.find(':');
			city = buffer.substr(pos+2, buffer.length());
			//cout << "City : " << city << endl;
			continue;
		}
		else if (buffer.find("User") != string::npos)
		{
			pos = buffer.find(':');
			userID = buffer.substr(pos+2, buffer.length());
			//cout << "User ID : " << userID << endl;
			id = atoi(userID.c_str());
			continue;
		}
		else if (buffer.find("Friends") != string::npos)
		{
			pos = buffer.find(':');
			buffer1 = buffer.substr(pos+1, buffer.length());
			istringstream in(buffer1);
			//cout << "Friends : " ;
			while(getline(in, buffer1, ',')){
				buffer1.erase(0, 1);
				//cout << buffer1 << ", ";
				if(buffer1 != "")
					userFriends[id].insertLast(buffer1);
			}
			//cout << endl;
			continue;
		}
		else if (buffer.find("Interests") != string::npos)
		{
			pos = buffer.find(':');
			buffer1 = buffer.substr(pos+1, buffer.length());
			istringstream in(buffer1);
			//cout << "Interests : " ;
			while(getline(in, buffer1, ',')){
				buffer1.erase(0, 1);
				//cout << buffer1 << ", ";
				temp.addInterest(buffer1);
			}
			//cout << endl;


			temp.setFirstName(firstname);
			temp.setLastName(lastname);
			temp.setUserName(username);
			temp.setPassword(password);
			temp.setCompany(company);
			temp.setCity(city);
			temp.setUserID(id);


			userTable[id] = temp;			// User stored into vector dependent on their ID
			temp = blank;					// User temp is overwritten with a blank User to repeat process

			continue;
		}

	}

	fin.close();							// FileIO Reading input process is now over
	fin.clear();

	HashUser userBuffer;					// A HashUser table is created to hold the newly made Users
	for(int i = 1; i < 16; i++)
		userBuffer.insert(userTable[i]);

	// Vector<User>			 - Currently contains Users with generic info, but BST<User> is currently empty
	// Vector<List<string>>	 - Parallel with our Vector<User>, this list contains strings of the User's friends names
	// HashUser				 - Also currently contains Users with generic info, but BST<User> is currently empty
	// Process:	Use a User's string List of friend names as keys, to add them as a friend with HashUser


	string friendName;
	User tempUser;
	for(int j = 1; j < 16; j++){
		for(int k = 0; k < userFriends[j].getLength(); k++){
			if(!userFriends[j].isEmpty()){
				userFriends[j].advanceToIndex(k+1);
				friendName = userFriends[j].getIterator();
				friendName.erase(remove(friendName.begin(), friendName.end(), ' '), friendName.end());
				//cout << friendName << " ";
				tempUser = userBuffer.getUser(friendName);
				userTable[j].addFriend(tempUser);
				g.addEdge(userTable[j],tempUser);
				tempUser = blank;
				//cout << endl;
				//cout << userTable[j] << endl;
			}
		}
		//cout << endl;
	}

	// Vector<User> userTable now has all the correct information from the text file
	// Data Structures can now be updated by inserting Users from the userTable

	for(int i = 1; i < 16; i++){
		//cout << userTable[i] << endl;
		bst.insert(userTable[i]);		// BST<User>
		hu.insert(userTable[i]);		// HashUser
		hl.insert(userTable[i]);		// HashLogin
		hi.insertInterest(userTable[i]);// HashInterests
		g.insert(userTable[i]);		// Graph
	}

}

void FileIO::saveData(string filename,BST<User> bst) const{
	ofstream fout;
	fout.open(filename.c_str());
	bst.inOrderPrint(fout);
	fout.close();
}
