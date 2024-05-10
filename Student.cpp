#include "Student.h"

Student::Student(){
	gradYear = 0;
	campus = "Default";
	major = "Undecided";
	emailAddress = "email@fordham.edu";
}

void Student::setGradYear(int userYear){
	gradYear = userYear;
}

void Student::setCampus(string userCampus){
	campus = userCampus;
}

void Student::setMajor(string userMajor){
	major = userMajor;
}

void Student::setEmail(string userEmail){
	emailAddress = userEmail;
}

int Student::getGradYear(){
	return gradYear;
}

string Student::getCampus(){
	return campus;
}

string Student::getMajor(){
	return major;
}

string Student::getEmail(){
	return emailAddress;
}

string createEmail(Student& studObj){
	string placeHolder;
	placeHolder = studObj.univID.getFullID();
	char lastNum = placeHolder.at(placeHolder.size() - 1); //gets last number of student ID
	placeHolder = studObj.univName.getFirstName();
	char firstLetter = placeHolder.at(0); //gets first letter of first name
	placeHolder = studObj.univName.getLastName();
	string fullEmail = firstLetter + placeHolder + lastNum + "@fordham.edu"; //email is composed of first letter of first name, last name & last # in id
	return fullEmail;
}

void Student::changeLastNum(){ //called when two students share an email
	int numIdx = emailAddress.find("@") - 1; 
	char temp = emailAddress.at(numIdx);
	int holder = temp - '0'; //finds and converts the number (in string) in email to an int so that it can be increased (creates a unique email)
	holder++;
	emailAddress.at(numIdx) = '0' + holder; //converts last number back to a charcater to be inserted to email string
}

istream& operator>>(istream& is, Student& studObj){
	is >> studObj.univName;
 	is >> studObj.gradYear;
 	is >> studObj.major;
 	is >> studObj.campus;
 	return is;
}

ostream& operator<<(ostream& os, const Student& studObj){
	os << studObj.univName << ", " << studObj.univID << ", " << studObj.emailAddress << endl; //both Name and ID have personal insertion operator
	return os;
}
