#pragma once
#ifndef DEGREE_H
#define DEGREE_H

#include<iostream>
#include<iomanip>
#include<string>

using std::string;


enum Degree { NETWORK, SECURITY, SOFTWARE, UNKNOWN };
static const std::string degreeProgramStrings[] = { "NETWORK", "SECURITY", "SOFTWARE", "UNKNOWN" };


#endif // !DEGREE_H
