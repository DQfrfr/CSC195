#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
using namespace std;


const float Employee::TAX = .1f; // Declare tax as a static constant

void Employee::Read()
{
	cout << "Enter employee's First name: ";
	cin >> name;

	cout << "Enter employee last initial: ";
	cin >> initial;

	while (1) {
		cout << "Enter employee age: ";
		cin >> age;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a valid input." << endl;
			continue;
		}

		if (age < 0) 
		{
			cout << "Please enter a positive value" << endl;
			continue;
		} else 
		{
			break;
		}
	}

	while (1) {
		cout << "Enter employee zipcode: ";
		cin >> zipcode;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a valid input." << endl;
			continue;
		}
		if (zipcode < 11111 || zipcode > 99999) {
			cout << "Invalid zipcode. Please enter a 5-digit number.\n";
			continue;
		}
		else {
			break;
		}
	}

	cout << "Enter employee's hourly wage: ";
	cin >> wage;

	while (1) {
		cout << "Enter number of days worked (Max 7) ";
		cin >> daysWorked;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a valid input." << endl;
			continue;
		}
		if (daysWorked < 1 || daysWorked > 7) {
			cout << "Please enter a number between 1 and 7.\n";
			continue;
		}
		else {
			break;
		}
	}

	getDailyHoursWorked();
	isAdult = age >= 18;
}

void Employee::Write()
{
	vector<float> payroll = calculatePayroll();

	cout << "\nEmployee Payroll Summary\n";
	cout << "-------------------------\n";
	cout << "Name: " << name << " " <<initial << ".\n";
	cout << "Age: " << age << " (Adult: " << (isAdult ? "Yes" : "No") << ")\n";
	cout << "Zipcode: " << zipcode << "\n";
	cout << "Hourly Wage: $" << wage << " per hour\n";
	cout << "Total Hours Worked: " << totalHours << " hours\n";
	cout << "Gross Income: $" << payroll[0] << "\n";
	cout << "Tax Amount: $" << payroll[1] << "\n";
	cout << "Net Income: $" << payroll[2] << "\n";
}

void Employee::getDailyHoursWorked() {
	totalHours = 0;
	for (int i = 0; i < daysWorked; i++) {
		cout << "Enter hours worked on day " << i + 1 << ": ";
		cin >> hoursWorkedPerDay[i];

		totalHours += hoursWorkedPerDay[i];
	}
}

// [0] = grossIncome, [1] = taxAmount, [2] = netIncome
vector<float> Employee::calculatePayroll() {
	vector<float> payroll(3);
	payroll[0] = wage * totalHours;
	payroll[1] = payroll[0] * TAX;
	payroll[2] = payroll[0] - payroll[1];
	return payroll;
}