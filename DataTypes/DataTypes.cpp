#include <iostream>
#include <array>
#include <vector>
using namespace std;

const float TAX = 0.1f;

struct employee {
    string name;
    char initial;
    short age;
    bool isAdult;
    unsigned int zipcode;
    float wage;
    short daysWorked;
    float hoursWorkedPerDay[7];
	float totalHours;
};

// [0] = grossIncome, [1] = taxAmount, [2] = netIncome
vector<float> calculatePayroll(employee emp) {
	vector<float> payroll(3);
	payroll[0] = emp.wage * emp.totalHours;
	payroll[1] = payroll[0] * TAX;
	payroll[2] = payroll[0] - payroll[1];
	return payroll;
}

void printDetails(employee &emp) {
	vector<float> payroll = calculatePayroll(emp);

	cout << "\nEmployee Payroll Summary\n";
	cout << "-------------------------\n";
	cout << "Name: " << emp.name << " " << emp.initial << ".\n";
	cout << "Age: " << emp.age << " (Adult: " << (emp.isAdult ? "Yes" : "No") << ")\n";
	cout << "Zipcode: " << emp.zipcode << "\n";
	cout << "Hourly Wage: $" << emp.wage << " per hour\n";
	cout << "Total Hours Worked: " << emp.totalHours << " hours\n";
	cout << "Gross Income: $" << payroll[0] << "\n";
	cout << "Tax Amount: $" << payroll[1] << "\n";
	cout << "Net Income: $" << payroll[2] << "\n";
}

void getDailyHoursWorked(employee &emp) {
	emp.totalHours = 0;
	for (int i = 0; i < emp.daysWorked; i++) {
		cout << "Enter hours worked on day " << i + 1 << ": ";
		cin >> emp.hoursWorkedPerDay[i];

		emp.totalHours += emp.hoursWorkedPerDay[i];
	}
}

void collectDetails(employee &emp) {
	cout << "Enter employee's First name: ";
	cin >> emp.name;

	cout << "Enter employee last initial: ";
	cin >> emp.initial;

	while (1) {
		cout << "Enter employee age: ";
		cin >> emp.age;
		if (emp.age < 0) {
			cout << "Please enter a positive value" << endl;
			continue;
		} 
		else {
			break;
		}
	}

	while (1) {
		cout << "Enter employee zipcode: ";
		cin >> emp.zipcode;
		if (emp.zipcode < 11111 || emp.zipcode > 99999) {
			cout << "Invalid zipcode. Please enter a 5-digit number.\n";
			continue;
		}
		else {
			break;
		}
	}

	cout << "Enter employee's hourly wage: ";
	cin >> emp.wage;

	while (1) {
		cout << "Enter number of days worked (Max 7) ";
		cin >> emp.daysWorked;
		if (emp.daysWorked < 1 || emp.daysWorked > 7) {
			cout << "Please enter a number between 1 and 7.\n";
			continue;
		}
		else {
			break;
		}
	}

	emp.isAdult = emp.age >= 18;
}

int main() {
	employee emp;
	collectDetails(emp);
	getDailyHoursWorked(emp);
	printDetails(emp);
}