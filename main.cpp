// C867-PA-Roster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include "Degree.h"
#include "roster.h"
#include "Student.h"
#include <iostream>
using std::cerr;
using std::string;
using std::cout;
using std::endl;
using namespace std;


int main()
{
	cout << endl << "   WGU - Scripting & Programming - C867   " << endl;
	cout << endl << "    Jonathan Fletcher - ID# 001427881     " << endl << endl;

	const static int numStudents = 5;
	string studentData[numStudents] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jonathan,Fletcher,jflet63@wgu.edu,33,99,99,99,SOFTWARE" };


	 Roster* classRoster = new Roster(numStudents);

	for (int i = 0; i < numStudents; i++) {
		classRoster->parseAdd(studentData[i]);
	}

	cout << "Students: " << endl;
	classRoster->printAll();
	cout << endl;

	cout << "Invalid Emails: " << endl;
	classRoster->printInvalidEmail();
	cout << endl;

	cout << "Average days per class for each student: " << endl;
	for (int i = 0; i < numStudents; ++i) {
		classRoster->printAverageCourseDays(classRoster->classRosterArray[i]->getId());
	}
	cout << endl;

	cout << "Software Degree Students: ";
	classRoster->printByDegreeProgram(Degree::SOFTWARE);
	cout << endl;
	if (classRoster->remove("A3")) classRoster->printAll();
	else cout << "Student not found" << endl; 
	cout << endl;
	if (classRoster->remove("A3")) classRoster->printAll();//Second remove for error check
	else cout << "Student not found" << endl;

	system("pause");
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
