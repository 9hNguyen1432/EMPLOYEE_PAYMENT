#pragma once
#include"Employee.h"

class Information
{
public:
	static tuple<bool, int, string, tuple<string, string, int*>> parse(string data);
};

