#include <iostream>
#include "pch.h"
#include "SecurityStudent.h"
#include "Student.h"
#include "Degree.h"

using namespace std;

SecurityStudent::SecurityStudent() {
	setDegreeProgram(SECURITY);
}

SecurityStudent::SecurityStudent(string Id, string fName, string lName, string email, int age, int* courseDays[], Degree degreeProgram)
{
	setDegreeProgram(SECURITY);
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}


void SecurityStudent::setDegreeProgram(Degree degreeProgram)
{
	degreeProgram = SECURITY;
}


void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;
}
