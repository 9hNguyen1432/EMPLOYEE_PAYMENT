#include "HourlyEmployeeUIConverter.h"
#include"HourlyEmployee.h"

string HourlyEmployeeUIConverter::convert(shared_ptr<void> type) {
	shared_ptr<HourlyEmployee> employee = shared_ptr<HourlyEmployee>(type, reinterpret_cast<HourlyEmployee*>(type.get()));

	stringstream ss;
	ss << employee->className() << ": ";
	ss << employee->getName() << "\n\t";
	ss << "HourlyPayment=" << employee->getPricePerHour() << "$; ";
	ss << "TotalHours=" << employee->getNumOfHour();
	ss << "\nTotalPayment: " << employee->getPayment() << "$; ";

	string result = ss.str();
	return result;
}