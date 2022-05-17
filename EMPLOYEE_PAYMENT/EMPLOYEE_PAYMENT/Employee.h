#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Employee {
public:
	virtual shared_ptr<Employee> generate(void* argm) = 0;
	virtual string className() = 0;
};