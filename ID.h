#ifndef ID_H
#define ID_H
#include <iostream>
using namespace std;
#include <string>


class ID{
	public:
		ID();
		int getIDNum(); //getter
		void setIDNum(int idNum); //setter
		string getFullID();
		void setFullID(std::string userID);
		void printID();
		friend ostream& operator<<(ostream& os, const ID& myID);
	private:
		int ID_number;
		string full_ID;

};


#endif
