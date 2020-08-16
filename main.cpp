// Roster-c867.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Degree.h"
#include "roster.h"
#include "Student.h"
#include <iostream>
#include "roster.cpp"
#include "main.h"
using std::cerr;
using std::string;
using std::cout;
using std::endl;



//Input is 7 long comma-delimited strings
string classRosterArray[numStudents] =

{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Jonathan,Fletcher,jflet63@wgu.edu,33,99,99,99,SOFTWARE" };

int main()
{

	Roster* Roster;
	for (int i = 0; i < numStudents; ++i) {
		Roster->add(numStudents[classRosterArray]);
	}

	Roster->printAll();
	cout << endl;

	cout << "Invalid Emails" << endl;
	Roster->printInvalidEmail();
	cout << endl;

	cout << "Average days per class for each student" << endl;
	for (int i = 0; i < numStudents; ++i) {
		Roster->printAverageCourseDays(Roster->classRosterArray[i]->getId());
	}
	cout << endl;

	Roster->printByDegreeProgram(SOFTWARE);
	cout << endl;
	Roster->remove("A3");
	cout << endl;
	Roster->remove("A3");
	cout << endl;


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
