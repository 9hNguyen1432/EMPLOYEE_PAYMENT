#pragma once
#include "Employee.h"

class Manager : public Employee {
private:
	int _pricePerStaff;
	int _numOfStaff;
	int _fixedPayment;
public:
	Manager() {};
	Manager(int, int, int);
	int getPayment();
	shared_ptr<Employee> generate(void* argm);
	string className();
};