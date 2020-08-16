#include <iostream>
#include "pch.h"
#include "SoftwareStudent.h"
#include "Student.h"
#include "Degree.h"

using namespace std;

SoftwareStudent::SoftwareStudent() {
	setDegreeProgram(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string Id, string fName, string lName, string email, int age, int* courseDays[], Degree degreeProgram)
{
	setDegreeProgram(SOFTWARE);
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}


void SoftwareStudent::setDegreeProgram(Degree degreeProgram)
{
	degreeProgram = SOFTWARE;
}



void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
}
