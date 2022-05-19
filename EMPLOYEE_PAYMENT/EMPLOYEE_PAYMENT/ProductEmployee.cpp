#include "ProductEmployee.h"

ProductEmployee::ProductEmployee(string name, int pricePerProduct, int numOfProduct)
{
	_name = name;
	_pricePerProduct = pricePerProduct;
	_numOfProduct = numOfProduct;
}

int ProductEmployee::getPayment()
{
	int result;
	result = _pricePerProduct * _numOfProduct;
	return result;
}

shared_ptr<Employee> ProductEmployee::create(tuple<string, int*> data)
{
	int* temp = get<1>(data);
	shared_ptr<Employee> result = make_shared<ProductEmployee>(get<0>(data), temp[0], temp[1]);
	return result;
}

string ProductEmployee::className()
{
	return "ProductEmployee";
}
