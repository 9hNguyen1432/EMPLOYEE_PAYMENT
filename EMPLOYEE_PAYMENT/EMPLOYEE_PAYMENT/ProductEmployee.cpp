#include "ProductEmployee.h"

ProductEmployee::ProductEmployee(int pricePerProduct, int numOfProduct)
{
	_pricePerProduct = pricePerProduct;
	_numOfProduct = numOfProduct;
}

int ProductEmployee::getPayment()
{
	int result;
	result = _pricePerProduct * _numOfProduct;
	return result;
}

shared_ptr<Employee> ProductEmployee::generate(void* argm)
{
	int* temp = (int*)argm;
	shared_ptr<Employee> result = make_shared<ProductEmployee>(temp[0], temp[1]);
	return result;
}

string ProductEmployee::className()
{
	return "ProductEmployee";
}
