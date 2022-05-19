#pragma once
#include <iostream>
#include <memory>
#include<tuple>
#include<sstream>
using namespace std;

class Information;

class Employee {
public:
	virtual shared_ptr<Employee> create(tuple<string,int*>) = 0;
	virtual string className() = 0;
	virtual int getPayment() = 0;
};