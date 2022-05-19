#pragma once
#include"IConverter.h"
class HourlyEmployeeUIConverter : public IConverter
{
public:
	string convert(shared_ptr<void> type);
};

