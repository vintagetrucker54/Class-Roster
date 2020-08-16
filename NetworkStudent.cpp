
#include "pch.h"
#include <iostream>
#include "NetworkStudent.h"
#include "Student.h"
#include "Degree.h"
using namespace std;

NetworkStudent::NetworkStudent() {
	setDegreeProgram(NETWORK);
}

NetworkStudent::NetworkStudent(string Id, string fName, string lName, string email, int age, int* courseDays[], Degree degreeProgram)
{
	setDegreeProgram(NETWORK);
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}


void NetworkStudent::setDegreeProgram(Degree degreeProgram)
{
	degreeProgram = NETWORK;
}



void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
	delete this;
}
