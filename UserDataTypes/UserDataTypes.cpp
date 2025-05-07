#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
    int numOfEmployees = 0;

    cout << "Enter the amount of employees. (max 5): \n";

    while (1) 
    {
        cin >> numOfEmployees;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid input. (1-5)";
            continue;
        }

        if (numOfEmployees > 5 || numOfEmployees < 1)
        {
            cout << "Please enter a number between 1 and 5. Try again" << endl;
            continue;
        }
        break;
    }

    Employee employees[5];

    for (int i = 0; i < numOfEmployees; i++) 
    {
        cout << "Enter Employee " << i + 1 << " Deatails" << endl;
        employees[i].Read();
    }

    cout << "\n--- Payroll Summary ---\n" << endl;
    for (int i = 0; i < numOfEmployees; i++) 
    {
        employees[i].Write();
    }

    return 0;
}
