#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee {
private:
	string _name;
	int _pricePerHour;
	int _numOfHour;
public:
	string getName() { return _name; };
	int getPricePerHour() { return _pricePerHour; };
	int getNumOfHour() { return _numOfHour; };
public:
	HourlyEmployee() {};
	HourlyEmployee(string,int, int);
	int getPayment();
	shared_ptr<Employee> create(tuple<string, int*>);
	string className();
};