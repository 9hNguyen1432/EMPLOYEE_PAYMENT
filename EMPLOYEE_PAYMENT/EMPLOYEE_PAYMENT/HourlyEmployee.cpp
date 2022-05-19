#include "HourlyEmployee.h"
HourlyEmployee::HourlyEmployee(string name, int pricePerHour, int numOfHour)
{
	_name = name;
	_pricePerHour = pricePerHour;
	_numOfHour = numOfHour;
}

int HourlyEmployee::getPayment()
{
	int result;
	result = _pricePerHour * _numOfHour;
	return result;
}

shared_ptr<Employee> HourlyEmployee::create(tuple<string, int*> data)
{
	int* temp = get<1>(data);
	shared_ptr<Employee> result = make_shared<HourlyEmployee>(get<0>(data), temp[0], temp[1]);
	return result;
}

string HourlyEmployee::className()
{
	return "HourlyEmployee";
}