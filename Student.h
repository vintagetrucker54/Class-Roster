#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Degree.h"
#include<iostream>
#include<string>

using std::string;
using namespace std;


class Student {  //Represents a student
private:
	string studentId;
	string fName;
	string lName;
	string email;
	int age;
	int courseDays[3];//Days left in Course will be an array of 3
	Degree degreeProgram;//Enum val: NETWORK, SECURITY, SOFTWARE OR UNKNOWN
public:
	const static int courseArraySize = 3;
	
	//Emtpy construct
	Student();

	//Full construct
	Student(string ID, string fName, string lName, string email, int age, int courseDays[], Degree degreeProgram);

    //accessors
	string getId();
	string getFName();
	string getLName();
	string getEmail();
	int getAge();
	int* getDays();
	Degree getDegree();

	//mutators
	void setId(string ID);
	void setFName(string fName);
	void setLName(string lName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int courseDays[]);
	void setDegree(Degree d);
	void print();

	//destruct
	~Student();
};


#endif // !STUDENT_H
