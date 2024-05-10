#include "ID.h"
#include <iostream>
using namespace std;


static int currNumber = 10000000; //makes sure to have a permanent starting location
ID::ID(){
	ID_number = currNumber;
	full_ID = "A" + to_string(ID_number);
	currNumber++;
}

int ID::getIDNum(){
	return ID_number;
}

string ID::getFullID(){
	return full_ID;
}

void ID::setIDNum(int idNum){
	ID_number = idNum;
}

void ID::setFullID(string userID){
	full_ID = userID;
}

void ID::printID(){
	cout << "ID: " << full_ID << endl << endl;
}

ostream& operator<<(ostream& os, const ID& myID){ //specifies the ID member to be read in when insertion operator is used
	os << myID.full_ID;
	return os;
}
