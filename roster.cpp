#include <iostream>
#include <ostream>
#include <string>
#include <list>
#include <array>
#include "pch.h"
#include "Student.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include "Degree.h"
#include "roster.h"
using std::cerr;
using std::string;
using std::cout;
using std::endl;
using namespace std;

const int numStudents = 8;

void Roster::add(string row){
	if (lastStudentIndex < capacity) {
		lastStudentIndex++;
		int numDaysArray[Student::courseArraySize];

	if (row.substr(row.length() - 8, 8) == "SOFTWARE") {
		this->classRosterArray[lastStudentIndex] = new SoftwareStudent();
		classRosterArray[lastStudentIndex]->setDegreeProgram(SOFTWARE);
		}
	else if (row.substr(row.length() - 7, 7) == "NETWORK") {
		this->classRosterArray[lastStudentIndex] = new NetworkStudent();
		classRosterArray[lastStudentIndex]->setDegreeProgram(NETWORK);
		}
	else if (row.substr(row.length() - 8, 8) == "SECURITY") {
		this->classRosterArray[lastStudentIndex] = new SecurityStudent();
		classRosterArray[lastStudentIndex]->setDegreeProgram(SECURITY);
		}
		
/*
Will parse through each 'student string' delimiting on the comma
Then extract each substring & set each field, set ID
		

int rhs = numStudents[lastStudentIndex].find(",");
classRosterArray[lastStudentIndex]->setId(studentData[lastStudentIndex].substr(0, rhs));

//read first name
int lhs = rhs + 1;//FIXME
rhs = studentData[lastStudentIndex].find(",", lhs);
classRosterArray[lastStudentIndex]->setFName(studentData[lastStudentIndex].substr(lhs, rhs - lhs));

//read last name
lhs = rhs + 1;
rhs = studentData[lastStudentIndex].find(",", lhs);
classRosterArray[lastStudentIndex]->setLName(studentData[lastStudentIndex].substr(lhs, rhs - lhs));

//read email
lhs = rhs + 1;
rhs = studentData[lastStudentIndex].find(",", lhs);
classRosterArray[lastStudentIndex]->setEmail(studentData[lastStudentIndex].substr(lhs, rhs - lhs));

//read days in course per array entry
lhs = rhs + 1;
rhs = studentData[lastStudentIndex].find(",", lhs);
		numDaysArray[0] = stoi(studentData[lastStudentIndex].substr(lhs, rhs - lhs));
		
lhs = rhs + 1;
rhs = studentData[lastStudentIndex].find(",", lhs);
numDaysArray[1] = stoi(studentData[lastStudentIndex].substr(lhs, rhs - lhs));
		
lhs = rhs + 1;
rhs = studentData[lastStudentIndex].find(",", lhs);
numDaysArray[2] = stoi(studentData[lastStudentIndex].substr(lhs, rhs - lhs));

*/


//set days in courses
classRosterArray[lastStudentIndex]->setDays(numDaysArray);

	}

	else {
		cout << "Error! Max capacity!" << '\n';
			exit(-1);}
	}

void Roster::printAll()//call print method for each student
	{
		for (int i = 0; i <= this->lastStudentIndex; i++) (this->classRosterArray)[i]->print();
	}

void Roster::remove(string studentId){
	for (int i = 0; i <= lastStudentIndex; i++){
		if (classRosterArray[i] == nullptr) // finds student 
		{
			cout << "Not Found" << '\n';
		}
		else if (studentId == classRosterArray[i]->getId()) {
			classRosterArray[i] = nullptr;
			cout << "Removed" << '\n';
			}
		}
			return;
	}

void Roster::printAverageCourseDays(string studentId){
	bool found = false;
	for (int i = 0; i <= lastStudentIndex; i++){
		if (this->classRosterArray[i]->getId() == studentId) //finds student{
			found = true;
			int* c = classRosterArray[i]->getDays();
			cout << "Average number of days student: " << studentId << " is " << (c[0] + c[1] + c[2]) / 3;  }
	}
			if (!found) { cout << "NOT FOUND" << '\n'; }
	}

void Roster::printInvalidEmail() {
	cout << "Invalid emails: " << '\n';
		for (int i = 0; i < lastStudentIndex; i++ ) {
			string email = classRosterArray[i]->getEmail();
			if ((email.find('@') == string::npos) || (email.find(' ') != string::npos) || (email.find('.') == string::npos)) {
		cout << "Invalid email" << '\n';}
					}
				}

void Roster::printByDegreeProgram(Degree degreeProgram) {
	cout << "Degree by program: " << degreeProgramStrings[degreeProgram] << '\n';
		for (int i = 0; i <= lastStudentIndex; i++) {
			if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) this->classRosterArray[i]->print();
				}
			}

Roster::~Roster()//destroys all students
	{
	for (int i = 0; i < numStudents; i++){
	delete this->classRosterArray[i];
		}
		delete this;
		}
