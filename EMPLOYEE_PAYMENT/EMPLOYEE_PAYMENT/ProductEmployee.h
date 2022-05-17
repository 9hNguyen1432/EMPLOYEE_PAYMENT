#pragma once
#include "Employee.h"

class ProductEmployee : public Employee {
private:
	int _pricePerProduct;
	int _numOfProduct;
public:
	ProductEmployee() {};
	ProductEmployee(int, int);
	int getPayment();
	shared_ptr<Employee> generate(void* argm);
	string className();
};