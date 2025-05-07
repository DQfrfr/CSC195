#pragma once
#include <iostream>
#include <string>
#include <vector>

class Employee {
public:
    void Read();
    void Write();
    void getDailyHoursWorked();

private:
    std::string name;
    char initial;
    short age;
    bool isAdult;
    unsigned int zipcode;
    float wage;
    short daysWorked;
    float hoursWorkedPerDay[7];
    float totalHours;

    static const float TAX;

    std::vector<float> calculatePayroll();
};