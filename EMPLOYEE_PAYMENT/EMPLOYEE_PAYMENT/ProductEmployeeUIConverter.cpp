#include "ProductEmployeeUIConverter.h"
#include"ProductEmployee.h"

string ProductEmployeeUIConverter::convert(shared_ptr<void> type) {
	shared_ptr<ProductEmployee> employee = shared_ptr<ProductEmployee>(type, reinterpret_cast<ProductEmployee*>(type.get()));

	stringstream ss;
	ss << employee->className() << ": ";
	ss << employee->getName() << "\n\t";
	ss << "PaymentPerProduct=" << employee->getPricePerProduct() << "$; ";
	ss << "TotalProducts=" << employee->getNumOfProduct();
	ss << "\nTotalPayment: " << employee->getPayment() << "$; ";

	string result = ss.str();
	return result;
}