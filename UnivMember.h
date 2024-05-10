#ifndef UNIVMEMBER_H
#define UNIVMEMBER_H
#include <iostream>
#include <string>
#include "ID.h"
#include "Name.h"
using namespace std;
class UnivMember{
	public:
		UnivMember();
		UnivMember(string inputName); 
		void setUnivID(ID userID);
		ID getUnivID();
		void setUnivName(string userName);
		Name getUnivName();
		void setRole(string userRole);
		string getUserRole();
		void printUnivMember();

	protected:
		ID univID;
		Name univName;
		string role;
};


#endif
