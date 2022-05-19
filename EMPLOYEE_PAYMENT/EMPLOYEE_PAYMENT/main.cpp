#include "Employee.h"
#include "EmployeeFactory.h"
#include "Ulti.h"
#include<sstream>
#include<map>

#include "DailyEmployeeUIConverter.h"
#include "HourlyEmployeeUIConverter.h"
#include "ProductEmployeeUIConverter.h"
#include "ManagerUIConverter.h"

struct {
	vector <shared_ptr<Employee>> ListEmployees;
}state;

shared_ptr<EmployeeFactory> EmployeeFactory::_instance = NULL;

const string fileName = "November2021.txt";

void main() {
	 
	vector <tuple<string, string, int*>> dataFromFile = getDataFromFile(fileName);

	// doc du lieu tu file:
	// dataFromFile = ................;


	for (int i = 0; i < dataFromFile.size(); i++) {
		shared_ptr<Employee> temp =
			EmployeeFactory::instance()->create(dataFromFile[i]);
		state.ListEmployees.push_back(temp);
	}

	//Cau hinh
	map<string, shared_ptr<IConverter>> ui;
	ui[(new DailyEmployee())->className()] = make_shared<DailyEmployeeUIConverter>();
	ui[(new HourlyEmployee())->className()] = make_shared<HourlyEmployeeUIConverter>();
	ui[(new ProductEmployee())->className()] = make_shared<ProductEmployeeUIConverter>();
	ui[(new Manager())->className()] = make_shared<ManagerUIConverter>();

	
	for (int i = 0; i < state.ListEmployees.size(); i++) {
		auto convert = ui[state.ListEmployees[i]->className()];
		cout << convert->convert(shared_ptr<void>(state.ListEmployees[i])) << endl;
	}

	return;
}