#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include <list>
#include <array>
#include "Student.h"
#include "Degree.h"
using namespace std;




//Roster stores Students
class Roster {
public:
	int lastStudentIndex;                           //index of last student in repository
	int capacity;                                   //max size of repository
	Student** classRosterArray;                     //array of pointers to students
	Roster();                                       //empty construct, initializes default vals
	Roster(int capacity);
	void parseAdd(string datarow);                  //parses strings, creates Student objects
	void add(string ID, string fName, string lName, string email, int age, int courseDays0, int courseDays1, int courseDays2, Degree degreeProgram);
	void printAll();                                //prints all students in repository using each Student's print() method
	bool remove(string studentId);                  //removes a student based on ID
	void printAverageCourseDays(string studentId);  //prints avg # of days left in courses for student with specific ID
	void printInvalidEmail();                       //locates and prints invalid emails
	void printByDegreeProgram(Degree d);            //prints all students in specific degree
	Student* getStudentAt(int lastStudentIndex);

	
};


#endif // ROSTER_H
