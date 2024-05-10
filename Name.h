#ifndef NAME_H
#define NAME_H
#include <iostream>
using namespace std;
#include <string>


class Name{
	public:
		Name();
		Name(string userName);
		string getFirstName();
		string getLastName();
		friend string removeSpace(string s);
		void printName();
		friend istream& operator>>(istream& is, Name& myName);
		friend ostream& operator<<(ostream& os, const Name& myName);

	private:
		string fname;
		string lname;

};


#endif
