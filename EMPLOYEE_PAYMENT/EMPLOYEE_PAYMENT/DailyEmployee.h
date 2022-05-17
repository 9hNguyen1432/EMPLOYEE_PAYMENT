#pragma once
#include "Employee.h"

class DailyEmployee : public Employee {
private:
	int _pricePerDay;
	int _numOfDay;
public:
	DailyEmployee() {};
	DailyEmployee(int, int);
	int getPayment();
	shared_ptr<Employee> generate(void* argm);
	string className();
};