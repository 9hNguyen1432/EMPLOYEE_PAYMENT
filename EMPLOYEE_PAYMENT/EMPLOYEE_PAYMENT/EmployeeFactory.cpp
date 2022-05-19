#include"EmployeeFactory.h"
#include<sstream>

shared_ptr<Employee> EmployeeFactory::create(tuple<string, string, int*> data) {
	shared_ptr<Employee> result;

	for (int j = 0; j < _prototypes.size(); j++) {
		auto converter = _prototypes[get<0>(data)];
		tuple<string, int*> detail = make_tuple(get<1>(data), get<2>(data));

		result = converter->create(detail);
		return result;
	}
};
