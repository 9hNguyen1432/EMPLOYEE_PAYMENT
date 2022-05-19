#include "DailyEmployee.h"

DailyEmployee::DailyEmployee(string name, int pricePerDay, int numOfDay)
{
	_name = name;
	_pricePerDay = pricePerDay;
	_numOfDay = numOfDay;
}

int DailyEmployee::getPayment()
{
	int result;
	result = _pricePerDay * _numOfDay;
	return result;
}

shared_ptr<Employee> DailyEmployee::create(tuple<string, int*> data)
{
	int* temp = get<1>(data);
	shared_ptr<Employee> result = make_shared<DailyEmployee>(get<0>(data),temp[0], temp[1]);
	return result;
}

string DailyEmployee::className()
{
	return "DailyEmployee";
}


