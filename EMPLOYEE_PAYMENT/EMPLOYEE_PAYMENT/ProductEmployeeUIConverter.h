#pragma once
#include"IConverter.h"
class ProductEmployeeUIConverter : public IConverter
{
public:
	string convert(shared_ptr<void> type);
};

