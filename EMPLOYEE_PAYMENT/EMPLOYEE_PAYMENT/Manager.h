#pragma once
#include "Employee.h"

class Manager : public Employee {
private:
	string _name;
	int _pricePerStaff;
	int _numOfStaff;
	int _fixedPayment;
public:
	string getName() { return _name; };
	int getPricePerStaff() { return _pricePerStaff; };
	int getNumOfStaff() { return _numOfStaff; };
	int getFixedPayment() { return _fixedPayment; };
public:
	Manager() {};
	Manager(string, int, int, int);
	int getPayment();
	shared_ptr<Employee> create(tuple<string, int*>);
	string className();
};