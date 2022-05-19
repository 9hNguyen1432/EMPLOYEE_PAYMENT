#include "Manager.h"

Manager::Manager(string name, int fixPayment,  int numOfStaff, int price)
{
	_name = name;
	_pricePerStaff = price;
	_numOfStaff = numOfStaff;
	_fixedPayment = fixPayment;
}

int Manager::getPayment()
{
	int result;
	result = _fixedPayment + _pricePerStaff * _numOfStaff;
	return result;
}

shared_ptr<Employee> Manager::create(tuple<string, int*> data)
{
	int* temp = get<1>(data);
	shared_ptr<Employee> result = make_shared<Manager>(get<0>(data), temp[0], temp[1], temp [0]);
	return result;
}

string Manager::className()
{
	return "Manager";
}

