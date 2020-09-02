#pragma once
#include "student.h"
#include "Degree.h"
#include <string>
#include <iostream>
#include <iomanip>
using std::left;
using std::setw;
using std::cerr;
using std::string;
using std::cout;
using namespace std;

//sets default
Student::Student() {
	this->studentId = "";
	this->fName = "";
	this->lName = "";
	this->email = "";
	this->age = 0;
	//this->courseDays = new int[courseArraySize];
	for (int i = 0; i < courseArraySize; i++) this->courseDays[i] = 0;
	this->degreeProgram = Degree::UNKNOWN;
}

//full construct
Student::Student(string ID, string fName, string lName, string email, int age, int courseDays[], Degree degreeProgram) {
	this->studentId = ID;
	this->fName = fName;
	this->lName = lName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < courseArraySize; i++) { this->courseDays[i] = courseDays[i]; }
	this->degreeProgram = degreeProgram;

};

//accessors
string Student::getId() { return studentId; }
string Student::getFName() { return fName; }
string Student::getLName() { return lName; }
string Student::getEmail() { return email; }
int Student::getAge() { return age; }
int* Student::getDays() { return courseDays; }
Degree Student::getDegree() { return degreeProgram; }


//mutators
void Student::setId(string ID) { this->studentId = ID; }
void Student::setFName(string fName) { this->fName = fName; }
void Student::setLName(string lName) { this->lName = lName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int courseDays[]) {
	for (int i = 0; i < courseArraySize; i++) {
		this->courseDays[i] = courseDays[i];
	}
}
void Student::setDegree(Degree degreeProgram) { this->degreeProgram = degreeProgram; }


//Displays fields
void Student::print() {
	cout << left << setw(5) << studentId;
	cout << left << setw(25) << fName;
	cout << left << setw(25) << lName;
	cout << left << setw(45) << email;
	cout << left << setw(5) << age;
	cout << left << setw(5) << courseDays[0];
	cout << left << setw(5) << courseDays[1];
	cout << left << setw(5) << courseDays[2];
	cout << left << setw(15) << degreeProgramStrings[(int)getDegree()] << endl;
}




