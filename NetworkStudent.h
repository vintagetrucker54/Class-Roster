#pragma once

#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <string>
#include "Degree.h"
#include "Student.h"
using namespace std;

class NetworkStudent : public Student {
public:
	NetworkStudent();
	NetworkStudent(string Id, string fName, string lName, string email, int age, int* courseDays[], Degree degreeProgram);
	Degree getDegreeProgram();
	void setDegreeProgram(Degree degreeProgram);
	void print();


	~NetworkStudent();
};



#endif
