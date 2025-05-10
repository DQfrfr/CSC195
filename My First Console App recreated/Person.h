#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Suffix.h"
#include "Prefix.h"
using namespace std;

class Person {
	Prefix prefix;
	string firstname;
	string lastname;
	Suffix suffix;
	unsigned short age;

public:
	void setPrefix(Prefix p);

	void setFirstName(string f);

	void setLastName(string l);

	void setSuffix(Suffix s);

	void setAge(unsigned short a);

	string GetFullName();

	unsigned short GetAge();

	Person();
};