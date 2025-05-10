#include <iostream>
#include <string>
#include "Person.h"
#include "Prefix.h"
#include "Suffix.h"
using namespace std;

void Person::setFirstName(string firstname)
{
	this->firstName = firstname;
}

void Person::setLastName(string lastname)
{
	this->lastName = lastname;
}

void Person::setAge(int age)
{
	this->age = age;
}

void Person::setPrefix(Prefix prefix)
{
	this->prefix = prefix;
}

void Person::setSuffix(Suffix suffix)
{
	this->suffix = suffix;
}

string Person::getFullName()
{
	return getPrefixString()  + firstName + " " + lastName + getSuffixString();
}

string Person::getFirstName()
{
	return firstName;
}

string Person::getLastName()
{
	return lastName;
}

int Person::getAge()
{
	return age;
}

string Person::getPrefixString()
{
	switch (prefix)
	{
	case Prefix::NONE:
		return "";
	case Prefix::Mr:
		return "Mr. ";
	case Prefix::Mrs:
		return "Mrs. ";
	case Prefix::Ms:
		return "Ms. ";
	case Prefix::Dr:
		return "Dr. ";
	case Prefix::Prof:
		return "Prof. ";
	}
}

string Person::getSuffixString()
{
	switch (suffix)
	{
	case Suffix::NONE:
		return "";
	case Suffix::Mr:
		return " Mr.";
	case Suffix::Mrs:
		return " Mrs.";
	case Suffix::Ms:
		return " Ms.";
	case Suffix::Dr:
		return " Dr.";
	case Suffix::Prof:
		return " Prof.";
	}
}

Person::Person(string firstname, string lastname, int age1, Prefix prefix, Suffix suffix)
{
	setFirstName(firstname);
	setLastName(lastname);
	setAge(age1);
	setPrefix(prefix);
	setSuffix(suffix);
}

Person::Person(string firstname, string lastname, int age, Prefix prefix)
{
	setFirstName(firstname);
	setLastName(lastname);
	setAge(age);
	setPrefix(prefix);
}

Person::Person(string firstname, string lastname, int age, Suffix suffix)
{
	setFirstName(firstname);
	setLastName(lastname);
	setAge(age);
	setSuffix(suffix);
}

Person::Person(string firstname, string lastname, int age)
{
	setFirstName(firstname);
	setLastName(lastname);
	setAge(age);
}

string Person::toString()
{
	return getFullName() + " is " + to_string(age) + " years old.";
}
