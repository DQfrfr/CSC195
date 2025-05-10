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

void Person::setFate(string fate)
{
	this->fate = fate;
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
	case Suffix::JR:
		return " Jr.";
	case Suffix::SR:
		return " Sr.";
	case Suffix::I:
		return " I";
	case Suffix::II:
		return " II";
	case Suffix::III:
		return " III";
	case Suffix::IV:
		return " IV";
	case Suffix::V:
		return " V";
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
	setSuffix(Suffix::NONE);
}

Person::Person(string firstname, string lastname, int age, Suffix suffix)
{
	setFirstName(firstname);
	setLastName(lastname);
	setAge(age);
	setSuffix(suffix);
	setPrefix(Prefix::NONE);
}

Person::Person(string firstname, string lastname, int age)
{
	setFirstName(firstname);
	setLastName(lastname);
	setAge(age);
	setPrefix(Prefix::NONE);
	setSuffix(Suffix::NONE);
}

string Person::toString()
{
	return getFullName() + " is " + to_string(age) + " years old";
}

string Person::getFate()
{
	return fate;
}