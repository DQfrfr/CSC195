#include <iostream>
#include <string>
#include <vector>
#include "PersonController.h"
#include "Prefix.h"
#include "Suffix.h"
using namespace std;

void PersonController::run()
{
	collectPersonInfo();
	createPerson();
	Person temp = Person("John", "Doe", 30, Prefix::Mr, Suffix::NONE);
	people.push_back(temp);

	cout << "Hello " << people[0].getFullName() << "!" << endl;

	do
	{
		// Loop over and repaetedly ask user to add People or not until they say no
		// Then print all people and shutdown
		cout << "Do you want to add another person? (y/n): ";
		string choice = "";
		cin >> choice;

		if (choice == "y" || choice == "Y")
		{
			collectPersonInfo();
			createPerson();
			cout << "Hello " << people[people.size() - 1].getFullName() << "!" << endl;
		}
		else if (choice == "n" || choice == "N")
		{
			printPeople();
			exit(0);
		}
		else
		{
			cout << "Invalid input. Please enter 'y' or 'n'." << endl;
		}

	} while (true);
}

void PersonController::collectPersonInfo()
{
	cout << "Collect Person Info" << endl;
}

void PersonController::validatePrefix()
{
	cout << "Validate Prefix" << endl;
}

void PersonController::validateName()
{
	cout << "Validate Name" << endl;
}

void PersonController::validateAge()
{
	cout << "Validate Age" << endl;
}

void PersonController::validateSuffix()
{
	cout << "Validate Suffix" << endl;
}

void PersonController::createPerson()
{
	cout << "Create Person" << endl;
	// Collect person info and create a new Person object
	// Add the new Person object to the people vector
	// Example:
	// Person newPerson("John", "Doe", 30, Prefix::Mr, Suffix::NONE);
	// addToArray(newPerson);
}

void PersonController::addToArray(Person person)
{
	people.push_back(person);
}

void PersonController::printPeople()
{
	cout << "Print People" << endl;
}

string PersonController::olderOrYounger(int index)
{
	cout << "Older or Younger" << endl;
	return "";
}