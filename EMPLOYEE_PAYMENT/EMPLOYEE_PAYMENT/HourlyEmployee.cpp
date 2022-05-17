#include "HourlyEmployee.h"
HourlyEmployee::HourlyEmployee(int pricePerHour, int numOfHour)
{
	_pricePerHour = pricePerHour;
	_numOfHour = numOfHour;
}

int HourlyEmployee::getPayment()
{
	int result;
	result = _pricePerHour * _numOfHour;
	return result;
}

shared_ptr<Employee> HourlyEmployee::generate(void* argm)
{
	int* temp = (int*)argm;
	shared_ptr<Employee> result = make_shared<HourlyEmployee>(temp[0], temp[1]);
	return result;
}

string HourlyEmployee::className()
{
	return "HourlyEmployee";
}