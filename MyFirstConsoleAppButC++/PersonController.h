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
	vector<Person> people;

    void collectPersonInfo();

    Prefix validatePrefix();

    vector<string> validateName();

    int validateAge();

    Suffix validateSuffix();

	void createPerson(string firstname, string lastname, int age, Prefix prefix, Suffix suffix);

	void createPerson(string firstname, string lastname, int age, Prefix prefix);

	void createPerson(string firstname, string lastname, int age, Suffix suffix);

	void createPerson(string firstname, string lastname, int age);

    void generateFate(Person &person);

    void printPeople();

    string olderOrYounger(int index);

public:
	void run();
};
