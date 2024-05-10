#ifndef STUDENT_H
#define STUDENT_H
#include "UnivMember.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student: public UnivMember{ //derived from UnivMember
	public:
		Student();
		void setGradYear(int userYear);
		void setCampus(string userCampus);
		void setMajor(string userMajor);
		void setEmail(string userEmail);
		int getGradYear();
		string getCampus();
		string getMajor();
		string getEmail();
		void changeLastNum();
		friend ostream& operator<<(ostream& os, const Student& studObj);
		friend istream& operator>>(istream& is, Student& studObj);
		friend istream& getline(istream& is, Student& studObj);
		friend string createEmail(Student& studObj);

	private:
		int gradYear;
		string campus;
		string major;
		string emailAddress;
};


#endif
