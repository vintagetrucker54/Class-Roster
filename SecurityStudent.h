#pragma once
#ifndef SECURITY_H
#define SECURITY_H
#include <iostream>
#include <string>
#include "Degree.h"
#include "Student.h"
using namespace std;

class SecurityStudent : public Student {

public:
	SecurityStudent();
	SecurityStudent(string Id, string fName, string lName, string email, int age, int* courseDays[], Degree degreeProgram);
	Degree getDegreeProgram();
	void setDegreeProgram(Degree degreeProgram);
	void print();


	~SecurityStudent();
};


#endif
