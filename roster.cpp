#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <list>
#include <array>
#include "Student.h"
#include "Degree.h"
#include "roster.h"
using std::cerr;
using std::string;
using std::cout;
using std::endl;
using namespace std;

Roster::Roster() {
	this->capacity=0;
	this->lastStudentIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastStudentIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

void Roster::parseAdd(string row)
{
	if (lastStudentIndex < capacity) {
		lastStudentIndex++;
	}
		int numDaysArray[Student::courseArraySize];

		
		//Will parse through each 'student string' delimiting on the comma
		//Then extract each substring & set each field

		//read ID
		int rhs = row.find(",");
		string ID = row.substr(0, rhs);

		//read first name
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string fName = row.substr(lhs, rhs - lhs);

		//read last name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lName = row.substr(lhs, rhs - lhs);

		//read email
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string email = row.substr(lhs, rhs - lhs);

		//read age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string tempAge = row.substr(lhs, rhs - lhs));
		int age = stoi(tempAge);

		//read days in course per array entry
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		numDaysArray[0] = stoi(row.substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		numDaysArray[1] = stoi(row.substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		numDaysArray[2] = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		Degree degreeProgram;
		string degree = row.substr(lhs, rhs - lhs);
	
		add(ID, fName, lName, email, age, courseDays0, courseDays1, courseDays2, degreeProgram);


		//might need to move this to top
		if (degree == "NETWORK") { degreeProgram = Degree::NETWORK; }
		else if (degree == "SECURITY") { degreeProgram = Degree::SECURITY; }
		else if (degree == "SOFTWARE") { degreeProgram = Degree::SOFTWARE; }
		else { degreeProgram = Degree::UNKNOWN; exit(-1); }


	}


		void Roster::printAll()//call print method for each student
		{
			for (int i = 0; i <= lastStudentIndex; i++) (this->classRosterArray)[i]->print();
		}

		bool Roster::remove(string studentId)
		{
			bool found = true;
			for (int i = 0; i <= lastStudentIndex; i++)
			{
				if (classRosterArray[i]->getId() == studentId) // finds student
				{
					cout << "Removed" << endl;
					classRosterArray[i] = classRosterArray[lastStudentIndex];
					lastStudentIndex--;
					break;
				}
			}
			if (!found) { cout << "NOT FOUND" << endl; }
			return found;
		}

		void Roster::printAverageCourseDays(string studentId)
			{
			int avg = 0;
				for (int i = 0; i <= lastStudentIndex; i++)
				{
					string tempStudentID = classRosterArray[i]->getId(); //finds student

					if (tempStudentID == studentId) 
					{
						avg = ((classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3);
						cout << "Average number of days student: " << studentId << " has left is " << avg << endl;
					}
				}
			}

		void Roster::printInvalidEmail() {
			cout << "Invalid emails: " << endl;
				for (int i = 0; i < lastStudentIndex; i++ ) {
					string email = classRosterArray[i]->getEmail();
					if ((email.find('@') == string::npos) || (email.find(' ') != string::npos) || (email.find('.') == string::npos)) {
							cout << "Invalid email: " << email << endl;
						}
					}
				}

		void Roster::printByDegreeProgram(Degree d) {
				for (int i = 0; i <= lastStudentIndex; i++) {
					Degree deg = classRosterArray[i]->getDegree();
					if (deg == d) { this->classRosterArray[i]->print(); }
					}			
				cout << "Degree by program: " << degreeProgramStrings[d] << endl;

				}
		void add(string ID, string fName, string lName, string email, int age, int courseDays0, int courseDays1, int courseDays2, Degree degreeProgram) {
			int courseDays[Student::courseArraySize];
			courseDays[0] = courseDays0;
			courseDays[1] = courseDays1;
			courseDays[2] = courseDays2;

			classRosterArray[lastStudentIndex] = new Student(ID, fName, lName, email, age, courseDays, degreeProgram);   
		}
		

		Roster::~Roster()//destroys all students
				{
					for (int i = 0; i < 5; i++)
					{
						delete this->classRosterArray[i];
					}
					delete classRosterArray;
				}
