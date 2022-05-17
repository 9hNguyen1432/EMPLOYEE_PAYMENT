#include "Manager.h"

Manager::Manager(int fixPayment,  int numOfStaff, int price)
{
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

shared_ptr<Employee> Manager::generate(void* argm)
{
	int* temp = (int*)argm;
	shared_ptr<Employee> result = make_shared<Manager>(temp[0], temp[1], temp [0]);
	return result;
}

string Manager::className()
{
	return "Manager";
}

