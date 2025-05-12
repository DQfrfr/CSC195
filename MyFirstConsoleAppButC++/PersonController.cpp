#include <iostream>
#include <string>
#include <vector>
#include "PersonController.h"
#include <random>
#include "Prefix.h"
#include "Suffix.h"
using namespace std;

void PersonController::run()
{
	srand(time(0));
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
		userInput = lower(userInput);

		if (userInput == "f")
		{
			return Prefix::NONE;
		}
		else if (userInput == "mr" || userInput == "mr.")
		{
			return Prefix::Mr;
			
		}
		else if (userInput == "mrs" || userInput == "mrs.")
		{
			return Prefix::Mrs;
		}
		else if (userInput == "ms" || userInput == "ms.")
		{
			return Prefix::Ms;
		}
		else if (userInput == "dr" || userInput == "dr.")
		{
			return Prefix::Dr;
		}
		else if (userInput == "prof" || userInput == "prof.")
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
	int age = 0;

	while (true)
	{
		cout << "Please Enter your age: ";
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
		userInput = lower(userInput);

		if (userInput == "f")
		{
			return Suffix::NONE;
		}
		else if (userInput == "jr" || userInput == "jr.")
		{
			return Suffix::JR;
		}
		else if (userInput == "sr" || userInput == "sr.")
		{
			return Suffix::SR;
		}
		else if (userInput == "i")
		{
			return Suffix::I;
		}
		else if (userInput == "ii")
		{
			return Suffix::II;
		}
		else if (userInput == "iii")
		{
			return Suffix::III;
		}
		else if (userInput == "iv")
		{
			return Suffix::IV;
		}
		else if (userInput == "v")
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
	Person person = Person(firstname, lastname, age, prefix, suffix);
	generateFate(person);
	people.push_back(person);
}

void PersonController::createPerson(string firstname, string lastname, int age, Prefix prefix)
{
	Person person = Person(firstname, lastname, age, prefix);
	generateFate(person);
	people.push_back(person);
}

void PersonController::createPerson(string firstname, string lastname, int age, Suffix suffix)
{
	Person person = Person(firstname, lastname, age, suffix);
	generateFate(person);
	people.push_back(person);
}

void PersonController::createPerson(string firstname, string lastname, int age)
{
	Person person = Person(firstname, lastname, age);
	generateFate(person);
	people.push_back(person);
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

void PersonController::generateFate(Person &person)
{
	int roll = rand() % 10;

	if (roll > 3)
	{
		return;
	}

	std::vector<std::string> fates = {
	"won the lottery and vanished to Fiji.",
	"was last seen riding a bear into the sunset.",
	"joined an underground ping-pong cult.",
	"accidentally invented sentient bread.",
	"is now the mayor of a town with 2 people.",
	"got recruited by time travelers.",
	"started a business selling air in jars.",
	"faked their death and moved to Area 51.",
	"became a motivational speaker for squirrels.",
	"is currently lost in IKEA.",
	"challenged a goose to a duel and lost.",
	"was abducted by aliens but came back bilingual.",
	"turned into a cloud. Nobody knows how.",
	"became a professional kazoo player.",
	"lives on a houseboat with 17 cats.",
	"taught raccoons how to box.",
	"is trapped inside a vending machine.",
	"teleported into the backrooms.",
	"now haunts a Waffle House.",
	"became TikTok famous for doing taxes blindfolded.",
	"found Atlantis but refuses to tell anyone.",
	"married a ghost. Seems happy.",
	"now pilots a mech suit in a secret government facility.",
	"opened a restaurant that only serves toast.",
	"was turned into an NPC in a mobile game.",
	"won a staring contest with Medusa.",
	"gave up everything to chase a butterfly.",
	"became a werewolf accountant.",
	"permanently fused with their Roomba.",
	"is hiding in plain sight as a substitute teacher.",
	"tried to hug a cactus to prove a point.",
	"was reverse-adopted by a pack of wolves.",
	"wrote a bestselling book using only emojis.",
	"trained pigeons to deliver passive-aggressive notes.",
	"can now talk to plants, but they only gossip.",
	"accidentally became the leader of a robot uprising.",
	"was cursed to always be mildly damp.",
	"created a new language but forgot how it works.",
	"invented teleportation but lost the return button.",
	"tripped into a portal and is now a sidekick in a fantasy realm.",
	"swapped places with their mirror reflection."
	};

	string fate = fates[rand() % fates.size()];
	cout << "----- Random Event! -----" << endl;
	cout << person.getFullName() << "'s fate is now: " << fate << endl;
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

string PersonController::lower(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}
	return word;
}