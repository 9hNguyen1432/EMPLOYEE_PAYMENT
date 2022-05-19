#include"EmployeeFactory.h"
#include<sstream>


EmployeeFactory::EmployeeFactory() {
	shared_ptr<DailyEmployee> dailyEmployee = make_shared<DailyEmployee>();
	shared_ptr<HourlyEmployee> hourlyEmployee = make_shared<HourlyEmployee>();
	shared_ptr<ProductEmployee> productEmployee = make_shared<ProductEmployee>();
	shared_ptr<Manager> manager = make_shared<Manager>();

	_prototypes.insert({ dailyEmployee->className(),dailyEmployee });
	_prototypes.insert({ hourlyEmployee->className(),hourlyEmployee });
	_prototypes.insert({ productEmployee->className(),productEmployee });
	_prototypes.insert({ manager->className(),manager });
}
shared_ptr<Employee> EmployeeFactory::getPrototype(string className) {
	auto result = _prototypes[className];
	return result;
}


shared_ptr<EmployeeFactory> EmployeeFactory::instance() {
	if (_instance == NULL) {
		_instance = shared_ptr<EmployeeFactory>(new EmployeeFactory());
	}
	return _instance;
}

int EmployeeFactory::supportedTypesCount() {
	return _prototypes.size();
}

shared_ptr<Employee> EmployeeFactory::create(tuple<string, string, int*> data) {
	shared_ptr<Employee> result;

	for (int j = 0; j < _prototypes.size(); j++) {
		auto converter = _prototypes[get<0>(data)];
		tuple<string, int*> detail = make_tuple(get<1>(data), get<2>(data));

		result = converter->create(detail);
		return result;
	}
};
