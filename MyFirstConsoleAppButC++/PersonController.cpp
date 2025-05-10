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
			cout << people[people.size() - 1].getFullName() << " Was Added!" << endl;
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
	Prefix prefix = validatePrefix();
	vector<string> name = validateName();
	string firstName = name[0];
	string lastName = name[1];
	int age = validateAge();
	Suffix suffix = validateSuffix();

	// Do a check to see if the user entered a prefix or suffix
	if (prefix == Prefix::NONE && suffix == Suffix::NONE)
	{
		createPerson(firstName, lastName, age);
	}
	else if (prefix != Prefix::NONE && suffix == Suffix::NONE)
	{
		createPerson(firstName, lastName, age, prefix);
	}
	else if (prefix == Prefix::NONE && suffix != Suffix::NONE)
	{
		createPerson(firstName, lastName, age, suffix);
	}
	else
	{
		createPerson(firstName, lastName, age, prefix, suffix);
	}
}

Prefix PersonController::validatePrefix()
{
	string userInput = "";

	while (true)
	{
		cout << "Please enter any prefixes if applicable (f to skip)" << endl;
		cin >> userInput;

		if (userInput == "f" || userInput == "F")
		{
			return Prefix::NONE;
		}
		else if (userInput == "Mr" || userInput == "Mr.")
		{
			return Prefix::Mr;
			
		}
		else if (userInput == "Mrs" || userInput == "Mrs.")
		{
			return Prefix::Mrs;
		}
		else if (userInput == "Ms" || userInput == "Ms.")
		{
			return Prefix::Ms;
		}
		else if (userInput == "Dr" || userInput == "Dr.")
		{
			return Prefix::Dr;
		}
		else if (userInput == "Prof" || userInput == "Prof.")
		{
			return Prefix::Prof;
		}
		else
		{
			cout << "Invalid prefix. Please try again." << endl;
		}
	}
}

//vector[0] = firstName, vector[1] = lastName
vector<string> PersonController::validateName()
{
	vector<string> name;
	string firstName = "";
	string lastName = "";

	while (true)
	{
		cout << "Please enter your first name: ";
		cin >> firstName;
		if (firstName.length() < 2)
		{
			cout << "First name must be at least 2 characters long." << endl;
			continue;
		}
		name.push_back(firstName);
		break;
	}

	while (true)
	{
		cout << "Please Enter your last name: ";
		cin >> lastName;
		if (lastName.length() < 2)
		{
			cout << "Last name must be at least 2 characters long." << endl;
			continue;
		}
		name.push_back(lastName);
		break;
	}

	return name;
}

int PersonController::validateAge()
{
	cout << "Please Enter your age: ";
	int age = 0;

	while (true)
	{
		cin >> age;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a valid input." << endl;
			continue;
		}
		if (age < 0)
		{
			cout << "Please enter a positive value" << endl;
			continue;
		}
		else if (age > 120)
		{
			cout << "Be fr now" << endl;
			continue;
		}
		else
		{
			return age;
		}
	}
}

Suffix PersonController::validateSuffix()
{
	while (true)
	{
		cout << "Please enter any suffixes if applicable (f to skip)" << endl;
		string userInput = "";
		cin >> userInput;

		if (userInput == "f" || userInput == "F")
		{
			return Suffix::NONE;
		}
		else if (userInput == "Jr" || userInput == "Jr.")
		{
			return Suffix::JR;
		}
		else if (userInput == "Sr" || userInput == "Sr.")
		{
			return Suffix::SR;
		}
		else if (userInput == "I" || userInput == "i")
		{
			return Suffix::I;
		}
		else if (userInput == "II" || userInput == "ii")
		{
			return Suffix::II;
		}
		else if (userInput == "III" || userInput == "iii")
		{
			return Suffix::III;
		}
		else if (userInput == "IV" || userInput == "iv")
		{
			return Suffix::IV;
		}
		else if (userInput == "V" || userInput == "v")
		{
			return Suffix::V;
		}
		else
		{
			cout << "Invalid suffix. Please try again." << endl;
		}

	}
}

void PersonController::createPerson(string firstname, string lastname, int age, Prefix prefix, Suffix suffix)
{
	people.push_back(Person(firstname, lastname, age, prefix, suffix));
}

void PersonController::createPerson(string firstname, string lastname, int age, Prefix prefix)
{
	people.push_back(Person(firstname, lastname, age, prefix));
}

void PersonController::createPerson(string firstname, string lastname, int age, Suffix suffix)
{
	people.push_back(Person(firstname, lastname, age, suffix));
}

void PersonController::createPerson(string firstname, string lastname, int age)
{
	people.push_back(Person(firstname, lastname, age));
}

void PersonController::printPeople()
{
	if (people.size() <= 1)
	{
		return;
	}
	for (int i = 1; i < people.size(); i++)
	{
		cout << people[i].toString() << olderOrYounger(i) << endl;
	}
}

string PersonController::olderOrYounger(int i)
{
	if (people[i].getAge() > people[0].getAge())
	{
		return " - Older than you.";
	}
	else if (people[i].getAge() < people[0].getAge())
	{
		return " - Younger than you.";
	}
	else
	{
		return " - Same age as you.";
	}
	return "";
}