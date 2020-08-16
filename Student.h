#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#include "Degree.h"

#include<iostream>
#include<iomanip>
#include<string>
using std::string;
using std::cout;

class Student {  //Represents a student
private:
	string studentId;
	string fName;
	string lName;
	string email;
	int age;
	int* courseDays;//Days left in Course will be an array of 3
	Degree degreeProgram;//Enum val: NETWORK, SECURITY, OR SOFTWARE

public:
	const static int courseArraySize = 3;
	Student();//emtpy construct
	Student(string ID, string fName, string lName, string email, int age, int courseDays[], Degree degreeProgram);//Full construct

//accessor for fields
	string getId();
	string getFName();
	string getLName();
	string getEmail();
	int getAge();
	int* getDays();
	Degree getDegreeProgram();

	//accessors
	void setId(string ID);
	void setFName(string fName);
	void setLName(string lName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int courseDays[]);
	void setDegreeProgram(Degree degreeProgram);
	void print();

	//destruct
	~Student();
};


#endif // !STUDENT_H
