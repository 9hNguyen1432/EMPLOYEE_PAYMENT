#include "ManagerUIConverter.h"
#include"Manager.h"

string ManagerUIConverter::convert(shared_ptr<void> type) {
	shared_ptr<Manager> employee = shared_ptr<Manager>(type, reinterpret_cast<Manager*>(type.get()));

	stringstream ss;
	ss << employee->className() << ": ";
	ss << employee->getName() << "\n\t";
	ss << "FixedPayment=" << employee->getFixedPayment() << "$; ";
	ss << "TotalEmployees=" << employee->getNumOfStaff() << "; ";
	ss << "PaymentPerEmployee=" << employee->getPricePerStaff() << "$";
	ss << "\nTotalPayment: " << employee->getPayment() << "$; ";

	string result = ss.str();
	return result;
}