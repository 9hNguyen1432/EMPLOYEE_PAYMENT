#pragma once

#include "Employee.h"
#include "DailyEmployee.h"
#include "HourlyEmployee.h"
#include "ProductEmployee.h"
#include "Manager.h"
#include <vector>
#include <map>
class EmployeeFactory {
private:
	static shared_ptr<EmployeeFactory> _instance;
	vector<shared_ptr<Employee>> _prototypes;
	EmployeeFactory() {
		_prototypes.push_back(make_shared<DailyEmployee>());
		_prototypes.push_back(make_shared<HourlyEmployee>());
		_prototypes.push_back(make_shared<ProductEmployee>());
		_prototypes.push_back(make_shared<Manager>());
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

	shared_ptr<Employee> create(tuple<string, int*> data) {
		shared_ptr<Employee> result;

		for (int j = 0; j < _prototypes.size(); j++) {
			if (get<0>(data) == _prototypes[j]->className()) {
				result = _prototypes[j]->generate(get<1>(data));
				return result;
			}
		}
	};
};
