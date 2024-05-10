#include "Name.h"
#include "ID.h"
#include "UnivMember.h"
#include "Student.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/* reads in name, graduation year, major and campus
 * parses and organises Student member function
 * checks for repeat in emails
 * sends it into a file, with student name, id, and email
 */

int main(){
	string userDescription;
	string fullName;
	ifstream studNameFiles("StudentInfo.txt");
	vector <Student*> studentList;

	if(!studNameFiles.is_open()){
		cout << "Failed to open" << endl;
	}

	while(!studNameFiles.eof()){
		Student* myStudent = new Student();
		studNameFiles >> *myStudent; //reads whole line of information
		myStudent->setEmail(createEmail(*myStudent));
		studentList.push_back(myStudent);
	}
	studNameFiles.close();	
	

	for(int i = 0; i < studentList.size() - 2; i++){
		for(int j = i + 1; j < studentList.size() - 1; j++){
			if(studentList.at(i)->getEmail() == studentList.at(j)->getEmail()){ //Makes sure each username is unique
				studentList.at(j)->changeLastNum();
			}
		}
	}

	ofstream exportFile("StudentOrg.txt");
	for(int i = 0; i < studentList.size(); i++){
		exportFile << *(studentList.at(i)); //inserts each member in vector of Student pointers to file
	}
	exportFile.close();
		
	return 0;

}
