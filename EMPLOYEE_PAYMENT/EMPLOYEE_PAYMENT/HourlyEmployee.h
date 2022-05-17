#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee {
private:
	int _pricePerHour;
	int _numOfHour;

public:
	HourlyEmployee() {};
	HourlyEmployee(int, int);
	int getPayment();
	shared_ptr<Employee> generate(void* argm);
	string className();
};