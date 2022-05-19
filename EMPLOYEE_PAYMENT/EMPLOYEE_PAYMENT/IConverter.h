#pragma once
#include<iostream>

using namespace std;

class IConverter
{
public:
	virtual string convert(shared_ptr<void> type) = 0;
};

