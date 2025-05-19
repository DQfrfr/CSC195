#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>
using namespace std;

void vectorPrint(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void printList(list<string>& lst)
{
	// Looping through using an iterator
	for (string fruit : lst)
	{
		cout << fruit << " ";
	}
	cout << endl;
}

void printMap(map<string, int>& m)
{
	// Printing using auto so i dont have to worry about the type
	for (auto& pair : m)
	{
		cout << pair.first << ": " << pair.second << endl;
	}
	cout << endl;
}

void Arrays()
{
	// Arrays
	
	// Initilizing a 7 string long string array
	string daysOfTheWeek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	// Getting the length of the array
	int arrLength = sizeof(daysOfTheWeek) / sizeof(daysOfTheWeek[0]);

	// looping through array and printing each value 
	for (int i = 0; i <= arrLength - 1; i++)
	{
		cout << daysOfTheWeek[i] << endl;
	}
	cout << endl;
}

void vectors()
{
	// Vectors

	// Initializing a vector of integers
	vector<int> numbers = { 1, 2, 3, 4, 5 };

	// Adding and removing an element to the end of the vector
	numbers.push_back(6);
	numbers.push_back(7);

	// printing before and after removing the last element
	vectorPrint(numbers);
	numbers.pop_back();
	vectorPrint(numbers);
	cout << endl;
}

void lists()
{
	// Lists

	// Initializing a list of strings
	list<string> fruits = { "Apple", "Banana", "Cherry" };

	// Adding and removing elements to the front and back of the list
	fruits.emplace_front("Mango");
	fruits.emplace_back("Orange");

	// Printing before and after removing an element
	printList(fruits);
	fruits.remove("Banana");
	printList(fruits);
	cout << endl;
}

void maps()
{
	// Maps

	// Initializing a map of strings and integers
	map<string, int> stock = { {"Apple", 50}, {"Banana", 30}, {"Cherry", 20} };

	// Printing before and after modifying an element
	printMap(stock);
	stock["Banana"] = 20;
	printMap(stock);
}

int main()
{
	Arrays();
	vectors();
	lists();
	maps();
	return 0;
}
