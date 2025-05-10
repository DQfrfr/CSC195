#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include "Prefix.h"
#include "Suffix.h"
using namespace std;

class PersonController
{
	string firstName;
	string lastName;
	int age;
	Prefix prefix;
	Suffix suffix;
	vector<Person> people;

    void collectPersonInfo();

    void validatePrefix();

    void validateName();

    void validateAge();

    void validateSuffix();

    void createPerson();

    void addToArray(Person person);

    void printPeople();

    string olderOrYounger(int index);

public:
	void run();
};
