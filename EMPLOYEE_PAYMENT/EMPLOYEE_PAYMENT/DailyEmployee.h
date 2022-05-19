#pragma once
#include "Employee.h"

class DailyEmployee : public Employee {
private:
	string _name;
	int _pricePerDay;
	int _numOfDay;
public:
	string getName() { return _name; };
	int getPricePerDay() { return _pricePerDay; };
	int getNumOfDay() { return _numOfDay; };
public:
	DailyEmployee() {};
	DailyEmployee(string, int, int);
	int getPayment();
	shared_ptr<Employee> create(tuple<string, int*>);
	string className();
};