#include "DailyEmployeeUIConverter.h"
#include"DailyEmployee.h"

string DailyEmployeeUIConverter::convert(shared_ptr<void> type) {
	shared_ptr<DailyEmployee> employee = shared_ptr<DailyEmployee>(type,reinterpret_cast<DailyEmployee*>(type.get()));

	stringstream ss;
	ss << employee->className() << ": ";
	ss << employee->getName() << "\n\t";
	ss << "DailyPayment=" << employee->getPricePerDay() << "$; ";
	ss << "TotalDays=" << employee->getNumOfDay();
	ss << "\nTotalPayment: " << employee->getPayment() << "$; ";

	string result = ss.str();
	return result;
}