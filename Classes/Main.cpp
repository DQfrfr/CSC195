#include <iostream>
#include <string>
#include "Media.h"
#include "Image.h"
#include "Video.h"
#include "database.h"
using namespace std;

int DisplayMenu()
{
	cout << "1. Create" << endl;
	cout << "2. Display All" << endl;
	cout << "3. Display by Name" << endl;
	cout << "4. Display by Type" << endl;
	cout << "5. Exit" << endl;

	int choice;
	cin >> choice;
	cout << endl;
	return choice;

}

void createMedia(Database &db)
{
	int type;
	while (1)
	{
		cout << "Enter media type (1: Video, 2: Image): ";
		cin >> type;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}
		if (type < 1 || type > 2)
		{
			cout << "Invalid type. Please try again." << endl;
			continue;
		}
		db.Create(static_cast<eType>(type));
		break;
	}
}

void displayName(Database& db)
{
	string name;
	cout << "Enter media name: ";
	cin >> name;
	db.Display(name);
}

void displayByType(Database& db)
{
	int type;
	while (1)
	{
		cout << "Enter media type (1: Video, 2: Image): ";
		cin >> type;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}
		if (type < 1 || type > 3)
		{
			cout << "Invalid type. Please try again." << endl;
			continue;
		}
		db.Display(static_cast<eType>(type));
		break;
	}
}

int main()
{
	Database* db = new Database();
	bool active = true;
	while (active)
	{
		switch (DisplayMenu())
		{
		case 1:
			createMedia(*db);
			break;
		case 2:
			db->DisplayAll();
			break;
		// Needs work. Should check db to see if its empty
		case 3:
			displayName(*db);
			break;
		case 4:
			displayByType(*db);
			break;
		case 5:
			active = false;
			db->~Database();
			break;
		} 	
	}

	return 0;
}