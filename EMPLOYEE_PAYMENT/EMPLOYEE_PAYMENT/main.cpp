#include "Employee.h"
#include "EmployeeFactory.h"

struct {
	vector <shared_ptr<Employee>> ListEmployees;
}state;

shared_ptr<EmployeeFactory> EmployeeFactory::_instance = NULL;

void main() {
	// 
	vector <tuple<string, int*>> dataFromFile;

	// doc du lieu tu file:
	// dataFromFile = ................;


	for (int i = 0; i < dataFromFile.size(); i++) {
		shared_ptr<Employee> temp = 
		EmployeeFactory::instance()->create(dataFromFile[i]);
		state.ListEmployees.push_back(temp);
	}

	return;
}