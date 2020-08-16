#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include <list>
#include <array>
#include "pch.h"
#include "Student.h"
#include "Degree.h"

class Roster;
//Roster stores Students
class Roster {
public:
	int lastStudentIndex;                                    //index of last student in repository
	int capacity;                                            //max size of repository
	Student** classRosterArray;                              //array of pointers to students
	Roster();                                                //empty construct, initializes default vals
	Roster(int capacity);
	void add(string datarow);                                //parses strings, creates Student objects
	void printAll();                                         //prints all students in repository using each Student's print() method
	void remove(string studentId);                           //removes a student based on ID
	void printAverageCourseDays(string studentId);           //prints avg # of days left in courses
	void printInvalidEmail();                                //locates and prints invalid emails
	void printByDegreeProgram(Degree degreeProgram);         //prints all students in specific degree
	
	~Roster();//destruct 
};


#endif // ROSTER_H
