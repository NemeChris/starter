#include <iostream>
#include <string>
using namespace std;
#include "Name.h"


string removeSpace(string s){
	string result;
	int lastLetterIdx = s.size() - 1;
	while(s.at(lastLetterIdx) == ' '){ //goes backwards, stopping only hwen there is no space
		lastLetterIdx--;
	}

	return s.substr(0, lastLetterIdx + 1);
}

Name::Name(){
	fname = "First";
	lname = "Last";
}


Name::Name(string userName){
	lname = userName.substr(0, userName.find(",")); 
	fname = userName.substr(userName.find(",")+1, userName.size()-1);
	fname = removeSpace(fname);
}

string Name::getFirstName(){
	return fname;
}

string Name::getLastName(){
	return lname;
}

void Name::printName(){
	cout << fname << " "  << lname << endl;
}

istream& operator>>(istream& is, Name& myName){ //specifies what's to be put into the Name object & parses code
	string fullName;
	is >> fullName;
	myName.lname = fullName.substr(0, fullName.find(",")); //starts at beginning letter and ends before comma
	myName.fname = fullName.substr(fullName.find(",")+1, fullName.size()-1); //starts after comma and ends at last letter
	myName.fname = removeSpace(myName.fname);
	return is;
}

ostream& operator<<(ostream& os, const Name& myName){
	os << myName.fname << " " << myName.lname;
	return os;
}
