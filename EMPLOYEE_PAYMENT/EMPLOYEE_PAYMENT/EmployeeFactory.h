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
	EmployeeFactory() {
		_prototypes.insert({ (new DailyEmployee())->className(),make_shared<DailyEmployee>() });
		_prototypes.insert({ (new HourlyEmployee())->className(),make_shared<HourlyEmployee>() });
		_prototypes.insert({ (new ProductEmployee())->className(),make_shared<ProductEmployee>() });
		_prototypes.insert({ (new Manager())->className(),make_shared<Manager>() });
	}
public:
	shared_ptr<Employee> getPrototype(string className) {
		auto result = _prototypes[className];
		return result;
	}
public:
	static shared_ptr<EmployeeFactory> instance() {
		if (_instance == NULL) {
			_instance = shared_ptr<EmployeeFactory>(new EmployeeFactory());
		}
		return _instance;
	}

	int supportedTypesCount() {
		return _prototypes.size();
	}

	shared_ptr<Employee> create(tuple<string, string, int*> data);
};
