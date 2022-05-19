#pragma once
#include "Employee.h"

class ProductEmployee : public Employee {
private:
	string _name;
	int _pricePerProduct;
	int _numOfProduct;
public:
	string getName() { return _name; };
	int getPricePerProduct() { return _pricePerProduct; };
	int getNumOfProduct() { return _numOfProduct; };
public:
	ProductEmployee() {};
	ProductEmployee(string, int, int);
	int getPayment();
	shared_ptr<Employee> create(tuple<string, int*>);
	string className();
};