#include "DailyEmployee.h"

DailyEmployee::DailyEmployee(int pricePerDay, int numOfDay)
{
	_pricePerDay = pricePerDay;
	_numOfDay = numOfDay;
}

int DailyEmployee::getPayment()
{
	int result;
	result = _pricePerDay * _numOfDay;
	return result;
}

shared_ptr<Employee> DailyEmployee::generate(void* argm)
{
	int* temp = (int*) argm;
	shared_ptr<Employee> result = make_shared<DailyEmployee>(temp[0], temp[1]);
	return result;
}

string DailyEmployee::className()
{
	return "DailyEmployee";
}


