#pragma once
#ifndef SOFTWARE_H
#define SOFTWARE_H
#include <iostream>
#include <string>
#include "Degree.h"
#include "Student.h"
using namespace std;

class SoftwareStudent : public Student {

public:
	SoftwareStudent();
	SoftwareStudent(string Id, string fName, string lName, string email, int age, int* courseDays[], Degree degreeProgram);
	Degree getDegreeProgram();
	void setDegreeProgram(Degree degreeProgram);
	void print();


	~SoftwareStudent();
};


#endif
