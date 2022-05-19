#pragma once

#include "Employee.h"
#include "DailyEmployee.h"
#include "HourlyEmployee.h"
#include "ProductEmployee.h"
#include "Manager.h"
#include <vector>
#include <map>
#include<tuple>

class EmployeeFactory {
private:
	static shared_ptr<EmployeeFactory> _instance;
	/*vector<shared_ptr<Employee>> _prototypes;
	EmployeeFactory() {
		_prototypes.push_back(make_shared<DailyEmployee>());
		_prototypes.push_back(make_shared<HourlyEmployee>());
		_prototypes.push_back(make_shared<ProductEmployee>());
		_prototypes.push_back(make_shared<Manager>());
	}*/
	map<string,shared_ptr<Employee>> _prototypes;
	EmployeeFactory();
public:
	shared_ptr<Employee> getPrototype(string className);
public:
	static shared_ptr<EmployeeFactory> instance();

	int supportedTypesCount();

	shared_ptr<Employee> create(tuple<string, string, int*> data);
};
