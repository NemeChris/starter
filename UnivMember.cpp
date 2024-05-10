#include "UnivMember.h"

UnivMember::UnivMember(){
	univName = Name();
}

UnivMember::UnivMember(string inputName){
	univName = Name(inputName); //calls the non-default name constructor to parse fname & lname
}

void UnivMember::setUnivID(ID userID){
	univID = userID;
}

ID UnivMember::getUnivID(){
	return univID;
}

void UnivMember::setUnivName(string userName){
	univName = userName;
}

Name UnivMember::getUnivName(){
	return univName;
}

void UnivMember::setRole(string userRole){
	role = userRole;
}

void UnivMember::printUnivMember(){
	cout << role << ": ";
	univName.printName();
	univID.printID();
}
