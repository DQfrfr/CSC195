#pragma once
#include <string>
#include "Prefix.h"
#include "Suffix.h"
using namespace std;

class Person
{
	string firstName;
	string lastName;
	string fate;
	int age;
	Prefix prefix;
	Suffix suffix;

	void setFirstName(string firstname);

	void setLastName(string lastname);

	void setAge(int age);

	void setPrefix(Prefix prefix);

	void setSuffix(Suffix suffix);

public:
	void setFate(string fate);

	string getFullName();

	string getFirstName();

	string getFate();

	string getLastName();

	int getAge();

	string getPrefixString();

	string getSuffixString();

	Person(string firstName, string lastName, int age, Prefix prefix, Suffix suffix);

	Person(string firstName, string lastName, int age, Prefix prefix);

	Person(string firstName, string lastName, int age, Suffix suffix);

	Person(string firstName, string lastName, int age);

	string toString();
};